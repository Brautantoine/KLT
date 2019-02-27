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

#ifndef JSON_CONTENEUR_HPP
#define JSON_CONTENEUR_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "json.hpp"

class json_conteneur
{
  public:
    json_conteneur();
    virtual ~json_conteneur();

    virtual void load_from_file() =0;
    virtual void display() =0;

  protected:
    std::ifstream file;
    nlohmann::json parser;

};


#endif //JSON_CONTENEUR_HPP
