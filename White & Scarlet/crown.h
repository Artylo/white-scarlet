#ifndef CROWN_H
#define CROWN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

/*GLOBALS*/
const int players = 4;
const int tiles   = 5;
const int townNum   = tiles * 20/100;
const int castleNum = tiles * 30/100;

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
//Castle
void print_castles(CASTLE castle[]);
void set_owner_castle(CASTLE castle[]);

//Town
void print_towns(TOWN town[]);
void set_owner_town(TOWN town[]);

//Army
void army_add(CASTLE castle[], TOWN town[], PLAYER player[]);
void army_remove(CASTLE castle[], TOWN town[], PLAYER player[]);

#endif // CROWN_H
