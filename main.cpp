#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "Task.h"
#include "Date.h"
#include "analyze.h"


bool demarrage()
{
    std::cout << "Bienvenue dans votre gestionnaire de tâche." <<std::endl ;
    std::cout<< "Avez-vous déjà un compte utilisateur ?" << std::endl ;
    std::cout << " Tapez O pour Oui et N pour Non" << std::endl ;
    char reponse;
    std::cin >> reponse ;
    bool utilisateur {reponse=='O'} ;
    return utilisateur ;
}

int main ()
{
    bool utilisateur ;
    std::string nom_utilisateur ;
    std::vector<Task> liste_Taches ;
    return 0;
}  


