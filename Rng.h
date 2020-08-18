#ifndef RNG_H
#define RNG_H
using namespace std;

class Rng
{
    public:
        Rng(); //default constructor
        void setRandom_Num();
        int getRandom_Num();
        
        void setCriticalHit(); //(critical hit probability)
        int getCriticalHit(int playerlevel);

        void setMiss();
        int getMiss();
        
        void setDefenceChance();
        int getDefenceChance();
        
        int getRandomEvent();
        
        int runAway(int playerhealth);
        //void setProbability
        //int getProbability
        
    private:
        bool criticalhit; 
        bool miss;
        bool runchance;
  
};



#endif