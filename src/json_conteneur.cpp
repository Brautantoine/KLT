#include "json_conteneur.hpp"

json_conteneur::json_conteneur()
{

}

json_conteneur::~json_conteneur()
{
  file.close();
}

void json_conteneur::load_from_file()
{
  std::cout << "Mother class :: nothing to load";
}

void json_conteneur::display() 
{
  std::cout << "Mother class :: nothing to display\n";
}
