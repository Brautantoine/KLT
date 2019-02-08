/****************************************************************************************
*    KLT : A terminal tool that help you learn kana                                     *
*    Copyright KLT (C) 2018 - 2019  Antoine Braut                                       *
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

#ifndef UTILS_HPP
#define  UTILS_HPP

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "manifest_conteneur.hpp"

namespace utils
{
    int arg_hash(std::string key);                                              // Adapted from stackoverflow : "Why the switch cannot be applied on strings"
    void show_help();
    void show_version();
    void run_validation(char **argv);
}


#endif // UTILS_HPP
