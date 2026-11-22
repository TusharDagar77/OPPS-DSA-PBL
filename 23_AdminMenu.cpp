#include "SmartCity.h"
#include <iostream>
void SmartCity::cityAdminMenu(){
int choice;do{
std::cout<<"\n--- CITY ADMINISTRATION ---\n1. Add a city service\n2. Update traffic/road condition/closure\n3. Display all services\n4. Display road connections\n0. Return to main menu\nEnter your choice: ";
if(!(std::cin>>choice)){clearInput();continue;}
switch(choice){case 1:addServiceFromUser();break;case 2:updateRoad();break;case 3:displayServices();break;case 4:showRoads();break;case 0:break;default:std::cout<<"Invalid choice. Try again.\n";}
}while(choice!=0);
}
