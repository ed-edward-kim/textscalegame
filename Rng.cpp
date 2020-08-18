#include <iostream>
#include <string>
#include <ctime>
#include "Rng.h"
//include other files to use probability
using namespace std;

Rng::Rng()
{
    srand(time(0)); 
    criticalhit = false;
    miss = false;
    runchance = false;
}

void Rng::setRandom_Num()
{
    ; //random function / probability function? Or have probabiltiy function separate.
}

int Rng::getRandom_Num()
{
    ;//return random_num;
}

void Rng::setCriticalHit()
{
    //criticalhit = (rand() 100) < 5; //a 5% chance to land a critical hit. 2x damage.
    ;
}
int Rng::getCriticalHit(int playerlevel)
{
    criticalhit = (rand()% 100) < (5 + playerlevel); //a 5% chance to land a critical hit. 2x damage. Every time you level it goes up by 1%
    if (criticalhit == false)
    {
        return 1;
    }
    else if(criticalhit == true)
    {
        cout << "Critical Hit!" << endl; //2x damages
        return 2;
    }
}

void Rng::setMiss()
{
    ;
}
int Rng::getMiss()
{
    miss = ((rand()% 100) < 5); //a 5% chance miss attack. If false, then you didn't miss. 
    if (miss == false)
    {
        return 1;
    }
    else if(miss == true) //if critical hit misses, return 0.
    {
        cout << "Attack Missed!" << endl; //2x damages
        return 0;
    }
}


int Rng::getRandomEvent()
{
    bool tripandfall = (rand()%100) < 1; //theres a 1% chance to trip and take damage.
    if (tripandfall == true)
    {
        cout << "You tripped and took damage!" << endl;
        return 5;
    }
    else
    {
        return 0;
    }
}

int Rng::runAway(int playerhealth)
{
    runchance = ((rand()% 100) < (45 + playerhealth )); //a 45% chance to run away. Will increase by 1 for amount of health had)
    if (runchance == false)
    {
        return 0;
    }
    else if(runchance == true) 
    {
        return 1;
    }
}





//probability stuff