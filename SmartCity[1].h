#ifndef SMARTCITY_H
#define SMARTCITY_H
#include <string>
#include "Types.h"
#include "Config.h"
class SmartCity{
    Service* head; std::string locations[MAX_LOCATIONS]; Road roads[MAX_LOCATIONS][MAX_LOCATIONS]; int locationCount;
public:
    SmartCity(); ~SmartCity();
    int weight(const Road&) const; bool validLocation(int) const; void clearInput();
    void addService(int,std::string,std::string,std::string,int); void addServiceFromUser();
    void displayServices() const; void searchService() const; void showLocations() const;
    void addRoad(int,int,int); void showRoads() const; void updateRoad(); void shortestRoute();
    void cityAdminMenu(); void menu(); void seedLocations(); void seedRoads(); void seedServices();
};
#endif
