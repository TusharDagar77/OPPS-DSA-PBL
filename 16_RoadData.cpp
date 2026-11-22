#include "SmartCity.h"
void SmartCity::addRoad(int a,int b,int km){
if(a<0||b<0||a>=MAX_LOCATIONS||b>=MAX_LOCATIONS||a==b||km<=0)return;
roads[a][b].distance=km;roads[b][a].distance=km;
}
