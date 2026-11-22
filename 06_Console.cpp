#include "Console.h"
#include <cstdio>
#ifdef _WIN32
#include <windows.h>
#endif
void openSeparateConsole(){
#ifdef _WIN32
FreeConsole();
if(AllocConsole()){freopen("CONIN$","r",stdin);freopen("CONOUT$","w",stdout);freopen("CONOUT$","w",stderr);}
#endif
}
