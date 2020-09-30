#include "map.h"
//Funkcje mapy
void WorldMap::drawmap()
    {
        for(int i=0; i<50; i++) //Rysowanie tablicy
            {

                for(int i2=0; i2<50; i2++)
                    {
                        cout<<(tiles[i2][i]);
                    }
                    cout<<endl;
            }
    }
void WorldMap::setmap()
    {
        for(int i=0; i<50; i++) //Wyzerowanie tablicy
            {
                for(int i2=0; i2<50; i2++)
                    {
                        tiles[i2][i]='.';
                    }
            }
        for(int i=0; i<50; i++)
            {
                tiles[0][i]='#'; //G�rna kraw�d�
                tiles[i][49]='#'; //Prawa kraw�d�
                tiles[49][i]='#'; //Dolna kraw�d�
                tiles[i][0]='#'; //Lewa kraw�d�
            }
        tiles[x][y]='o';
        tiles[2*x][2*y]='S';
        drawmap();
        cout<<endl;
        }



void WorldMap::updatemap(int way)
    {
        COORD crd;
        crd.X=x;
        crd.Y=y;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), crd );
        tiles[x][y]='.';
        cout<<tiles[x][y];
        switch(way)
            {
            case 1:
                {
                    y-=1;
                    crd.Y=y;
                    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), crd );
                    tiles[x][y]='o';
                    cout<<tiles[x][y];
                }
                break;
            case 2:
                {
                    x-=1;
                    crd.X=x;
                    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), crd );
                    tiles[x][y]='o';
                    cout<<tiles[x][y];
                }
                break;
            case 3:
                {
                    y+=1;
                    crd.Y=y;
                    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), crd );
                    tiles[x][y]='o';
                    cout<<tiles[x][y];
                }
                break;
            case 4:
                {
                    x+=1;
                    crd.X=x;
                    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), crd );
                    tiles[x][y]='o';
                    cout<<tiles[x][y];
                }
                break;
            }
    }

int WorldMap::wherex()
  {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      COORD                      result;
      if (!GetConsoleScreenBufferInfo(
            GetStdHandle( STD_OUTPUT_HANDLE ),
             &csbi))
    return -1;
  return result.X;
  }
int WorldMap::wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }

 void WorldMap::setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
  {
  	if(size == 0)
  	{
  		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
  	}
  	CONSOLE_CURSOR_INFO lpCursor;
  	lpCursor.bVisible = visible;
  	lpCursor.dwSize = size;
  	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&lpCursor);
  }
void WorldMap::stepto(char CH, int way)
    {
        switch(CH)
            {
            case '#':
                {
                    ;
                }
                break;
            case 'S':
                {
                    system("cls");
                    cout<<"You faced skeleton!"<<endl;
                    cout<<"You beat skeleton"<<endl;
                    cout<<"Press any key to continue: ";
                    getch();
                    system("cls");
                    drawmap();
                    updatemap(way);
                }
                break;
            case '.':
                {
                    updatemap(way);
                }
                break;
            }
    }
void WorldMap::move()
    {
        int guard=0;
        int mv;
        while(guard==0)
        {

        mv=getch();
        switch(mv)
            {
            case 119:            //"W"  do góry
                    {
                        stepto(tiles[x][y-1], 1);
                    }
                break;
            case 97:                //"A" w lewo
                    {
                        stepto(tiles[x-1][y], 2);
                    }
                break;
            case 115:               //"S" do dolu
                    {
                        stepto(tiles[x][y+1], 3);
                    }
                break;
            case 100:                  //"D" w prawo
                    {
                        stepto(tiles[x+1][y], 4);
                    }
                break;
            case 27:                    //"ESC" escape
                    {
                        system("cls");
                        cout<<"Koniec gry"<<endl;
                        guard=1;
                    }
                break;
            }


        }
    }
