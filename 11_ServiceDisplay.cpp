#include "SmartCity.h"
#include <iostream>
void SmartCity::displayServices() const{
Service* p=head;if(!p){std::cout<<"No services available.\n";return;}
std::cout<<"\n--- CITY SERVICES ---\n";
while(p){std::cout<<"ID: "<<p->id<<" | Name: "<<p->name<<" | Category: "<<p->category<<" | Area: "<<p->area<<" | Location node: "<<p->locationNode<<"\n";p=p->next;}
}
