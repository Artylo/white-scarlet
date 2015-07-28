#include "crown.h"

void army_add(CASTLE castle[], TOWN town[], PLAYER player[])
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

void army_remove(CASTLE castle[], TOWN town[], PLAYER player[])
{
    string reciever;
    int kind, quantity;
    cout << "[general/kind/quantity]: ";
    cin  >> reciever >> kind >> quantity;

    for(int i = 0; i < players; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(player[i].general[j].name == reciever)
            {
                player[i].general[j].x[kind-1] -= quantity;
                cout << quantity << " type " << kind << " units have been removed from " << reciever << "'s forces" << endl;
            }
        }
    }
    cin.ignore(1000,'\n');
}
