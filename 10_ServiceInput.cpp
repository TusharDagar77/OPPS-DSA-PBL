#include "SmartCity.h"
#include <iostream>
void SmartCity::addServiceFromUser(){
int id=1,node;for(Service* p=head;p;p=p->next)if(p->id>=id)id=p->id+1;
std::string name,category,area;
std::cout<<"Enter service name: ";std::getline(std::cin>>std::ws,name);
std::cout<<"Enter category (Hospital, Education, Bank, etc.): ";std::getline(std::cin,category);
std::cout<<"Enter area/location: ";std::getline(std::cin,area);showLocations();
std::cout<<"Enter matching location node number: ";
if(!(std::cin>>node)){clearInput();std::cout<<"Invalid input. Service was not added.\n";return;}
if(!validLocation(node)){std::cout<<"Invalid location node. Service was not added.\n";return;}
addService(id,name,category,area,node);std::cout<<"Service added successfully with ID "<<id<<".\n";
}
