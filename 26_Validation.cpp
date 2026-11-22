#include "SmartCity.h"
#include <iostream>
bool SmartCity::validLocation(int n) const{return n>=0&&n<locationCount;}
void SmartCity::clearInput(){std::cin.clear();std::cin.ignore(10000,'\n');}
