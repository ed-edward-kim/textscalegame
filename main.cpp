#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <fstream>

//Random function stuff:
#include <ctime> //random numbers
#include <stdlib.h> // Clear console?


//Headers
#include "Stats.h"
#include "Bossing.h"
#include "Biome.h"
#include "Gear.h"
#include "Monster.h"
#include "Rng.h"
#include "Shop.h"

using namespace std;

void clear()  //found this on google, will use this to clear the console.
{ 
    cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
}



void SaveRecord(Stats& player)
{
    cout << "Record saved to record.txt. " << endl;
    ofstream record;
    record.open("record.txt");
    record << "Name: " << player.getName() << endl;
    record << "Max Level: " << player.getLevel();
    record.close();
    //record << "Bosses Completed: " << something with bosses
    
    exit(0);
}


void Store(Stats& player, Shop& shop, Gear& gear)//, bool shoplevel)
{
    int money = player.getMoney();
    int currentplayerlevel = player.getLevel();
    //cout << "Test 1: " << player.getMoney();
    int weaponcost = 0;
    int armorcost = 0;
    string choice = "";
    string buyitem = ""; //buy item input
    //cout << "Test 2: " << player.getMoney();
    while (choice != "6")
    {
        //just to set all the items. Probably could have put this somewhere else.
        //cout << "Test 3: " << player.getMoney();
        cout << "Current Money: " << player.getMoney() << endl;
        shop.hasLeveled(currentplayerlevel);   //checks if you have leveled up or not. If you leveled up, you get a new shop.
        
        //sets shop
        shop.getItemList();//shoplevel);
        shop.setItem1();
        shop.setItem2();
        shop.setItem3();
        shop.setItem4();
        shop.setItem5();
        cout << "6: Leave shop" << endl;
        cout << "Type the number and hit enter to purchase! " << endl;
        getline(cin, choice);
        
        if (choice == "" || (!(choice > "0"  && choice < "7" )))  //default doesn't work with stoi if you accidentally type a non-number value. This sets unusuable answers to "7" 
        {
            choice = "7";
        }
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Not a valid input!" << endl;
        }
        
        switch(stoi(choice))
        {
            case 1: 
            {
                if (shop.getItem1() == "")
                {
                    clear();
                    cout << "This has been sold out!\n" << endl;
                    break;
                }
                
                cout << "Are you sure you would like to buy " << shop.getItem1() << " for " << shop.getWeaponCost() << " money? (Y/N): " << endl;    //weapon cost to armor cost prolly
                getline(cin, buyitem);
                if (buyitem == "Y" || buyitem == "y")
                {
                    if (player.getMoney() < shop.getWeaponCost())//if you dont have money for the item
                    {
                        clear();
                        cout << "You do not have enough money for this item! " << endl;
                        break;
                    }
                    else if (player.getMoney() >= shop.getWeaponCost())//if you have money for the item
                    {
                        clear();
                        player.setMoney(player.getMoney() - shop.getWeaponCost());
                        cout << "Item: '"<< shop.getItem1() << "' has been purcahsed. Remaining balance: " << player.getMoney() << endl;
                        gear.setWeapon(shop.getItem1()); //sets your weapon to the item from the shop
                        gear.setWeapon_Stats(shop.getItem1Stat()); //sets the stats for said weapon from the shop
                        shop.removeItemFromShop(1); //removes item from shop.
                    }
                    break;
                }
                else if (buyitem == "N" || buyitem == "n")
                {
                    clear();
                    cout << "Item purchase canceled. " << endl;
                    break;
                }
                else
                {
                    clear();
                    cout << "That is not an option! " << endl;
                    break;
                }
                break;
            }
            case 2: 
            {
                if (shop.getItem2() == "")
                {
                    clear();
                    cout << "This has been sold out!\n" << endl;
                    break;
                }
                
                cout << "Are you sure you would like to buy " << shop.getItem2() << " for " << shop.getWeaponCost() << " money? (Y/N): " << endl;
                getline(cin, buyitem);
                if (buyitem == "Y" || buyitem == "y") 
                {
                    if (player.getMoney() < shop.getWeaponCost()) //If you don't have enough money
                    {
                        clear();
                        cout << "You do not have enough money for this item! " << endl;
                        break;
                    }
                    else if (player.getMoney() >= shop.getWeaponCost()) //if you have enough money
                    {
                        clear();
                        player.setMoney(player.getMoney() - shop.getWeaponCost());
                        cout << "Item: '"<< shop.getItem2() << "' has been purcahsed. Remaining balance: " << player.getMoney() << endl;
                        gear.setHelmet(shop.getItem2()); 
                        gear.setHelmet_Stats(shop.getItem2Stat());
                        shop.removeItemFromShop(2);
                    }
                    break;
                }
                else if (buyitem == "N" || buyitem == "n")
                {
                    clear();
                    cout << "Item purchase canceled. " << endl;
                    break;
                }
                else
                {
                    clear();
                    cout << "That is not an option! " << endl;
                    break;
                }
                break;
            }
            case 3: 
            {
                if (shop.getItem3() == "")
                {
                    clear();
                    cout << "This has been sold out!\n" << endl;
                    break;
                }
                
                cout << "Are you sure you would like to buy " << shop.getItem3() << " for " << shop.getWeaponCost() << " money? (Y/N): " << endl;
                getline(cin, buyitem);
                if (buyitem == "Y" || buyitem == "y")
                {
                    if (player.getMoney() < shop.getWeaponCost())
                    {
                        clear();
                        cout << "You do not have enough money for this item! " << endl;
                        break;
                    }
                    else if (player.getMoney() >= shop.getWeaponCost())
                    {
                        clear();
                        player.setMoney(player.getMoney() - shop.getWeaponCost());
                        cout << "Item: '"<< shop.getItem3() << "' has been purcahsed. Remaining balance: " << player.getMoney() << endl;
                        gear.setChest(shop.getItem3());
                        gear.setChest_Stats(shop.getItem3Stat()); 
                        shop.removeItemFromShop(3);
                    }
                    break;
                }
                else if (buyitem == "N" || buyitem == "n")
                {
                    clear();
                    cout << "Item purchase canceled. " << endl;
                    break;
                }
                else
                {
                    clear();
                    cout << "That is not an option! " << endl;
                    break;
                }
                break;
            }
            case 4: 
            {
                if (shop.getItem4() == "")
                {
                    clear();
                    cout << "This has been sold out!\n" << endl;
                    break;
                }
                
                cout << "Are you sure you would like to buy " << shop.getItem4() << " for " << shop.getWeaponCost() << " money? (Y/N): " << endl;
                getline(cin, buyitem);
                if (buyitem == "Y" || buyitem == "y")
                {
                    if (player.getMoney() < shop.getWeaponCost())
                    {
                        clear();
                        cout << "You do not have enough money for this item! " << endl;
                        break;
                    }
                    else if (player.getMoney() >= shop.getWeaponCost())
                    {
                        clear();
                        player.setMoney(player.getMoney() - shop.getWeaponCost());
                        cout << "Item: '"<< shop.getItem4() << "' has been purcahsed. Remaining balance: " << player.getMoney() << endl;
                        gear.setShoes(shop.getItem4());
                        gear.setShoes_Stats(shop.getItem4Stat());
                        shop.removeItemFromShop(4);
                    }
                    break;
                }
                else if (buyitem == "N" || buyitem == "n")
                {
                    clear();
                    cout << "Item purchase canceled. " << endl;
                    break;
                }
                else
                {
                    clear();
                    cout << "That is not an option! " << endl;
                    break;
                }
                break;
            }
            case 5: 
            {
                if (shop.getItem5() == "")
                {
                    clear();
                    cout << "This has been sold out!\n" << endl;
                    break;
                }
                
                cout << "Are you sure you would like to buy " << shop.getItem5() << " for " << shop.getWeaponCost() << " money? (Y/N): " << endl;
                getline(cin, buyitem);
                if (buyitem == "Y" || buyitem == "y")
                {
                    if (player.getMoney() < shop.getWeaponCost())
                    {
                        clear();
                        cout << "You do not have enough money for this item! " << endl;
                        break;
                    }
                    else if (player.getMoney() >= shop.getWeaponCost())
                    {
                        clear();
                        player.setMoney(player.getMoney() - shop.getWeaponCost());
                        cout << "Item: '"<< shop.getItem5() << "' has been purcahsed. Remaining balance: " << player.getMoney() << endl;
                        gear.setConsumable(shop.getItem5());
                        gear.setConsumable_Stats(shop.getItem5Stat());
                        shop.removeItemFromShop(5);
                    }
                    break;
                }
                else if (buyitem == "N" || buyitem == "n")
                {
                    clear();
                    cout << "Item purchase canceled. " << endl;
                    break;
                }
                else
                {
                    clear();
                    cout << "That is not an option! " << endl;
                    break;
                }
                break;
            }
            case 6: 
            {
                clear();
                break;
            }
            default:
            {
                cout << "That is not an option!" << endl;
            }
        }
    }
}

void Intro(Stats& player)
{
    string name;
    cout << "Welcome to The Game!" << endl;
    //enter more stuff here
    cout << "Please enter your name!: " << endl;
    getline(cin, name);
    player.setName(name);
    clear();
    cout << "Welcome to the game " << player.getName() << "!\n" << endl;
}


void MenuHome()
{
    cout << "What would you like to do?" << endl;
    cout << "1: View Stats " << endl;
    cout << "2: View Equipment " << endl; //maybe combined with stats?
    cout << "3: Go to the Store " << endl;
    cout << "4: Adventure " << endl;
    cout << "5: Challenge the Bosses " << endl;
    cout << "6: Quit The Game (Progress will not be saved!) " << endl;

}

string BiomeMenu(Biome& biome) 
{
    string choice = "";
    clear();
    cout << "Which Biome would you like to travel?\n" << endl;
    cout << "1: Fire" << endl;
    cout << "2: Wind" << endl;
    cout << "3: Water" << endl;
    cout << "4: Land" << endl;
    cout << "Type the number and press Enter: " << endl;
    
    getline(cin, choice);
    
    //biome.setBiome(stoi(choice));
    
    
    if (choice == "1")
    {
        choice = "Fire";
        return choice;
    }
    else if (choice == "2")
    {
        choice = "Wind";
        return choice;
    }
    else if (choice == "3")
    {  
        choice = "Water";
        return choice;
    }
    else if (choice == "4")
    {
        choice = "Land";
        return choice;
    }
    else
    {
        cout << "That is not an option, so we are going by land whether you like it or not." << endl;
        choice = "Land";
        return choice;
    }
    
 
}

