#include "crown.h"

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
