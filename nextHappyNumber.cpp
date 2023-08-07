//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// TERMINADO Y PASO LOS 1110 CASOS DE GFG

// } Driver Code Ends
class Solution
{
public:
    int nextHappy(int N)
    {
        int n = N + 1;
        unordered_set<int> unique; // to store every result
        unordered_set<int>::iterator itUni;
        int res = 0;
        int number = n;
        

        while(res != 1)
        {
            if( number == 7 )
            {
                res = 1;
                break;
            }
            if(number==2 || number==4 || number==8 || number==3 || number==9 || number==5 || number==6)
            {
                n++;
                number = n;
                res = 0;
                continue;                
            }
            res = 0;
            while(number > 0)
            {
                res += (number % 10) * (number % 10);
                number/=10;                
            }
            number = res;
            if(unique.insert(res).second == false)
            {
                // Enter here because it tray to insert a repeated number.
                n++;
                number = n;
                res = 0;
            }            
            
        }

        return n;
        
        // code here
    }
};
/*

1
10

*/
//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends          