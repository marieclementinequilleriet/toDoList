#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Task.h"
#include "Date.h"

/*
std::vector<Task> get_tasks(std::string const chemin)
{

    //on ouvre le fichier dans lequel on a stocké les taches à la dernière sauvegarde
    std::ifstream aLire;
    aLire.open(chemin.c_str());
    std::vector<Task> liste_Taches(0);

    if (aLire)
    {
        std::cout << "Le fichier est ouvert" << std::endl;

        /*on initialise le vecteur de taches dans lequel toutes les taches seront enregistrées, 
    accessibles via leur identifiant (=indice dans le vecteur) */

/*        bool fini = false; //pour savoir si on afini de lire le fichier

        char c('a');
        //on lit le premier caractère du fichier
        aLire.get(c);
        ;
        std::cout << "premier car lu" << std::endl;

        //la tache est composée d'attributs séparés par des / (et & pour marquer le début du vecteur de tâches)
        //les taches sont séparées par des §
        //la fin du fichier est marquée par un ¤
        while (not fini)

        {
            //11 attributs de la classe Task, dont les dates qui sont en 3 morceaux, moins le cas des sousTeches qui sont lues ensuite
            std::string attributs[16];
            for (int j(0); j < 16; j++)
            {
                attributs[j] = "";
            }
            int i(0);
            std::cout << "vecteur attributs créé" << std::endl;
            while (i < 16)
            //gérer le fait qu'on puisse avoir des '&' dans commentaire et description
            {
                if (c == '/')
                {
                    std::cout << attributs[i] << std::endl;
                    i++;
                }
                {
                    attributs[i].push_back(c);
                }
                aLire.get(c);
            }

            //éliminer le i de la mémoire

            //on crée le vecteur de sous-taches

            std::vector<int> ssTache(0);
            std::string identifiant("");
            aLire.get(c);
            while (c != '&' && c != '~')
            //gérer le fait qu'on puisse avoir des '§' dans commentaire et description
            {
                if (c == '/')
                {
                    ssTache.push_back(atoi(identifiant.c_str()));
                }
                {
                    identifiant.push_back(c);
                }
                aLire.get(c);
            }

            /*On ajoute à la liste des taches de l'utilisateur la tâche ainsi définie, sa place dans le vecteur des taches 
        est son identifiant*/

/*    liste_Taches.push_back(Task(atoi(attributs[0].c_str()), attributs[1], attributs[2], Date(atoi(attributs[3].c_str()), atoi(attributs[4].c_str()), atoi(attributs[5].c_str())), Date(atoi(attributs[6].c_str()), atoi(attributs[7].c_str()), atoi(attributs[8].c_str())),
                                        Date(atoi(attributs[9].c_str()), atoi(attributs[10].c_str()), atoi(attributs[11].c_str())), attributs[12], atoi(attributs[13].c_str()), attributs[14],
                                        attributs[15], ssTache));

            //on vérifie que le fichier n'est pas fini
            //pour l'instant, le dernier caractère lu est un § ou un ¤
            if (c = '~')
            {
                fini = true;
            }
            {
                aLire.get(c);
            }
        }
        //se débarasser du c
    }
    {
        std::cout << "Erreur, le fichier n'est pas ouvert";
    }

    return liste_Taches;
} */

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