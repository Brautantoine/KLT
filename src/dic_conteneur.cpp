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

#include "dic_conteneur.hpp"

int dic_conteneur::nb_dic =0;

/*dic_conteneur::dic_conteneur()
{

}*/

dic_conteneur::dic_conteneur(const dic_conteneur& that)
{
  this->file_name = that.file_name;
  this->nb_words = that.nb_words;
  this->id = that.id;
  this->kana = that.kana;
  this->romaji = that.romaji;
  this->level = that.level;
  this->detail = that.detail;
  this->loaded = that.loaded;
  this->validating = that.validating;
  this->dic_number = that.dic_number;
  nb_dic++;
}

void dic_conteneur::operator=(const dic_conteneur& that)
{
  this->file_name = that.file_name;
  this->nb_words = that.nb_words;
  this->id = that.id;
  this->kana = that.kana;
  this->romaji = that.romaji;
  this->level = that.level;
  this->detail = that.detail;
  this->loaded = that.loaded;
  this->validating = that.validating;
  this->dic_number = that.dic_number;
  nb_dic++;
}

dic_conteneur::dic_conteneur(std::string n_file,int n_nb_words)
{
  file_name=n_file;
  nb_words=n_nb_words;
  loaded=false;
  validating=false;

  nb_dic++;
  dic_number=nb_dic;
}

dic_conteneur::~dic_conteneur()
{
  nb_dic--;
}

void dic_conteneur::load_from_file()
{
  if(validating)
    std::cout << "[" << dic_number << "] Loading dictionnary : "+file_name << std::endl;

  try
  {
    file.open(file_name, std::ifstream::in);
    if(file.fail())
      throw std::runtime_error("Error while opening "+file_name+" : No such file or directory\n");
      for(int i =0;i<nb_words;i++)
      {
        file >> parser;
        id.emplace_back(parser["id"]);
        kana.emplace_back(parser["kana"]);
        romaji.emplace_back(parser["romaji"]);
        level.emplace_back(parser["level"]);
        detail.emplace_back(parser["detail"]);
      }

      if(validating)
        std::cout << "dictionnary loaded\n\t" << id.size() << " word(s) have been found." << std::endl;
      loaded=true;
      file.close();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what();
  }


}

void dic_conteneur::display()
{
  is_loaded();
  for(unsigned int i=0;i<id.size();i++)
  {
    std::cout << "id :" << id.at(i) << std::endl
      << "is : " << kana.at(i) << std::endl
      << "wich is : " << detail.at(i) << std::endl;
  }
}

inline void dic_conteneur::is_loaded()
{
  if(!loaded)
    throw std::runtime_error("Error while trying to read the manifest : "+file_name+" not loaded\n");
}

void dic_conteneur::validate()
{
  validating=true;
  load_from_file();
  if(!loaded)
    throw std::runtime_error("Error while loading :"+file_name+". Maybe you can verify json syntax.\n");
  //validating=false uneccessary because this object will be destroyed at the end of this scope
}

void dic_conteneur::draw_random_word()
{
  static int last_word(-1);
  int nb_word(id.size());

  do {
    current_word=rand()%nb_word;
  } while(current_word==last_word);

  last_word=current_word;
}

std::string dic_conteneur::get_current()
{
  return kana.at(current_word);
}

std::string dic_conteneur::get_current_romaj()
{
  return romaji.at(current_word);
}

bool dic_conteneur::compare_word(std::string input)
{
  std::transform(input.begin(), input.end(), input.begin(), ::tolower);
  if(romaji.at(current_word).compare(input))
    return false;
  else
    return true;
}
