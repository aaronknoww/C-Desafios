#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t = 0;
	cin>>t;
	if(t<1 || t > 1000)
	    return 0;
	    
	char ship[t];
	try
    {
        
        for (int i = 0; i < t; i++)
            cin >> ship[i];
        
       
    }
    catch(const std::exception& e)
    {
        return 0;
    }
	for (int i = 0; i < t; i++)
	{
	    
    	switch (ship[i])
        {
        case 'b':
            cout<<"BattleShip\n";
            break;
        case 'B':
            cout<<"BattleShip\n";
            break;
        case ('c'):
            cout<<"Cruiser\n";
             break;
        case ('C'):
            cout<<"Cruiser\n";
             break;
        case ('d'):
            cout<<"Destroyer\n";
             break;
        case ('D'):
            cout<<"Destroyer\n";
             break;
        case ('f' || 'F'):
            cout<<"Crusier\n";
             break;
        case ('F'):
            cout<<"Crusier\n";
             break;
        default:
            return 0;
        }
	}
	return 0;
}
