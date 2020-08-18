#include <iostream>
#include <string>
#include "Stats.h"

using namespace std;

Stats::Stats()
{
    level = 1;
    health = 10;
    maxhealth = 10;
    stamina = 10;
    maxstamina = 10;
    money = 700;
    experience = 1;
    maxexperience = 15 + (level * 2);
    //power = 5;
}

//Name
void Stats::setName(string charname)
{
    charactername = charname;
}

string Stats::getName()
{
    return charactername;
}

//Health
void Stats::setHealth(int healthvalue)
{
    health = healthvalue;
}

int Stats::getHealth()
{
    return health;
}

int Stats::getMaxHealth()
{
    return maxhealth;
}

//Money
void Stats::setMoney(int moneyvalue)
{
    money = moneyvalue;
}

int Stats::getMoney()
{
    return money;
}

//Stamina
void Stats::setStamina(int staminavalue)
{
    stamina = staminavalue;
}

int Stats::getStamina()
{
    return stamina;
}

int Stats::getMaxStamina()
{
    return maxstamina;
}

//Level
void Stats::setLevel(int levelvalue)
{
    level = levelvalue;
}

int Stats::getLevel()
{
    return level;
}
/*
//Power
void Stats::setPower(int powervalue)
{
    power = powervalue;
}

int Stats::getPower()
{
    return power;
}
*/

void Stats::setExperience(int experiencevalue, int playerlevel)
{
    
    experience += experiencevalue;
    maxexperience = 15 + (playerlevel * 2);
    if (experience >= maxexperience)
    {
        cout << "Congratulations! You leveled up!" << endl;
        cout << "Health + 5" << endl;
        cout << "Stamina + 2" << endl;
        
        
        level++;
        maxhealth += 5;  //adds 5 max hp
        maxstamina += 2; //adds 2 stamina
        experience = 0;  //resets experience bar
    }
}

int Stats::getExperience()
{
    return experience;
}

int Stats::getMaxExperience()
{
    return maxexperience;
}