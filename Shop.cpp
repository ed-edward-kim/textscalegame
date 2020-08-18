#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Shop.h"
using namespace std;

Shop::Shop()
{
    srand(time(0));//for randomness wew
    setModifiers();
    //newshop = true;
    itemCosts(1);//initially fill item price
    shoplevel = 0;
    levelup = true;
    //Have this section run once to have an item set already. This way it wont get stuck in a false loop
    int index = 0;
    
    ifstream shopfile;
    shopfile.open("shop.txt");
    string item;
    while (!(shopfile.eof())) //while not at end of file, but the item's from the shop list into an array, that way we can grab random values from the array to correspond to the item.
    {
        getline(shopfile, item);      
        savedshoplist[index] = item;
        index++;
    }

}

void Shop::setModifiers()
{
    
    string mname = "";
    string mvalue = "";
    modifiername[22];
    int index = 0;
    ifstream modifier;
    modifier.open("modifiers.txt");
    
    for (int index = 0; index < 22; index++)  //because a total of 23 modifiers
    {
        getline(modifier, mname, ',');
        modifiername[index] = mname;
        
        getline(modifier, mvalue);
        modifiervalue[index] = stoi(mvalue);
    }
    modifier.close();
}

string Shop::getRandomModifiers()
{
    //int random_probability = rand()% 100;
    random_number = rand()% 21 + 1; //21
    
/*    if (random_probability <= 5) //so a 5% chance to get a legendary mod!
    {
        random_mod = modifiername[21];
        return random_mod;
    }
    else
    {*/
    random_mod = modifiername[random_number];   //else you get a modifier from 0 - 21
    
    return random_mod;        
    //}

}


void Shop::setItemList(int playerlevel)//bool levelup)//gets playerlevel from shoplevel
{
    if (levelup == true) //if this is set to true, that means that you have leveled up recently, so it will give you a new list of items.
    {
        
        int index = 0;
        ifstream shop;
        shop.open("shop.txt");
        while (!(shop.eof())) //while not at end of file, but the item's from the shop list into an array, that way we can grab random values from the array to correspond to the item.
        {
            random_mod = getRandomModifiers(); //gets a random mod
            getline(shop, item);      
            savedshoplist[index] = random_mod + " " + item;
            modvalue[index] = modifiervalue[random_number];// + playerlevel; //attaches the modifier damage that corresponds with the random mod 
            index++;
        }    
        shop.close();
    }
    else if (levelup == false)  //if you have not leveled up since your last time at the shop, it will show the same equipment.
    {
        cout << "Level up in order to get new items in the shop!" << endl;

    }
    
    
    
}




int Shop::getWeaponCost()
{
    return weaponcost;
}
int Shop::setWeaponCost()
{
    ;
}

int Shop::getArmorCost()
{
    return weaponcost;
}
int Shop::setArmorCost()
{
    ;//return armorcost;
}

/*void Shop::setLevelup (int level)
{
    currentlevel = level;
}*/

void Shop::itemCosts(int playerlevel)//checks current level of player to deal with money scaling
{
    int randomnumber = rand()% 10 + 2; //random number between 2 and 10
    weaponcost = 100 + ((playerlevel * randomnumber) * 2);

}

void Shop::removeItemFromShop(int numbervalue)
{
    savedshoplist[numbervalue - 1] = "";
}

void Shop::hasLeveled(int playerlevel)
{
    if (shoplevel == playerlevel)
    {
        levelup = false;
        setItemList(shoplevel);
    }
    else if (shoplevel != playerlevel)
    {
        levelup = true;
        shoplevel = playerlevel;
        setItemList(shoplevel);
        itemCosts(shoplevel);
    }
}


void Shop::setItem1()
{
    item1 = savedshoplist[0];     //sets first item as the shoplist's first item.
    item1stat = modvalue[0];
}
string Shop::getItem1()
{
    return item1;
}
int Shop::getItem1Stat()
{
    return item1stat;
}


void Shop::setItem2()
{
    item2 = savedshoplist[1];
    item2stat = modvalue[1];
}
string Shop::getItem2()
{
    return item2;
}
int Shop::getItem2Stat()
{
    return item2stat;
}

void Shop::setItem3()
{
    item3 = savedshoplist[2];
    item3stat = modvalue[2];
}
string Shop::getItem3()
{
    return item3;
}
int Shop::getItem3Stat()
{
    return item3stat;
}


void Shop::setItem4()
{
    item4 = savedshoplist[3];
    item4stat = modvalue[3];
}
string Shop::getItem4()
{
    return item4;
}
int Shop::getItem4Stat()
{
    return item4stat;
}

void Shop::setItem5()
{
    item5 = savedshoplist[4];
    item5stat = modvalue[4];
}
string Shop::getItem5()
{
    return item5;
}
int Shop::getItem5Stat()
{
    return item5stat;
}


void Shop::getItemList()
{
    for (int i = 0; i < 5; i++)
    {
        if (savedshoplist[i] == "")
        {
            cout << i + 1 << " : SOLD! " << endl;
        }
        else
        {
            if (i == 0)
            {
                cout << i+1 << " : " << savedshoplist[i] << "  Cost: " << weaponcost << " | Power -> " << modvalue[i] << endl;
            }
            else if (i == 4)
            {
                cout << i+1 << " : " << savedshoplist[i] << "  Cost: " << weaponcost << " | Heal power -> " << modvalue[i] * 2 << endl;
            }
            else
            {
                cout << i+1 << " : " << savedshoplist[i] << "  Cost: " << weaponcost << " | Defence -> " << modvalue[i] << endl;
            }
            
        }
        
    }
}