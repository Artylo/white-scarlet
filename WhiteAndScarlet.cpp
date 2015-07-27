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
void set_owner_castle(CASTLE castle[])
{
    string src;

    cout << "[castle/player]: ";
    cin  >> src;

    for(int i = 0; i < castleNum; i++)
    {
        if(castle[i].name == src)
        {
            cin  >> castle[i].owner;
            if(castle[i].owner != " ") cout << castle[i].name << " is now under " << castle[i].owner << "'s rule" << endl;
            else
            {
                castle[i].owner = " ";
                cout << castle[i].name << " has fallen under anarchy" << endl;
            }
        }
    }
}
void set_owner_town(TOWN town[])
{
    string src;

    cout << "[town/player]: ";
    cin  >> src;

    for(int i = 0; i < townNum; i++)
    {
        if(town[i].name == src)
        {
            cin  >> town[i].owner;
            if(town[i].owner != " ") cout << town[i].name << " is now under " << town[i].owner << "'s rule" << endl;
            else
            {
                town[i].owner = " ";
                cout << town[i].name << " has fallen under anarchy" << endl;
            }
        }
    }
}
void money_distribute(CASTLE castle[], TOWN town[], PLAYER player[])
{
    /*
    //Castles
    for(int i = 0; i < castleNum; i++)
    {
        for(int j = 0; j < players; j++)
        {
                if(castle[i].owner == player[j].name)
                {
                    player[j].gold += castle[i].income;
                    cout << player[j].name << " gains " << castle[i].income << " gold from castle " << castle[i].name << endl;
                }
        }
    }
    */

    //Towns
    for(int i = 0; i < townNum; i++)
    {
        for(int j = 0; j < players; j++)
        {
            if(town[i].owner == player[j].name)
            {
                player[j].gold += town[i].income;
                cout << player[j].name << " gains " << town[i].income << " gold from the town of " << town[i].name << endl;
            }
        }
    }
}
void army_distribute(CASTLE castle[], TOWN town[], PLAYER player[])
{
    //Castles
    string place, reciever;
    int kind, quantity;
    cout << "[castle/general/kind/quantity]: ";
    cin  >> place >> reciever >> kind >> quantity;
    for(int i = 0; i < castleNum; i++)
    {
        if(castle[i].name == place)
        {
            for(int j = 0; j < players; j++)
            {
                for(int h = 0; h < 4; h++)
                {
                    if(player[j].general[h].name == reciever)
                    {
                        player[j].general[h].x[kind-1] += quantity;
                        player[j].gold -= quantity*kind;
                        cout << player[j].general[h].name << " has received " << quantity << " type " << kind << " reinforcements" << endl;
                    }
                }
            }
        }
    }

    cin.ignore(1000,'\n');
}
void print_castles(CASTLE castle[])
{
    for(int i = 0; i < castleNum; i+=2)
    {
        if(i+1 < castleNum)
        {
            cout << castle[i].name << " - " << castle[i].owner << " || ";
            cout << castle[i+1].name << " - " << castle[i+1].owner << endl;
        }
        else cout << castle[i].name << " - " << castle[i].owner << endl;
    }
}
void print_towns(TOWN town[])
{
    for(int i = 0; i < townNum; i+=2)
    {
        if(i+1 < townNum)
        {
            cout << town[i].name << " - " << town[i].owner << " || ";
            cout << town[i+1].name << " - " << town[i+1].owner << endl;
        }
        else cout << town[i].name << " - " << town[i].owner << endl;
    }
}
void print_players(CASTLE castle[], TOWN town[], PLAYER player[])
{
    for(int i = 0; i < players; i++)
    {
        cout << endl << player[i].name << endl;
        cout << "Gold: " << player[i].gold << endl << endl;

        //Generals
        for(int j = 0; j < 4; j++)
        {
            cout << player[i].general[j].name << endl;
            for(int ster = 0; ster < player[i].general[j].stars; ster++) cout << "*";
            cout << endl;

            for(int h = 0; h < 5; h++)
            {
                cout << "x" << h+1 << ": " << player[i].general[j].x[h] << " | ";
            }
            cout << endl << endl;
        }

        cout << "Owner of the towns of: ";
        for(int t = 0; t < townNum; t++) if(town[t].owner == player[i].name) cout << town[t].name << " ";
        cout  << endl << "Owner of the castles of: ";
        for(int c = 0; c < castleNum; c++) if(castle[c].owner == player[i].name) cout << castle[c].name << " ";
        cout << endl << endl;
    }
}
void set_blessing()
{

}
void set_turn(int &TURN)
{
    TURN++;
    if(TURN == 5) TURN = 1;

    switch(TURN)
    {
    case 1:
        cout << "THE FIRST PHASE HAS STARTED"  << endl;
        break;
    case 2:
        cout << "THE SECOND PHASE HAS STARTED" << endl;
        break;
    case 3:
        cout << "THE THIRD PHASE HAS STARTED"  << endl;
        break;
    case 4:
        cout << "THE FOURTH PHASE HAS STARTED" << endl;
        break;
    default:
        cout << "I don't know what turn it is, call the programmer ;~;" << endl;
        break;
    }
    set_blessing();
}

