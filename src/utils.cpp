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

#include "utils.hpp"


int utils::arg_hash(std::string key)
{
   int result;
   static const std::unordered_map<std::string,std::function<void()>> m{
       {"--help",   [&](){ result = 1; }},
       {"-h",   [&](){ result = 1; }},
       {"-v",   [&](){ result = 2; }},
       {"--version",   [&](){ result = 2; }},
   };
   static const auto end = m.end();
       auto it = m.find(key);
       if (it != end) {
           it->second();
       } else {
           result = -1;
       }
       return result;
}

void utils::show_help()
{
  std::cout << "Kana Learning Tool - version 0.6.0 (beta)\n\
A simple terminal tool using ncurses that will help you learn kana.\n\
Run the program without any arg to launch the core program.\n\
\n\
      Usage :   klt [Arg]\
\n\
                -h | --help     : show this message\n\
                -v | --version  : show version\n\n";
}

void utils::show_version()
{
  std::cout << "Kana Learning Tool - version 0.6.0 (beta)\n";
}
