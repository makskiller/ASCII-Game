#include "game.h"
using namespace std;
WorldMap mapa;
int main()
{

    mapa.setmap();
    mapa.setcursor(0,0);
    mapa.move();
    return 0;
}
