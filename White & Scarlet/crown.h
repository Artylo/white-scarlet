#ifndef CROWN_H
#define CROWN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

/*STRUCTURES*/
struct GENERAL
{
    string name;
    int stars = 2;
    int army  = 100;
    int x[5] = {0,0,0,0,0}; //Infantry//Cavalry//Archers//Artillery//Ships
};
struct PLAYER
{
    string name;
    GENERAL general[4];
    int gold = 0;

};
struct TOWN
{
    string name   = " ";
    string owner  = " ";
    int armour    = 1;
    //int capacity  = 800;
    int income    = 400;
    //int training = 100;
    //int trainCost = 2;
};
struct CASTLE
{
    string name  = " ";
    string owner = " ";
    int armour = 2;
    //int capacity = 200;
    //int income   = 40;
    int training = 100;
    int trainCost = 2;
};

/*FUNCTIONS*/
void matey();

#endif // CROWN_H
