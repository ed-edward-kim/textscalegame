#include <iostream>
#include <string>
#include "Biome.h"

using namespace std;

Biome::Biome()
{
    firebiome = false;
    windbiome = false;
    waterbiome = false;
    landbiome = false;
}

void Biome::setBiome(int biometype)  //decided with a random number function
{
    if (biometype = 1)
    {
        firebiome = true;
        windbiome = false;
        waterbiome = false;
        landbiome = false;
    }
    else if (biometype = 2)
    {
        firebiome = false;
        windbiome = true;
        waterbiome = false;
        landbiome = false;
    }
    else if (biometype = 3)
    {
        firebiome = false;
        windbiome = false;   
        waterbiome = true;
        landbiome = false;
    }
    else if (biometype = 4)
    {
        firebiome = false;
        windbiome = false;   
        waterbiome = false;
        landbiome = true;
    }
    
    
}

string Biome::getBiome(int biomenumber)
{
    if (biomenumber == 1)
    {
        return "Fire";
    }
    else if (biomenumber == 2)
    {
        return "Wind";
    }
    else if (biomenumber == 3)
    {
        return "Water";
    }
    else if (biomenumber == 4)
    {
        return "Land";
    }
}