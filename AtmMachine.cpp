
#include <iostream>

using namespace std;

void testCase()
{
    int n = 0;
    int k = 0;

    cin >> n;
    if(n <1 || n > 100)
        exit(0);
    cin >> k;
    if( k < 1 || k > 1000000)
        exit(0);
    
    int withdraws[n];

    for (int i = 0; i < n; i++)
    {
        cin >> withdraws[i];
        if(withdraws[i] < 1 || withdraws[i] > 1000000)
            exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        if(k==0)
            cout<<"0 ";
        else if(withdraws[i] <= k )
        {
            k -= withdraws[i];
            cout<<"1 ";
        }
        else
            cout<<"0 ";
        
    }
          
    cout<<"\n";

}

int main()
{
    int t = 0;
    cin >> t;
    if(t<1 || t > 100 )
        return 0;

    for (int i = 0; i < t; i++)
    {
        testCase();
    }
    
     return 0;
}

/*
2
5 10
3 5 3 2 1
4 6
10 8 6 4

5 3 3 2 1
*/