void AdventureMenu()
{
    string input = "";
    cout << "1 : Attack!" << endl;
    cout << "2 : Defend!" << endl;
    cout << "3 : Use Potion!" << endl;
    cout << "4 : Run Away!" << endl;

    
}

void Adventure(Monster& monster, Stats& player, Rng& random, Gear& gear, Biome& biome)
{
    //chooses which Biome you want to go to
    int answer = 0;
    string prefix = "";
    string rand_monster = ""; //random monster is the prefix and biome and monster name
    string choice = "";
    int money = player.getMoney();
    
    //player variables
    int maxstamina = player.getMaxStamina();
    int stamina = maxstamina;
    int maxhealth = player.getMaxHealth();
    int playerhealth = player.getHealth();
    int playerlevel = player.getLevel();
    int defence = gear.getDefence(playerlevel);
    int damagedone = 0; //damage done to enemy
    int totaldamage = 0; //damage after things like critical and miss are taken into account
    int criticalhit = 0;
    int potion = 0;
    
    //monster variables
    string monsterprefix = "";
    int monsterhealth = 0;
    int maxmonsterhealth = 0;
    int monsterdamagetaken = 0;
    string monstername = "";
    int monsterexperience = 0;
    int monstermoney = 0;
    int monsterdamage = 0;
    int monsterdefence = 0;
    int totalmonsterdamage = 0;
    int runchance = 0;
    int fall = 0;
    bool runaway = false;    //if you run away, you have a chance for it to be true. if its true, you go back home.
    bool gohome = false;  
    bool loop = false; //to exit the 
    monster.setMonster_Prefixes();
    string biometype = BiomeMenu(biome);//gets what biome you went to.
    
    clear();
    

    cout << "You have have chosen the " << biometype <<" Biome." << endl;   //biome.getBiome(biometype)
    
    while(gohome == false)
    {
        monster.setMonster_Values(player.getLevel()); //sets all the monster values for a random monster. scales with player level.
        monsterprefix = monster.getMonster_Prefixes();
        monstername = monster.getMonster_Name();
        damagedone = 0;
        monsterhealth = 0;
        rand_monster = biometype + " " + monstername; //adds a prefix, biome, and name to output
        runaway = false;
        loop = false;
        
        cout << "As you venture out, you come across a " << biometype << " " << monstername << endl;
        
        cout << "What would you like to do? \n" << endl;
        
        cout << "Test1: " << monsterprefix << endl;
        cout << "Test2: " << monster.getMonster_Prefixes();
        while(playerhealth > 0 && runaway == false && loop==false)
        {

            monsterhealth = monster.getMonster_Hp();
            monster.setMonster_Values(player.getLevel()); //when we run it for round 2 we get a new monster :D
            
            maxmonsterhealth = monsterhealth;
            while ((monsterhealth > 0 && runaway == false) && (playerhealth > 0 && runaway == false))
            {
                if (loop == true)
                {
                    monsterhealth = monster.getMonster_Hp();
                    monster.setMonster_Values(player.getLevel()); //when we run it for round 2 we get a new monster :D
                }
                if (stamina < 1)
                {
                    cout << "You are out of Stamina. You will take 1 damage per turn!";
                    player.setHealth(playerhealth - 1);
                }
                
                cout << rand_monster << " Health: " << monsterhealth << endl; //display monster hp
                
                cout << "\n" << endl;
                cout << player.getName() << " Health: " << player.getHealth() << endl << endl;
                cout << player.getName() << " Stamina: " << stamina << endl;
                AdventureMenu();
                getline(cin, choice);
                if (choice == "" || (!(choice > "0"  && choice < "5" )))  //default doesn't work with stoi if you accidentally type a non-number value. This sets unusuable answers to "7" 
                {
                    choice = "6";
                }
                switch(stoi(choice))
                {
                    case 1:
                    {
                        clear();
                        fall = random.getRandomEvent(); //random events (only have 1)
                        
                        if (fall == 5)
                        {
                            player.setHealth(playerhealth - 5);
                        }
                        
                        
                        damagedone = gear.getDamage(playerlevel);  //damage from gear
                        criticalhit = random.getCriticalHit(playerlevel);       //crit chance 5%. Increases by 1% for every level.
                        monsterdefence = monster.getMonster_Defence();  //monster's defence
                        totaldamage = ((damagedone - monsterdefence) * criticalhit);  //damage dealth is the damage done, minus the monsters defence, times a critical hit. If crit misses, critical hit=1
                        //cout << "Test: Total damage: " << totaldamage << endl;
                        if (totaldamage < 1) //if the armor is to strong, you will do a minimum of 1 damage.
                        {
                            totaldamage = 1;
                        }
                		cout << "monsterdef: " << monsterdefence << ", damage done: " << damagedone << ", totaldamage = " << totaldamage << endl;
                        cout << "You dealt " << totaldamage << " Damage to the " << rand_monster << "!" << endl;
                        monsterhealth = monsterhealth - totaldamage; //this might be unecessary
                        monster.Monster_Hp(monsterhealth);
                        
                        monsterdamage = monster.getMonster_Attack();
                        defence = gear.getDefence(playerlevel);
                        totalmonsterdamage = monsterdamage - defence;
                        
                        if (totalmonsterdamage < 1)
                        {
                            totalmonsterdamage = 1;
                        }
                        
                        cout << biometype << " " << monstername << " dealt " << totalmonsterdamage << "!" << endl;
                        player.setHealth(playerhealth - totalmonsterdamage);
                        
                        playerhealth = player.getHealth();
                        stamina--;
                        player.setStamina(stamina);
                        break;
                    }
                    case 2:
                    {
                        clear();
                        defence = gear.getDefence(playerlevel + 5); //you get +5 defence, but you do not attack the monster for the turn.
                        monsterdamage = monster.getMonster_Attack();
                        totalmonsterdamage = monsterdamage - defence;
                        if (totalmonsterdamage < 1)
                        {
                            cout << "You defended the attack! It did 0 damage. " << endl;
                            totalmonsterdamage = 0;
                        }
                        cout << rand_monster << " dealt " << totalmonsterdamage <<" Damage!" << endl;
                        stamina--;
                        break;
                    }
                    case 3:
                    {
                        potion = gear.getConsumable_Stats();
                        cout << "You drank a " << gear.getConsumable() << " potion and restored " << potion << " health!" << endl;
                        playerhealth = playerhealth + potion;
                        if (playerhealth > maxhealth)
                        {
                            playerhealth == maxhealth;
                        }
                        player.setHealth(playerhealth);
                        break;
                    }
                    case 4:
                    {
                        clear();
                        stamina--;
                        runchance = random.runAway(playerhealth);
                        
                        if (runchance == 1)
                        {
                            cout << "You successfully ran away!" << endl;
                            runaway = true;
                            gohome = true;
                            break;
                        }
                        else
                        {
                            clear();
                            cout << "You failed to run away!" << endl;
          
                        }
                        
                        break;
                    }
                    default:
                    {
                        clear();
                        cout << "That is not an option!" << endl;
                        
                    }
                }
                if (playerhealth < 1)
                {
                    clear();
                    cout << "You have died." << endl;
                    gohome = true;  //might not need these 2
                    loop = true;
                    SaveRecord(player);
                }
                else if (monsterhealth < 1)
                {
                    clear();
                    string input;
                    monsterexperience = maxmonsterhealth * 3; 
                    monstermoney = (monsterexperience * 2) + playerlevel; //monster gives its experience * 2 + the player level in money
                    cout << "You have gained " << monsterexperience << " experience and " << monstermoney << " Money!" << endl;
                    
                    player.setExperience(monsterexperience, player.getLevel());
                    player.setMoney(money + monstermoney);
                    monsterexperience = 0; //reset
                    monstermoney = 0;
                    cout << "Level: " << player.getLevel() << endl;
                    cout << "Experience: " << player.getExperience() << " / " << player.getMaxExperience() << endl;
                    cout << "Health: " << playerhealth << endl;
                    cout << "Money: " << player.getMoney() << endl;
                    cout << "Would you like to fight again? (Y/N): " << endl;
                    getline(cin, input);
                    
                    if (input == "y" || input == "Y")
                    {
                        loop = true;
                        break;
                    }
                    else if (input == "n" || input == "N")
                    {
                        gohome = true;
                        loop = true;
                        break;
                    }
                    else
                    {
                        cout << "That is not an option! We are going back home." << endl;
                        gohome = true;
                        loop = true;
                        break;
                    }
                }
            }
        }
        
    }
    
    

    
    
    
}


