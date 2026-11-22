#include "SmartCity.h"
int SmartCity::weight(const Road& r) const{return r.distance+(r.traffic-1)*3+(r.condition-1)*2;}
