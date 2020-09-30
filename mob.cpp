#include "mob.h"
//                  Monster
Monster::Monster(char Name, int Level)
    {
        switch(Name)
            {
            case 's':
                {
                    name="skeleton";
                    level= Level;
                    health = 10*(2^(Level-1));
                    damage = 3*(2^(Level-1));
                    defense = 2*(2^(Level-1));
                }
                break;
            }
    }
void Monster::doAttack(Hero *target)
    {
        int hth=target->gethealth();
        int att=damage-target->getdefense();
        if(att>0)
            {
                cout<<name<<" "<<level<<" is attacking"<<endl;
                target->sethealth(att);
                cout<<target->getname()<<" lvl "<<target->getlevel()<<" received "<<att<<" dmg";
                if(hth<0)
                    {
                        cout<<target->getname()<<" is dead!";
                        target->setdeath(name);
                    }
            }
    }
void Monster::getAttacked(int ATK)
    {
        ATK-=defense;
        health-=ATK;
        cout<<name<<" lvl "<<level<<" received "<<ATK<<"dmg";
        if(health<0)
            {
                setdeath();
            }
    }
string Monster::getname()
    {
        return name;
    }
string Monster::getdescription()
    {
        return description;
    }
void Monster::setdeath()
    {
        cout<<name<<" "<<level<<" died!";
    }
    //======================================================
//                             Hero
Hero::Hero(string Name)
    {
        name=Name;
        isdead=false;
        level=1;
        health=30;
        damage=3;
        defense=3;
    }
string Hero::getname()
    {
        return name;
    }
int Hero::getdefense()
    {
        return defense;
    }
int Hero::getlevel()
    {
        return level;
    }
void Hero::sethealth(int wartosc)
    {
        health+=wartosc;
    }
void Hero::setdeath(string name)
    {
        system("cls");
        cout<<"You are dead!"<<endl;
        cout<<this->name<<" killed by: "<<name<<endl;
        cout<<"Game Over press any key to exit: ";
        getch();
        isdead=true;
    }
