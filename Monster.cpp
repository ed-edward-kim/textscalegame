#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Monster.h"

using namespace std;

Monster::Monster()
{
    srand(time(0));
    
    //fill the Monsters array
    string monstername = "";
    string monsterhp = "";
    string monsteratk = "";
    string monsterdef = "";
    int i = 0;
    ifstream monsters;
    monsters.open("monsters.txt");
    while(!(monsters.eof()))          //for (int i = 0; i < 27; i++)
    {
        //fills monster_name[]
        getline(monsters, monstername, ',');
        monster_list[i] = monstername;
        //cout << "Monstername: " << monstername;
        
        //fills monster_hp[]
        getline(monsters, monsterhp, ',');
        monster_hp[i] = stoi(monsterhp);
        //cout << " | MonsterHP: " << monsterhp;
        
        //fills monster attack 
        getline(monsters, monsteratk, ',');
        monster_attack[i] = stoi(monsteratk);
        //cout << " | MonsterAttack: " << monsteratk;
        
        //fills monster def
        getline(monsters, monsterdef);
        monster_defence[i] = stoi(monsterdef);
        //cout << " | MonsterDefence: " << monsterdef;
        
        i++;
    }
    monsters.close();
    i = 0;
}

//Number of monsters through random
void Monster::setMonster_Number(int number) //depends on player level. prolly need int playerlevel
{
    ;
}

int Monster::getMonster_Number()
{
    ;
}

//Monster Name
void Monster::setMonster_Name(int number)
{
    if(number > 25 || number < 1){ //dealing with seg faults
        number = 2;
    }
    monster_name = monster_list[number]; 
}

string Monster::getMonster_Name()
{
    return monster_name;
}

//Monster HP
void Monster::setMonster_Hp(int number, int playerlevel)
{
    if(number > 25 || number < 1){ //dealing with seg faults
        number = 2;
    }
    monster_health = monster_hp[number] + playerlevel;
}

int Monster::Monster_Hp(int damagetaken)
{
    monster_health = monster_health - damagetaken;
    return monster_health;
}

int Monster::getMonster_Hp()
{
    return monster_health;
}

//Monster Attack
void Monster::setMonster_Attack(int number, int playerlevel)
{
    if(number > 25 || number < 1){ //dealing with seg faults
        number = 2;
    }
    monster_attackpower = monster_attack[number] + playerlevel;
}

int Monster::getMonster_Attack()
{
    return monster_attackpower;
}

//Monster Defence
void Monster::setMonster_Defence(int number, int playerlevel)
{
    if(number > 25 || number < 1){ //dealing with seg faults
        number = 2;
    }
    monster_defencepower = monster_defence[number] + playerlevel;
}

int Monster::getMonster_Defence()
{
    return monster_defencepower;
}


void Monster::setMonster_Experience(int number, int playerlevel)
{
    if(number > 25 || number < 1){ //dealing with seg faults
        number = 2;
    }
    monster_experience = monster_hp[number] + monster_attack[number] + monster_defence[number];
}

int Monster::getMonster_Experience()
{
    return monster_experience;
}

void Monster::setMonster_Prefixes()
{
    //filling prefix array
    string prefix = "";
    
    ifstream prefixfile;
    prefixfile.open("prefixes.txt");
    for (int i = 0; i < 23; i++ )
    {
        getline(prefixfile, prefix);
        monster_prefixlist[i] = prefix;
        //cout << monster_prefixlist[i] << endl;
        i++;
    }
    
/*    int randomprefix = rand()%24;
    monster_prefix = monster_prefixlist[randomprefix];*/
    
}
string Monster::getMonster_Prefixes()
{
    int randomprefix = rand()% 24;
    monster_prefix = monster_prefixlist[randomprefix];
    return monster_prefix;
}
void Monster::setMonster_Values(int playerlevel) //int playerlevel
{
    randomnumber = rand()% 23 + 1;
    
    setMonster_Name(randomnumber);
    setMonster_Hp(randomnumber, playerlevel);
    setMonster_Attack(randomnumber, playerlevel);
    setMonster_Defence(randomnumber, playerlevel);
    setMonster_Number(playerlevel); //playerlevel
    setMonster_Prefixes();
}
