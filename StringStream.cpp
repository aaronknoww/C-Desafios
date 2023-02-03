#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> parseInts(string str)
{

    
    stringstream cad(str);
    vector<int> ent;
    int t = 0;
    char c;    
    while (true )
    {
        if( cad >> t )
        {
            ent.push_back(t);
            cad >> c;
        }        
        else
            break;        
    }
    return ent;
}

int main() {
    string str;
    cin >> str;
    if(str.length() > 800000 )
        return 0;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}