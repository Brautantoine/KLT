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
  std::cout << "Kana Learning Tool - version 0.4 (beta-ncurses)\n\
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
  std::cout << "Kana Learning Tool - version 0.4 (beta-ncurses)\n";
}
