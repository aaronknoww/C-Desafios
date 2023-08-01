//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 1110 CASOS DE GFG
// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills)
    {
        int b5=0;
        int b10=0;
        
        if(bills[0] > 5 || bills[1] > 10)
            return false;

        for(int i = 0; i < N; i++)
        {
            if(bills[i] == 10)
            {
                b10++;
                if(b5==0)
                    return false;
                b5--;
            }
            else if(bills[i] == 20)
            {
                if(b5==0)
                    return false;
                
                if(b10 > 0)
                {
                    b10--;
                    b5--;
                }
                else
                {
                    if(b5 < 3)
                        return false;
                    b5 -= 3;
                }
            }
            else
                b5++;
        }
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends