#ifndef Monster_H
#define Monster_H

#include <string>
using namespace std;

class Monster
{
    public:
        Monster(); //default
        
        //number of monsters with random
        void setMonster_Number(int number);
        int getMonster_Number();
        
        //Monster name
        void setMonster_Name(int number);
        string getMonster_Name();
        
        //Monster Hp
        void setMonster_Hp(int number, int playerlevel);
        int Monster_Hp(int damagetaken);
        int getMonster_Hp();
        
        //Monster Attack
        void setMonster_Attack(int number, int playerlevel);
        int getMonster_Attack();
        
        
        //Monster Defence
        void setMonster_Defence(int number, int playerlevel);
        int getMonster_Defence();
    
        //get a random monster
        void setMonster_Values(int playerlevel);
        int getMonster_Values();
        
        //Monster Experience
        void setMonster_Experience(int number, int playerlevel);
        int getMonster_Experience();
        
        //Monster Prefixes
        void setMonster_Prefixes(); //fills prefix array
        string getMonster_Prefixes();
    
    private:
        
        string element;
        
        int monster_number;
        int randomnumber;
        //monster stats. [25] because there are 26 monsters in the notepad that I use.
        
        string monster_prefixlist[23]; //23 types of modifiers
        string monster_list[26];  //26 type of monsters
        int monster_hp[26];      //these all hold values that got read from a notepad. I have similar variables below that actually hold a value during a certain time in a fight.
        int monster_attack[26];
        int monster_defence[26];
        
        string monster_prefix;
        string monster_name;
        int monster_health;
        int monster_attackpower;
        int monster_defencepower;
        int monster_experience;

        
};



#endif