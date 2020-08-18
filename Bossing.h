#ifndef BOSSING_H
#define BOSSING_H

using namespace std;

class Bossing
{
    public:
        Bossing(); //defalt constructor might not need
        
        void setBoss_Name(string bossname);
        string getBoss_Name();
        
        void setBoss_Hp(int bosshp);
        int getBoss_Hp();
        
        void setBoss_Defence(int bossdefence);
        int getBoss_Defence();
        
        void setBoss_Attack(int bossattack);
        int getBoss_Attack();
        
        void setBoss_Stats();
     //set each boss individually? 1-10
     
    private:
        string boss_name;
        int boss_hp;
        int boss_defence;
        int boss_attack;

};



#endif