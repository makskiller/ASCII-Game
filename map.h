
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;
//Klasa mapy
class WorldMap
    {
    protected:
        char tiles[50][50]={'.'};
        int x=5,y=5; //Pozycja gracza
    public:
      void drawmap();
      void setmap();
      void updatemap(int way);
      void move();
      int wherex();
      int wherey();
      void setcursor(bool visible, DWORD size);
      void stepto(char CH, int way);
    };