void Boss(Bossing& cthulu, Stats& player, Rng& random, Gear& gear, Biome& biome, int playerlevel)
{
    cthulu.setBoss_Stats();
    string selection = "";
    
    bool end = false;
    
    int bossdamage = cthulu.getBoss_Attack();
    int bossdefence = cthulu.getBoss_Defence();
    int bosshp = cthulu.getBoss_Hp();
    
    
    int playerhealth = player.getHealth();
    int playerdamage = gear.getDamage(playerlevel);
    int playerdefence = gear.getDefence(playerlevel);
    
    int potion = gear.getConsumable_Stats();
    
    int bossdamagedealt = bossdamage - playerdefence;
    int playerdamagedealt = playerdamage - bossdefence;
    
    if (playerdamagedealt < 0)
    {
        playerdamagedealt = 1;
    }
    
    while (player.getHealth() > 0 && cthulu.getBoss_Hp() > 0)
    {
        if (player.getHealth() < 0)
        {
            cout << "You have died." << endl;
            cout << "Record saved to record.txt. " << endl;
            ofstream record;
            record.open("record.txt");
            record << "Name: " << player.getName() << endl;
            record << "Max Level: " << player.getLevel();
            record.close();
            exit(0);
        }
        while (end == false) //probably dont need this since I dont use it
        {
            clear();
            cout << "Cthulu Health: " << bosshp << endl << endl;
            cout << "Player Health: " << playerhealth << endl;
            AdventureMenu();
            getline(cin, selection);
            switch(stoi(selection))
            {
                case 1:
                {
                    cout << "You hit Cthulu for " << playerdamagedealt << endl;
                    cthulu.setBoss_Hp(bosshp - playerdamagedealt);
                    
                    cout << "Cthulu slapped you for " << bossdamagedealt << endl;
                    player.setHealth(playerhealth - bossdamagedealt);
                    
                    if (player.getHealth() < 0)
                    {
                        cout << "You have died." << endl;
                        cout << "Record saved to record.txt. " << endl;
                        ofstream record;
                        record.open("record.txt");
                        record << "Name: " << player.getName() << endl;
                        record << "Max Level: " << player.getLevel();
                        record.close();
                        exit(0);
                    }
                }
                case 2:
                {
                    cout << "You cant block Cthulu. Cthulu hit you for " << bossdamagedealt << endl;
                    player.setHealth(playerhealth - bossdamagedealt);
                    if (player.getHealth() < 0)
                    {
                        cout << "You have died." << endl;
                        cout << "Record saved to record.txt. " << endl;
                        ofstream record;
                        record.open("record.txt");
                        record << "Name: " << player.getName() << endl;
                        record << "Max Level: " << player.getLevel();
                        record.close();
                        exit(0);
                    }
                }
                case 3:
                {
                    cout << "You drank the potion and healed for " << potion << endl;
                    player.setHealth(playerhealth + potion);
                }
                case 4:
                {
                    cout << "You can't run away from Cthulu!" << endl;
                }
                default:
                {
                    cout << "Input no work" << endl;
                }
            }
        }
    }
    if (player.getHealth() > 0)
    {
        cout << "Record saved to record.txt. " << endl;
        ofstream record;
        record.open("record.txt");
        record << "Name: " << player.getName() << endl;
        record << "Max Level: " << player.getLevel();
        record.close();
        record << "Congratulations you killed Cthulu!" << endl;
        exit(0);
    }
    else
    {
        cout << "You died." << endl;
        SaveRecord(player);
    }
    
    
    exit(0);
}


