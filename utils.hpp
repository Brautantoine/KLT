#ifndef UTILS_HPP
#define  UTILS_HPP

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace utils
{
    int arg_hash(std::string key);                                              // Adapted from stackoverflow : "Why the switch cannot be applied on strings"
    void show_help();
    void show_version();
}


#endif // UTILS_HPP
