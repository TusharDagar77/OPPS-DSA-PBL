#include "SmartCity.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
void SmartCity::addService(int id,std::string name,std::string category,std::string area,int node){
Service* n=(Service*)malloc(sizeof(Service));
if(!n){std::cout<<"Memory allocation failed. Service was not added.\n";return;}
n->id=id;strncpy(n->name,name.c_str(),99);n->name[99]='\0';
strncpy(n->category,category.c_str(),49);n->category[49]='\0';
strncpy(n->area,area.c_str(),99);n->area[99]='\0';n->locationNode=node;n->next=NULL;
if(!head)head=n;else{Service* p=head;while(p->next)p=p->next;p->next=n;}
}
