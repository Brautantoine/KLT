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

#ifndef DIC_CONTENEUR_HPP
#define DIC_CONTENEUR_HPP

#include <iostream>
#include <fstream>
#include "json_conteneur.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include "json.hpp"


class dic_conteneur : public json_conteneur
{
  public:
    //dic_conteneur();                                                            // Needed for pre init, but not usable please use dic_conteneur(const dic_conteneur& that);
    dic_conteneur(const dic_conteneur& that);
    void operator=(const dic_conteneur& that);
    dic_conteneur(std::string n_file,int n_nb_words);
    ~dic_conteneur();



     void load_from_file();
     void validate();
     void display(); //debug

     void draw_random_word();
     std::string get_current();
     std::string get_current_romaj();
     std::string get_current_detail();
     bool compare_word(std::string input);

     static int nb_dic;

  protected:
     std::string file_name;
     int nb_words;

     std::vector<int>         id;
     std::vector<std::string> kana;
     std::vector<std::string> romaji;
     std::vector<int>         level;
     std::vector<std::string> detail;

   private:
     inline void is_loaded();

     int current_word;
     bool loaded;
     bool validating;

     int dic_number;



};


#endif //MANIFEST_CONETENEUR_HPP
