#include <string>
#include <iostream>
#include "Bossing.h"

using namespace std;

Bossing::Bossing()
{
    boss_name = "";
    boss_hp = 0;
    boss_defence = 0;
    boss_attack = 0;
}

//Boss name
void Bossing::setBoss_Name(string bossname)//param
{
    boss_name = bossname;
}

string Bossing::getBoss_Name()
{
    return boss_name;
}

//Boss HP
void Bossing::setBoss_Hp(int bosshp)//param
{
    boss_hp = bosshp;
}

int Bossing::getBoss_Hp()
{
    return boss_hp;
}

//Boss Defence
void Bossing::setBoss_Defence(int bossdefence)//param
{
    boss_defence = bossdefence;
}

int Bossing::getBoss_Defence()
{
    return boss_defence;
}

void Bossing::setBoss_Attack(int bossatk)
{
    boss_attack = bossatk;
}

int Bossing::getBoss_Attack()
{
    return boss_attack;
}

void Bossing::setBoss_Stats()
{
    setBoss_Name("Cthulhu");
    setBoss_Hp(666);
    setBoss_Defence(15);
    setBoss_Attack(20);
}