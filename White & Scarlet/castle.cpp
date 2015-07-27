#include "crown.h"

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
