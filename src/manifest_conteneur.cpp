/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018 - 2019 Antoine Braut                                        *
*                                                                                       *
*    This program is free software: you can redistribute it and/or modify               *
*    it under the terms of the GNU General Public License as published by               *
*    the Free Software Foundation, either version 3 of the License, or                  *
*    (at your option) any later version.                                                *
*                                                                                       *
*    This program is distributed in the hope that it will be useful,                    *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                     *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      *
*    GNU General Public License for more details.                                       *
*                                                                                       *
*    You should have received a copy of the GNU General Public License                  *
*    along with this program. If not, see <https://www.gnu.org/licenses/>.              *
*                                                                                       *
*    Contact : Antoine.braut@gmail.com                                                  *
*                                                                                       *
****************************************************************************************/

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
    {
      std::cout << "Manifest loaded" << std::endl;
      std::cout << "\nEntries founded :" << std::endl;
      for(int i = 0;i<parser["nb_files"];i++)
      {
        std::string buff("file"+std::to_string(i));
        std::cout <<"\t" << parser[buff]["name"] << std::endl;
      }
      std::cout << std::endl;
    }

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

    std::string name_with_path_type;
    if(!file_name.compare("ressources/manifest.json"))
      name_with_path_type = "relative_name";
    else
      name_with_path_type = "absolute_name";

    for(int k=0;k<parser["nb_files"];k++)
    {
      std::string buff("file"+std::to_string(k));

      vector_of_dic.emplace_back(parser[buff][name_with_path_type],parser[buff]["nb_words"]);
      vector_of_dic.at(k).load_from_file();
    }
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
      throw std::runtime_error("Error while loading : "+file_name+". Maybe you can verify your json syntax.\n");
    std::vector<dic_conteneur> v;

    std::string name_with_path_type;
    if(!file_name.compare("ressources/manifest.json"))
      name_with_path_type = "relative_name";
    else
      name_with_path_type = "absolute_name";

    for(int k=0;k<parser["nb_files"];k++)
    {
      std::string buff("file"+std::to_string(k));

      v.emplace_back(parser[buff][name_with_path_type],parser[buff]["nb_words"]);
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

std::vector<std::string> manifest_conteneur::get_names()
{
  std::vector <std::string> dic_buffer;
  for(int i = 0;i<parser["nb_files"];i++)
  {
    std::string buff("file"+std::to_string(i));
    dic_buffer.emplace_back(parser[buff]["name"]);
  }
  return dic_buffer;
}
