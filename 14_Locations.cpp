#include "SmartCity.h"
#include <iostream>
void SmartCity::showLocations() const{std::cout<<"\n--- LOCATION NODES ---\n";for(int i=0;i<locationCount;i++)std::cout<<i<<". "<<locations[i]<<"\n";}
void showCityLocations(const SmartCity& city){city.showLocations();}
