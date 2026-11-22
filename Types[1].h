#ifndef TYPES_H
#define TYPES_H
struct Service{int id;char name[100];char category[50];char area[100];int locationNode;Service* next;};
struct Road{int distance;int traffic;int condition;bool closed;};
#endif
