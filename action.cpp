#include "action.h"


bool deja_utilisateur()
{
    std::cout << "Bienvenue dans votre gestionnaire de tâche." <<std::endl ;
    std::cout<< "Avez-vous déjà un compte utilisateur ?" << std::endl ;
    std::cout << " Tapez O pour Oui et N pour Non" << std::endl ;
    char reponse;
    std::cin >> reponse ;
    bool utilisateur {reponse=='O'} ;
    return utilisateur ;
}

std::string fichier(bool dej_util)
{
    std::string nom_utilisateur ;
    if (dej_util)
    {
        std:: cout << "Entrez votre nom d'utilisateur" << std::endl ;
    }
    else
    {
        std::cout<< " Créez votre nom d'utilisateur (sans espaces)" << std::endl ;
    }
    std::cin >> nom_utilisateur;
    nom_utilisateur += ".txt" ;
    return nom_utilisateur ;
    
}

std::vector<Task> mes_Taches (bool dej_util , std::string fichier)
{  
    std::vector<Task> liste_Taches(0) ;
    if (dej_util)
    {
        liste_Taches = get_tasks(fichier) ; 
    }
    return liste_Taches ;
}

char actions_standards()
{
    std::cout << "Pour créer une tâche, tapez C" << std::endl ;
    std::cout << "Pour modifier une tâche, tapez M" << std::endl ;
    std::cout << "Pour afficher toutes les tâches, tapez A" << std::endl ;
    std::cout << "Pour quitter le gestionnaire de tâches, tapez Q" << std::endl;
    char res;
    std::cin >> res ; 
    return res ;
}

void afficher_tout(std::vector<Task> liste_Taches) 
{
    for (long unsigned int i = 0 ; i< liste_Taches.size(); i++)
    {
        std::cout<< "n°" << liste_Taches[i].get_id() << "     " << liste_Taches[i].get_title <<"       "<< liste_Taches[i].get_status << std::endl ;
    }
}

void modifier_tache(std::vector<Task> liste_Taches)
{
    std::cout << "Connaissez-vous l'identifiant de la tache à modifier ?  (O/N)" << std::endl ;
    bool connu ;
    std::cin >> connu ;
    if (connu == 'N') 
    {
        afficher_tout(liste_Taches) ;
    }
    std::cout << "Entrez le numéro de la tâche à modifier" << std::endl ;
    int a_modifier ;
    std::cin >> a_modifier ;
    liste_Taches[a_modifier].print_task() ;
    std::cout << "Pour clore la tache, tapez 0" << std::endl ;
    std::cout<< "Pour modifier, un attribut tapez le numéro correspondant :" << std:: endl ;
    std::cout<< "2          Description" << std:: endl ;
    std::cout<< "3          Date de création" << std:: endl ;
    std::cout<< "4          Date de fin" << std:: endl ;
    std::cout<< "5          Date limite" << std:: endl ;
    std::cout<< "6          Statut" << std:: endl ;
    std::cout<< "7          Avancement" << std:: endl ;
    std::cout<< "8          Priorité" << std:: endl ;
    std::cout<< "9          Commentaire" << std:: endl ;
    std::cout <<"10         Sous taches" << std::endl ;
    int nombre ;
    std::cin >> nombre ;
    switch (nombre)
    {
        case 0:
            liste_Taches[a_modifier].end_task() ;
            break;
        case 1 :
            {std::cout << "Entrez votre nouveau titre" << std::endl ;
            std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" ;
            std::string attribut ;
            std::cin.ignore() ;
            std::getline(std::cin, attribut ) ;
            liste_Taches[a_modifier].set_title(attribut) ; }
            break ;
        case 2 :
            {std::cout << "Entrez votre nouvelle description" << std::endl ;
            std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" ;
            std::string attribut ;
            std::getline(std::cin, attribut ) ;
            liste_Taches[a_modifier].set_description(attribut) ; }
            break ;
        case 3 :
            {std::cout << "Entrez votre nouvelle date de création" << std::endl ;
            Date attribut = saisir_date() ;
            liste_Taches[a_modifier].set_creation(attribut) ; }
            break ;
        case 4 :
            {std::cout << "Entrez votre nouvelle date de fin" << std::endl ;
            Date attribut = saisir_date() ;
            liste_Taches[a_modifier].set_closure(attribut) ; }
            break ;
        case 5 :
            {std::cout << "Entrez votre nouvelle date limite" << std::endl ;
            Date attribut = saisir_date() ;
            liste_Taches[a_modifier].set_closure(attribut) ; }
            break ;
        case 6 :
            {std::cout << "Entrez le statut actuel de la tâche" << std::endl ;
            std::cout << " Pas commencé / En cours / Terminé" << std::endl ;
            std::string attribut ;
            std::cin.ignore() ;
            std::getline(std::cin, attribut ) ;
            liste_Taches[a_modifier].set_status(attribut) ; }
            break ;
        case 7 :
            {std::cout << "Entrez l'avancement actuel de la tâche (en %)" << std::endl ;
            int attribut ;
            std::cin >> attribut ;
            liste_Taches[a_modifier].set_advancement(attribut) ; }
            break ;
        case 8 :
            {std::cout << "Entrez l'état de priorité de la tâche " << std::endl ;
            std::cout << "Lointain / Normal / Urgent" << std::endl ;
            std::string attribut ;
            std::cin >> attribut ;
            liste_Taches[a_modifier].set_priority(attribut) ; }
            break ;
        case 9 :
            {std::cout << "Entrez vos nouveaux commentaires" << std::endl ;
            std::cout << "Prière de ne pas utiliser le symbole / dans votre texte" ;
            std::string attribut ;
            std::cin.ignore() ;
            std::getline(std::cin ,attribut ) ;
            liste_Taches[a_modifier].set_comments(attribut) ; }
            break ;
        
        case 10 :
            liste_Taches[a_modifier].print_subTasks() ;
            std::cout << "Pour afficher" ;
            break ;
        
    default:
        std::cout << "Erreur : le sybole entré n'est pas reconnu" << std::endl ;
        modifier_tache(liste_Taches) ;
        break;
    }

}