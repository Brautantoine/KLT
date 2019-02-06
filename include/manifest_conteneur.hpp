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
