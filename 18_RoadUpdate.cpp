#include "SmartCity.h"
#include <iostream>
void SmartCity::updateRoad(){
int a,b,t,c,closed;showLocations();
std::cout<<"Enter first node: ";if(!(std::cin>>a)){clearInput();std::cout<<"Invalid input.\n";return;}
std::cout<<"Enter second node: ";if(!(std::cin>>b)){clearInput();std::cout<<"Invalid input.\n";return;}
if(!validLocation(a)||!validLocation(b)||a==b||roads[a][b].distance==0){std::cout<<"Invalid nodes or no direct road between them.\n";return;}
std::cout<<"Traffic (1 Low, 2 Medium, 3 High): ";if(!(std::cin>>t)){clearInput();return;}
std::cout<<"Road condition (1 Good, 2 Fair, 3 Poor): ";if(!(std::cin>>c)){clearInput();return;}
std::cout<<"Closed? (1 Yes, 0 No): ";if(!(std::cin>>closed)){clearInput();return;}
if(t<1||t>3||c<1||c>3||(closed!=0&&closed!=1)){std::cout<<"Invalid values. No changes made.\n";return;}
roads[a][b].traffic=roads[b][a].traffic=t;roads[a][b].condition=roads[b][a].condition=c;roads[a][b].closed=roads[b][a].closed=(closed==1);
std::cout<<"Road information updated.\n";
}
