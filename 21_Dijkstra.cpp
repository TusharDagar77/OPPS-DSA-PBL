#include "SmartCity.h"
#include "Config.h"
#include <iostream>
void explainDijkstra(){std::cout<<"Dijkstra selects the unvisited node with the lowest current cost.\n";}
void SmartCity::shortestRoute(){
int start,dest;showLocations();
std::cout<<"Enter starting node: ";if(!(std::cin>>start)){clearInput();return;}
std::cout<<"Enter destination node: ";if(!(std::cin>>dest)){clearInput();return;}
if(!validLocation(start)||!validLocation(dest)){std::cout<<"Invalid location number.\n";return;}
int dist[MAX_LOCATIONS],prev[MAX_LOCATIONS];bool used[MAX_LOCATIONS];
for(int i=0;i<locationCount;i++){dist[i]=INF_DISTANCE;prev[i]=-1;used[i]=false;}dist[start]=0;
for(int k=0;k<locationCount;k++){int u=-1,best=INF_DISTANCE;for(int i=0;i<locationCount;i++)if(!used[i]&&dist[i]<best){best=dist[i];u=i;}if(u==-1)break;used[u]=true;
for(int v=0;v<locationCount;v++)if(roads[u][v].distance>0&&!roads[u][v].closed&&!used[v]){int cost=weight(roads[u][v]);if(dist[u]+cost<dist[v]){dist[v]=dist[u]+cost;prev[v]=u;}}}
if(dist[dest]==INF_DISTANCE){std::cout<<"No open route found between these locations.\n";return;}
int path[MAX_LOCATIONS],n=0,cur=dest;while(cur!=-1&&n<MAX_LOCATIONS){path[n++]=cur;cur=prev[cur];}
std::cout<<"Recommended route (based on sample distance/traffic/road scores):\n";
for(int i=n-1;i>=0;i--){std::cout<<locations[path[i]];if(i)std::cout<<" -> ";}
std::cout<<"\nRoute score: "<<dist[dest]<<"\nNote: route score is a demo score, not actual kilometres or live travel time.\n";
}
