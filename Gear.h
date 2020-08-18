#ifndef GEAR_H
#define GEAR_H

using namespace std;

//include an item list perhaps through file.io, read stats through that?
//modifiers to gear through random?
class Gear
{
    public:
        Gear(); //default constructor
        
        //add parameters later
        
        //helmet
        void setHelmet(string helmet_name);
        string getHelmet();   //might change from int to string to deal with attributes possibly? Or return multiple int's in a certain order, probably need to write an order on notepad
        void setHelmet_Stats(int helmetstats);
        int getHelmet_Stats();
        
        //chest
        void setChest(string chest_name);
        string getChest();
        void setChest_Stats(int cheststats);
        int getChest_Stats();
        
        //Shoes
        void setShoes(string shoes_name);
        string getShoes();
        void setShoes_Stats(int shoestats);
        int getShoes_Stats();
        
        //Weapon
        void setWeapon(string weapon_name);
        string getWeapon();
        void setWeapon_Stats(int weaponstats);
        int getWeapon_Stats();
        
        //Consumable
        void setConsumable(string consumable_name);
        string getConsumable();
        void setConsumable_Stats(int consumablestats);
        int getConsumable_Stats();
        
        //Get defence
        int getDefence(int playerlevel);
        //Get Damage
        int getDamage(int playerlevel);
        
        //implement current stats maybe
        void gearStats();
        
    private:
        //helmet
        string helmet;
        int helmet_stats;
        
        //chest
        string chest;
        int chest_stats;
        
        //kicks
        string shoes;
        int shoe_stats;
        
        //weapon
        string weapon;
        int weapon_stats;
        
        //consumable
        string consumable;
        int consumable_stats;
        
        //gear modifiers (choose order wisely)
        int damage;
        int defence;
        int health;  //can this share with stats.h or will there be issues?
        int stamina;  //^
};





#endif