int main()
{
    srand(time(0)); //for random numbers
    
    //Buncha objects for all the classes
    Monster monster;
    Stats player;
    Rng random;
    Gear gear;
    
    Biome biome;
    Shop shop;
    //____________________________________
    
/*    //stuff for shop 
    
    shop.storeValues(player.getLevel()); //sets random values for shop stuff
    bool shoplevel = true;*/
    
    monster.setMonster_Prefixes();
    int devleveltest = 1;
    
    int playerlevel = player.getLevel(); //for initial case because it won't show some stuff otherwise.
    //___
    Intro(player); //maybe make this a tutorial

    string choice = "";
    
    while (choice != "6")
    {
        player.setHealth(player.getMaxHealth()); //refreshes players health to maximum health value.
        player.setStamina(player.getMaxStamina()); //refreshes players health to maximum stamina value;
        MenuHome();
        getline(cin, choice);
        if (choice == "" || (!(choice > "0"  && choice < "7" )))  //default doesn't work with stoi if you accidentally type a non-number value. This sets unusuable answers to "7" 
        {
            choice = "7";
        }
        switch (stoi(choice))
        {
            case 1:
                {
                    clear();
                    cout << "You selected View Stats!\n" << endl;
                    cout << "Name: " << player.getName() << endl;
                    cout << "Level: " << player.getLevel() << endl;
                    cout << "Experience: " << player.getExperience() << " / " << player.getMaxExperience() << endl;
                    cout << "Health: " << player.getHealth() << endl;
                
                    //cout << "Power: " << player.getPower() << endl;
                    cout << "Money: " << player.getMoney() << endl;
                    cout << "Stamina: " << player.getStamina() << endl;
                    cout << "Press Enter to Continue . . .";
                    cin.ignore();  //bug with accidentally typing anything else whatsoever if you dont hit enter, will give the "not an option"
                    clear();
                    break;
                }
            case 2:
                {
 
                    clear();
                    cout << "You selected View Equipment!\n" << endl;
                    gear.gearStats();
                    cout << "Press Enter to Continue . . .";
                    cin.ignore();  
                    clear();
                    break;
                }
            case 3:
                {
                    clear();
                    //shop.hasLeveled(playerlevel);
                    Store(player,shop,gear);//,shoplevel)
                    
                    /*if (playerlevel == player.getLevel())
                    {
                        shoplevel = false; //if the current players level is the same as the player.getlevel, shoplevel is false, which means that the shop will be the same!
                        Store(player, shop, gear, shoplevel);
                    }
                    else if (playerlevel != player.getLevel())
                    {
                        
                        playerlevel = player.getLevel();
                        shop.storeValues(playerlevel); //not working. If you level once, nothing shows in shop for the first time.
                        shoplevel = true; //since this is true, that now means that we can get a new shop.
                        Store(player, shop, gear, shoplevel);
                         
                        
                    }*/
                    /*cout << "Press Enter to Continue . . .";
                    cin.ignore();  
                    clear();*/
                    break;
                }
            case 4:
                {
                    Adventure(monster, player, random, gear, biome);
                    break;
                }
            case 5:
                {
                    Bossing cthulu;
                    Boss(cthulu, player, random, gear, biome, playerlevel);
                    
                    break;
                }
            case 6:
                {
                    clear();
                    SaveRecord(player);
                    return 0;
                    break;
                }
            default:
                {
                    clear();
                    cout << "That is not an option!\n" << endl;
                }
            
        }
    }
}

