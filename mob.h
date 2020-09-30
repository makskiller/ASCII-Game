#include <iostream>
#include <conio.h>
using namespace std;
class Mob
  {
  protected:
    int level;     //creature level
    int health;    //creature health
    int damage;       //creature damage
    int defense;  //creature defense
public:
    virtual void doAttack();
    //Getters
    string getname();
    string getdescription();
  };
class Hero ;

class Monster :public Mob
    {
        string name;
        string description;
public:
        Monster(char Name, int Level);
        //Funkcje:
        void doAttack(Hero *target);
        void getAttacked(int ATK);
        //Getters:
        string getname();
        string getdescription();
        //setters:
        void setdeath();


    };

class Hero :public Mob
    {
    protected:
        string name;
        bool isdead;
    public:
        Hero(string Name);
        //Funkcje:
        void doAttack();
        //getters
        string getname();
        int gethealth();
        int getdefense();
        int getlevel();
        //setters
        void sethealth(int wartosc);
        void setdeath(string Name);
    };
