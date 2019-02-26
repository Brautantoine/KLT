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
    dic_conteneur(const dic_conteneur& that);
    dic_conteneur(std::string n_file,int n_nb_words);
    ~dic_conteneur();

     void load_from_file();
     void validate();
     void display(); //debug

     void draw_random_word();
     std::string get_current();
     std::string get_current_romaj();
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
