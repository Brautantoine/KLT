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

#ifndef MANIFEST_CONETENEUR_HPP
#define MANIFEST_CONETENEUR_HPP

#include <iostream>
#include <fstream>
#include "json_conteneur.hpp"
#include "dic_conteneur.hpp"
#include <vector>
#include "json.hpp"

class manifest_conteneur : public json_conteneur
{
  public:
    manifest_conteneur(std::string n_file);
    ~manifest_conteneur();

     void load_from_file();
     bool validate();
     void display();

     void construct_from_manifest(std::vector<dic_conteneur>& vector_of_dic);

    std::vector<std::string> get_names();

  protected:
     //std::ifstream file; //herited from json_conteneur
     //nlohmann::json parser; //herited from json_conteneur
     std::string file_name;

  private:
    inline void is_loaded();

    bool loaded;
    bool validating;



};


#endif //MANIFEST_CONETENEUR_HPP
