#include "manifest_conteneur.hpp"

manifest_conteneur::manifest_conteneur(std::string n_file)
{
  file_name=n_file;
  loaded=false;
  validating=false;
}

manifest_conteneur::~manifest_conteneur()
{

}

void manifest_conteneur::load_from_file()
{
  if(validating)
    std::cout << "Loading Manifest : "+file_name << std::endl;
  try
  {
    file.open(file_name, std::ifstream::in);
    if(file.fail())
      throw std::runtime_error("Error while opening "+file_name+" : No such file or directory\n");
    file >> parser;
    if(validating)
      std::cout << "Manifest loaded" << std::endl;
    loaded=true;
    file.close();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what();
  }

}

void manifest_conteneur::display()
{
  is_loaded();

  std::cout << "what have been found in manifest :" << std::endl;
  std::cout << "nb_files :" << parser["nb_files"] << std::endl;
  std::cout << "version :" << parser["version"] << std::endl;
  std::cout << "all : " << parser << std::endl;

}

void manifest_conteneur::construct_from_manifest(std::vector<dic_conteneur>& vector_of_dic)
{
    is_loaded();
    vector_of_dic.clear();

    for(int k=0;k<parser["nb_files"];k++)
    {
      std::string buff("file"+std::to_string(k));

      vector_of_dic.emplace_back(parser[buff]["name"],parser[buff]["nb_words"]);
      vector_of_dic.at(k).load_from_file();
    }

    std::cerr << "vect size : " << vector_of_dic.size() << std::endl;
}

inline void manifest_conteneur::is_loaded()
{
  if(!loaded)
    throw std::runtime_error("Error while trying to read the manifest : "+file_name+" not loaded\n");
}

bool manifest_conteneur::validate()
{
  bool ret(true);
  validating=true;
  try
  {
    load_from_file();
    if(!loaded)
      throw std::runtime_error("Error while loading : "+file_name+". Maybe you can verify json syntax.\n");
    std::vector<dic_conteneur> v;
    for(int k=0;k<parser["nb_files"];k++)
    {
      std::string buff("file"+std::to_string(k));

      v.emplace_back(parser[buff]["name"],parser[buff]["nb_words"]);
      v.at(k).validate();
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    ret=false;
  }
  validating=false;
  return ret;
}
