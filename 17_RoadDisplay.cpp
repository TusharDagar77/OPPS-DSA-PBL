#include "SmartCity.h"
#include <iostream>
void SmartCity::showRoads() const{
std::cout<<"\n--- ROAD CONNECTIONS ---\n";
for(int i=0;i<locationCount;i++)for(int j=i+1;j<locationCount;j++)if(roads[i][j].distance>0)
std::cout<<i<<" ("<<locations[i]<<") <-> "<<j<<" ("<<locations[j]<<"), "<<roads[i][j].distance<<" km, Traffic: "<<roads[i][j].traffic<<", Condition: "<<roads[i][j].condition<<", "<<(roads[i][j].closed?"Closed":"Open")<<"\n";
}
