#ifndef STATS_H
#define STATS_H

using namespace std;

class Stats
{
    public:
        Stats(); //default constructor
        
        //name
        void setName(string charname);
        string getName();
        
        //health
        int getMaxHealth();  //max health
        void setHealth(int healthvalue); //sets health
        int getHealth();
        
        //money
        void setMoney(int moneyvalue); //sets money
        int getMoney();
        
        //stamina
        int getMaxStamina();
        void setStamina(int staminavalue);       //if < certainpoint, start losing hp
        int getStamina();
        
        //level
        void setLevel(int levelvalue); //sets level
        int getLevel();
        
/*        //strength
        void setPower(int powervalue);
        int getPower();
        */
        //experience
        void ExperienceNeeded();
        void setExperience(int experiencevalue, int playerlevel); //sets experience with values of a int and the player's level
        int getExperience(); //current experience
        int getMaxExperience(); //experience needed to level
        
    private:
        string charactername;
        int health; //this health is for battle
        int maxhealth; //this health is for the maximum amount of health you can have.
        int money;
        int stamina;
        int maxstamina;
        int level;
        //int power;
        
        int experience;
        int maxexperience;
        
        
        
        //money X
        //
        //rng biome X
        //rng events maybe? (all spaghetti falls out of your pockets)
        //resitances to certain elements (class or stats) //get from a gear class? 
        //bosses class X
        //gearing class X
        //items? (file io?) X
        //stamina deteriorates with time and then eats into your hp. X(write stamina code)
        
        
            //Cant display an actual map []
            
        //Home, press whatever to go blank ->    X   (make menus)
            //forward (options to go back to go home) X 
            //(afer certain point, get a boss (finite options))
                //pokemon esque, vs certain bosses at certain places?
        //
};

#endif