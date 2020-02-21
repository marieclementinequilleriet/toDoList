#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "Task.h"
#include "Date.h"
#include "analyze.h"
#include "action.h"


int main ()
{
    bool utilisateur ;
    std::string chemin ;
    std::vector<Task> liste_Taches ;
    utilisateur = deja_utilisateur() ;
    chemin = fichier(utilisateur) ;
    liste_Taches = mes_Taches(utilisateur,chemin) ;
    char action = 'D';
    do
    {
        action = actions_standards() ;
        switch (action)
        {
        case 'C':
            /* code */
            break;
        case 'M' :
            modifier_tache(liste_Taches) ;
            break;
        case 'A' :
            afficher_tout(liste_Taches) ;
            break ;
        case 'Q' :
            return 0;
            break;
        
        default:
            std::cout << "Cette instruction n'existe pas" ;
            break;
        }
    }
    while (action != 'Q') ;
    return 0;
}  


