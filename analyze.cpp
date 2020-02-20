#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Task.h"
#include "Date.h"


std::vector<Task> get_tasks(std::string const chemin)
{

    //on ouvre le fichier dans lequel on a stocké les taches à la dernière sauvegarde
    std::ifstream aLire;
    aLire.open(chemin.c_str());
    // on crée un vecteur qui contiendra toutes les taches
    std::vector<Task> liste_Taches(0);

    if (aLire)
    {
        std::string enregistrement;
        bool fini;
        fini = !(std::getline(aLire, enregistrement)); //pas sûre de mon code
        while (!fini)
        {
            std::vector<std::string> attributs(0);
            char c;
            std::string mot = "";
            for (unsigned i = 0; i < enregistrement.size(); i++)
            {
                c = enregistrement[i];
                // '/' marque le changement d'attribut, on le stocke alors dans le vecteur, sinon on engrange les lettres
                if (c == '/')
                {
                    attributs.push_back(mot);
                    mot = "";
                }
                else
                {
                    mot.push_back(c);
                }
            }
            // à ce moment, la ligne a été entièrement lue, tous les attibuts sont stockés
            Task tache = Task();
            tache.set_id(string_to_int(attributs[0]));
            tache.set_title(attributs[1]);
            tache.set_description(attributs[2]);
            tache.set_creation(string_to_Date(attributs[3]));
            tache.set_closure(string_to_Date(attributs[4]));
            tache.set_dueFor(string_to_Date(attributs[5]));
            tache.set_status(attributs[6]);
            tache.set_advancement(string_to_int(attributs[7]));
            tache.set_priority(attributs[8]);
            tache.set_comments(attributs[9]);
            liste_Taches.push_back(tache);
            for (int i = 10; i < attributs.size(); i++)
            {
                tache.add_subTask(string_to_int(attributs[i]));
            }
            fini = !(std::getline(aLire, enregistrement));
        }
        // à ce moment là, le fichier entier a été lu
    }
    else
    {
        std::cout << "Erreur, le fichier n'est pas ouvert";
    }

    return liste_Taches;
}

std::string Task_to_string (Task tache)
{
    std::string res {""} ;
    res = std::to_string(tache.get_id()) +"/" + tache.get_title() +"/" + tache.get_description() +"/" + tache.get_creation().Date_to_string()
    +"/" + tache.get_closure().Date_to_string() + tache.get_dueFor().Date_to_string() +"/" + tache.get_status() +"/" + 
    std::to_string(tache.get_advancement()) +"/" + tache.get_priority() +"/" + tache.get_comments()
    +"/" + subTask_to_string(tache.get_subTasks()) +"/&"  ;
    return res ;
    
}

void enregistrer(std::vector<Task> listeTaches,std::string const chemin) 
{

    std::ofstream enEcriture (chemin.c_str() , std::ios::app) ;
    if (enEcriture)
    {
        for (long unsigned int i {0} ; i< listeTaches.size() ; i++)
        {
            enEcriture<< Task_to_string(listeTaches[i]) << std::endl ;
        }
        enEcriture.close() ;
    }
    else
    {
       std::cout<< "Erreur, le fichier n'est pas ouvert"  << std::endl ;
    }
} 