/*MAINS*/
void init_players(PLAYER player[])
{
    //First owned castle, stars, gold, armies
    player[0].name = "Lancaster";
    player[1].name = "York";
    player[2].name = "Nevil";
    player[3].name = "Wales";
    for(int i = 0; i < players; i++)
    {
        if(player[i].name == "Lancaster")
        {
            player[i].gold = 100;
            player[i].general[0].name = "HenryIV";
            player[i].general[0].stars = 2;
            player[i].general[0].x[0] = 1;
            player[i].general[0].x[1] = 1;
            player[i].general[0].x[2] = 1;
            player[i].general[0].x[3] = 1;
            player[i].general[0].x[4] = 1;

            player[i].gold = 100;
            player[i].general[1].name = "EdwardWales";
            player[i].general[1].stars = 4;
            player[i].general[1].x[0] = 1;
            player[i].general[1].x[1] = 1;
            player[i].general[1].x[2] = 1;
            player[i].general[1].x[3] = 1;
            player[i].general[1].x[4] = 1;

            player[i].gold = 100;
            player[i].general[2].name = "Margaret";
            player[i].general[2].stars = 3;
            player[i].general[2].x[0] = 1;
            player[i].general[2].x[1] = 1;
            player[i].general[2].x[2] = 1;
            player[i].general[2].x[3] = 1;
            player[i].general[2].x[4] = 1;

            player[i].gold = 100;
            player[i].general[3].name = "JohnVere";
            player[i].general[3].stars = 3;
            player[i].general[3].x[0] = 1;
            player[i].general[3].x[1] = 1;
            player[i].general[3].x[2] = 1;
            player[i].general[3].x[3] = 1;
            player[i].general[3].x[4] = 1;
        }
        if(player[i].name == "York")
        {
            player[i].gold = 100;
            player[i].general[0].name = "RichardPlantagenet";
            player[i].general[0].stars = 4;
            player[i].general[0].x[0] = 1;
            player[i].general[0].x[1] = 1;
            player[i].general[0].x[2] = 1;
            player[i].general[0].x[3] = 1;
            player[i].general[0].x[4] = 1;

            player[i].gold = 100;
            player[i].general[1].name = "EdwardY";
            player[i].general[1].stars = 4;
            player[i].general[1].x[0] = 1;
            player[i].general[1].x[1] = 1;
            player[i].general[1].x[2] = 1;
            player[i].general[1].x[3] = 1;
            player[i].general[1].x[4] = 1;

            player[i].gold = 100;
            player[i].general[2].name = "George";
            player[i].general[2].stars = 3;
            player[i].general[2].x[0] = 1;
            player[i].general[2].x[1] = 1;
            player[i].general[2].x[2] = 1;
            player[i].general[2].x[3] = 1;
            player[i].general[2].x[4] = 1;

            player[i].gold = 100;
            player[i].general[3].name = "RichardG";
            player[i].general[3].stars = 5;
            player[i].general[3].x[0] = 1;
            player[i].general[3].x[1] = 1;
            player[i].general[3].x[2] = 1;
            player[i].general[3].x[3] = 1;
            player[i].general[3].x[4] = 1;
        }
        if(player[i].name == "Nevil")
        {
            player[i].gold = 100;
            player[i].general[0].name = "RichardNevil";
            player[i].general[0].stars = 4;
            player[i].general[0].x[0] = 1;
            player[i].general[0].x[1] = 1;
            player[i].general[0].x[2] = 1;
            player[i].general[0].x[3] = 1;
            player[i].general[0].x[4] = 1;

            player[i].gold = 100;
            player[i].general[1].name = "Catesby";
            player[i].general[1].stars = 3;
            player[i].general[1].x[0] = 1;
            player[i].general[1].x[1] = 1;
            player[i].general[1].x[2] = 1;
            player[i].general[1].x[3] = 1;
            player[i].general[1].x[4] = 1;

            player[i].gold = 100;
            player[i].general[2].name = "Seward";
            player[i].general[2].stars = 3;
            player[i].general[2].x[0] = 1;
            player[i].general[2].x[1] = 1;
            player[i].general[2].x[2] = 1;
            player[i].general[2].x[3] = 1;
            player[i].general[2].x[4] = 1;

            player[i].gold = 100;
            player[i].general[3].name = "Arthur";
            player[i].general[3].stars = 3;
            player[i].general[3].x[0] = 1;
            player[i].general[3].x[1] = 1;
            player[i].general[3].x[2] = 1;
            player[i].general[3].x[3] = 1;
            player[i].general[3].x[4] = 1;
        }
        if(player[i].name == "Wales")
        {
            player[i].gold = 100;
            player[i].general[0].name = "Owayn";
            player[i].general[0].stars = 4;
            player[i].general[0].x[0] = 1;
            player[i].general[0].x[1] = 1;
            player[i].general[0].x[2] = 1;
            player[i].general[0].x[3] = 1;
            player[i].general[0].x[4] = 1;

            player[i].gold = 100;
            player[i].general[1].name = "Llewelyn";
            player[i].general[1].stars = 4;
            player[i].general[1].x[0] = 1;
            player[i].general[1].x[1] = 1;
            player[i].general[1].x[2] = 1;
            player[i].general[1].x[3] = 1;
            player[i].general[1].x[4] = 1;

            player[i].gold = 100;
            player[i].general[2].name = "Gryffydd";
            player[i].general[2].stars = 2;
            player[i].general[2].x[0] = 1;
            player[i].general[2].x[1] = 1;
            player[i].general[2].x[2] = 1;
            player[i].general[2].x[3] = 1;
            player[i].general[2].x[4] = 1;

            player[i].gold = 100;
            player[i].general[3].name = "HenryTudor";
            player[i].general[3].stars = 3;
            player[i].general[3].x[0] = 1;
            player[i].general[3].x[1] = 1;
            player[i].general[3].x[2] = 1;
            player[i].general[3].x[3] = 1;
            player[i].general[3].x[4] = 1;
        }
    }
}
void command()
{
    srand(time(0));
    int TURN = 0;

    PLAYER player[players];
    /*
    for(int i = 0; i < players; i++)
    {
        cout << "PLAYER[" << i+1 << "/" << players << "]: ";
        cin >> player[i].name;
    }
    */
    TOWN town[townNum];
    for(int i = 0; i < townNum; i++)
    {
        cout << "TOWN[" << i+1 << "/" << townNum << "]:";
        cin  >> town[i].name;
        /*
        bool hasOwner;
        cout << "Does it have an owner?: ";
        cin >> hasOwner;
        if(hasOwner)
        {
            cout << towns[i].name << "'s owner (type for none): ";
            cin >>
        }
        */
    }
    CASTLE castle[castleNum];
    for(int i = 0; i < castleNum; i++)
    {
        cout << "CASTLE[" << i+1 << "/" << castleNum << "]:";
        cin  >> castle[i].name;
    }

    init_players(player);

    string option = "start";
    system("CLS");
    cin.ignore(1000,'\n');
    do
    {
        /*COMMANDS*/
        if(option == "turn") set_turn(TURN);
        else if(option == "start") cout << "Welcome to White & Scarlet. Input TURN, to start the game. (? or help)" << endl;

        //Castle Commands
        else if(option == "castle owner")
        {
            set_owner_castle(castle);
            cin.ignore(1000,'\n');
        }
        else if(option == "castle show")  print_castles(castle);

        //Town Commands
        else if(option == "town owner")
        {
            set_owner_town(town);
            cin.ignore(1000,'\n');
        }
        else if(option == "town show")    print_towns(town);

        //Player Commands
        else if(option == "players gold") money_distribute(castle,town,player);
        else if(option == "players army") army_distribute(castle,town,player);
        else if(option == "players show") print_players(castle,town,player);

        //Help Commands
        else if(option == "help" || option == "?")
        {
            cout << "List of current commands:"<< endl;
            cout <<
                 "help or ?    -> Shows help screen and list of commands\n" <<
                 "quit         -> Exits the game\n" <<
                 "turn         -> Sets the game to the next turn\n" <<
                 "castle owner -> Sets the new owner of a castle\n" <<
                 "castle show  -> Shows the names and owners of all the castles\n" <<
                 "town owner   -> Sets the new owner of a castle\n" <<
                 "town show    -> Shows the names and owners of all the towns\n" <<
                 "players gold -> Calculates and displays player gold income\n" <<
                 "players army -> Calculates and displays player army growth\n" <<
                 "players show -> Shows player stats, including owned castles and towns\n" <<
                 //"\n" <<
                 endl;
        }
        else cout << "Unknown command" << endl;

        cout << ">";
        getline(cin,option);
    }
    while(option != "quit");

}
int main()
{
    command();
    return 2318008;
}
