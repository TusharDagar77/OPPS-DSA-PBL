#include "SmartCity.h"
#include <cstdlib>
SmartCity::SmartCity():head(NULL),locationCount(8){
for(int i=0;i<MAX_LOCATIONS;i++)for(int j=0;j<MAX_LOCATIONS;j++)roads[i][j]={0,1,1,false};
seedLocations();seedRoads();seedServices();
}
SmartCity::~SmartCity(){Service* p=head;while(p){Service* t=p;p=p->next;free(t);}}
