#include <iostream>
#include <string>
#include "Gear.h"
#include "Stats.h" //for currentstats

using namespace std;

Gear::Gear()
{
    helmet = "No Helmet Equipped!";
    chest = "No Chest Equipped!";
    shoes = "No Shoes Equipped!";
    weapon = "No Weapon Equipped!";
    consumable = "No Consumable Equipped!";
    helmet_stats = 0;
    chest_stats = 0;
    shoe_stats = 0;
    weapon_stats = 0;
    consumable_stats = 0;
}

//Helmet//_______________________________________
void Gear::setHelmet(string helmetname)//param
{
    helmet = helmetname;
}
string Gear::getHelmet()//param
{
    return helmet;
}
void Gear::setHelmet_Stats(int helmetstats)
{
    helmet_stats = helmetstats;
}
int Gear::getHelmet_Stats()
{
    return helmet_stats;
}
//_______________________________________


//Chest//_______________________________________
void Gear::setChest(string chestname)//param
{
    chest = chestname;
}
string Gear::getChest()//param
{
    return chest;
}
void Gear::setChest_Stats(int cheststats)
{
    chest_stats = cheststats;
}
int Gear::getChest_Stats()
{
    return chest_stats;
}
//_______________________________________


//Shoes//_______________________________________
void Gear::setShoes(string shoesname)//param
{
    shoes = shoesname;
}
string Gear::getShoes()//param
{
    return shoes;
}
void Gear::setShoes_Stats(int shoestats)
{
    shoe_stats = shoestats;
}
int Gear::getShoes_Stats()
{
    return shoe_stats;
}
//_______________________________________


//Weapon//_______________________________________
void Gear::setWeapon(string weaponname)//param
{
    weapon = weaponname;
}
string Gear::getWeapon()
{
    return weapon;
}
void Gear::setWeapon_Stats(int weaponvalue)
{
    weapon_stats = weaponvalue;
}
int Gear::getWeapon_Stats()
{
    return weapon_stats;
}

//Consumable//_____________
void Gear::setConsumable(string consumablename)
{
    consumable = consumablename;
}

string Gear::getConsumable()
{
    return consumable;
}

void Gear::setConsumable_Stats(int consumablevalue)
{
    consumable_stats = consumablevalue * 2;
}
int Gear::getConsumable_Stats()
{
    return consumable_stats;
}
//_____________________________________

//Defence

int Gear::getDefence(int playerlevel) //your playerlevel gives you bonus defence!
{
    defence = helmet_stats + chest_stats + shoe_stats + playerlevel;
    return defence;
}

//Damage
int Gear::getDamage(int playerlevel) //playerlevel gives bonus attak!
{
    damage = weapon_stats + playerlevel;
    return damage;
}

//Display Current Stats//_______________________________________

        //figure out order to layout stats as
void Gear::gearStats()
{
    int total_def = helmet_stats + chest_stats + shoe_stats;
    
    cout << "Helmet: " << helmet << " | Armor -> " << helmet_stats << endl;
    cout << "Chest: " << chest << " | Armor -> " << chest_stats << endl;
    cout << "Shoes: " << shoes << " | Armor -> " << shoe_stats << endl;
    cout << "Weapon: " << weapon << " | Power -> " << weapon_stats << endl;
    cout << "Consumable: " << consumable << " | Heals -> " << consumable_stats << endl;
    cout << endl;
    
    cout << "Total Defence: " << total_def << endl;
    cout << "Total Power: " << weapon_stats << endl;
    cout << "Potion Heal: " << consumable_stats << endl;
    cout << endl;
}




//_______________________________________