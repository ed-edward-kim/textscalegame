#ifndef SHOP_H
#define SHOP_H

#include "Stats.h"

using namespace std;

class Shop
{
    public:
        Shop();
        
        //maaybe figure out setItemList
        void setItemList(int playerlevel); //retreives item list from arrays. Scales with palyer level
        void getItemList(); //outputs the shop.
        
        void setModifiers();        //deals with modifiers
        string getRandomModifiers();
        
        int setWeaponCost(); //gets weapon cost
        int getWeaponCost();
        
        int setArmorCost(); //gets armor cost
        int getArmorCost();
        
        void itemCosts(int playerlevel); //checks level of player to/and deal with money scaling :)
        void removeItemFromShop(int itemnumber);
        
        void hasLeveled(int playerlevel); //checks if you have leveled up. Deals with money and damage scaling as well for shop items.

        //getitem for each item in the shop
        void setItem1(); //sets item stat
        string getItem1();
        int getItem1Stat();
        
        void setItem2();
        string getItem2();
        int getItem2Stat();
        
        void setItem3();
        string getItem3();
        int getItem3Stat();
        
        void setItem4();
        string getItem4();
        int getItem4Stat();
        
        void setItem5();
        string getItem5();
        int getItem5Stat();
        
        
        //void setCurrentLevel(int level);
        
    private:
        string shoplist[4]; //total of 5 items at random can be in the shop involving helm, etc
        string savedshoplist[4]; //just to save shoplist, this way we can use a bool that wont let them see new items till a level up.
        //string itemname;
        string item; //holder func for getlining to add to array
        
        
        
        bool atkordef; //used to check whether the thing bought is an armour or a weapon bought. true = armour, false = weapon.
        
        int shoplevel; //scaling the shop's level. If you have not leveled, the shop will be the same.
        bool levelup; //used to check whether or not you leveled so new items will be in the shop. 
        
        //Items and their stats!
        
        int random_number;
        
        string random_mod;
        int modvalue[4];      
        string modifiername[23]; //modifier name
        int modifiervalue[23]; //modifier value that goes with name.
        
        
        string item1;
        int item1stat;
        
        string item2;
        int item2stat;
        
        string item3;
        int item3stat;
        
        string item4;
        int item4stat;
        
        string item5;
        int item5stat;
        
        //weapon and armor costs;
        int weaponcost;
        int armorcost;

};

#endif