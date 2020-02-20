#ifndef ANALYZE
#define ANALYZE

#include <iostream>
#include<string>
#include<vector>
#include <fstream>
#include "Date.h"
#include "Task.h"


std::vector<Task> get_tasks(std::string const chemin) ;
std::string Task_to_string (Task tache) ;
void enregistrer(std::vector<Task> listeTaches,std::string const chemin) ;

#endif