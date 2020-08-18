#ifndef BIOME_H
#define BIOME_H

using namespace std;

//used for deciding which kind of biome you come across / goto
class Biome
{
    public:
        Biome(); //default constructor
        void setBiome(int biometype);
        string getBiome(int biomenumber);
    
    private:
    //set to false until a random number assigns where you go
        bool firebiome;  //1
        bool windbiome;  //2
        bool waterbiome; //3
        bool landbiome;  //4
        
};



#endif