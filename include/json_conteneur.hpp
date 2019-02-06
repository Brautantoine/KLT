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
