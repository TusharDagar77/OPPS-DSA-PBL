#include "SmartCity.h"
#include <iostream>
void SmartCity::searchService() const{
std::string key;std::cout<<"Enter service name or category to search: ";std::getline(std::cin>>std::ws,key);
bool found=false;for(Service* p=head;p;p=p->next)if(std::string(p->name).find(key)!=std::string::npos||std::string(p->category).find(key)!=std::string::npos){
std::cout<<"ID: "<<p->id<<" | "<<p->name<<" | "<<p->category<<" | "<<p->area<<"\n";found=true;}
if(!found)std::cout<<"No matching service found.\n";
}
