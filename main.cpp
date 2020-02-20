#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "Task.h"
#include "Date.h"
#include "analyze.h"


/*void afficher_tout()
{

}

Task* demarrer ()
{

}

void save()
{

} */

int main ()
{
    std::vector<Task> listeTaches (get_tasks("utilisateur1.txt") ) ;
    listeTaches[0].print_task() ;
    return 0 ;
} 
