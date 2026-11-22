#include "SmartCity.h"
void SmartCity::seedLocations(){
locations[0]="AIIMS / Ansari Nagar";locations[1]="Safdarjung Hospital";locations[2]="IIT Delhi / Hauz Khas";locations[3]="Delhi University / North Campus";
locations[4]="New Delhi Railway Station";locations[5]="Kashmere Gate ISBT";locations[6]="Connaught Place";locations[7]="Saket / Select CITYWALK";
}
void SmartCity::seedRoads(){
addRoad(0,1,4);addRoad(0,2,8);addRoad(1,7,7);addRoad(2,3,12);addRoad(2,7,6);addRoad(3,6,9);addRoad(4,6,3);addRoad(4,5,6);addRoad(5,6,5);addRoad(6,7,11);
}
