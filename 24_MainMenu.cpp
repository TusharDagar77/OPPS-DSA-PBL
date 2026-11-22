#include "SmartCity.h"
#include <iostream>
void SmartCity::menu(){
int choice;do{
std::cout<<"\n========================================\n SMART CITY SERVICES & ROUTE MANAGEMENT\n========================================\n1. Display all services\n2. Search service\n3. Display location nodes\n4. Display road connections\n5. Find best available route\n6. City administration (manage updates)\n0. Exit\nEnter your choice: ";
if(!(std::cin>>choice)){clearInput();std::cout<<"Please enter a number from the menu.\n";continue;}
switch(choice){case 1:displayServices();break;case 2:searchService();break;case 3:showLocations();break;case 4:showRoads();break;case 5:shortestRoute();break;case 6:cityAdminMenu();break;case 0:std::cout<<"Thank you for using the system.\n";break;default:std::cout<<"Invalid choice. Try again.\n";}
}while(choice!=0);
}
