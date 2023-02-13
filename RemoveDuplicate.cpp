#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 300 CASOS GFG


class Solution{
public:	
		
	string removeDups(string S) 
	{
         unordered_set<char> hashT; // ordena y quita repetidos.
         string r;
         
         hashT.insert(S.begin(), S.end());

         for (auto &&ch : S)
         {
            if(hashT.erase(ch)>0)
                r.push_back(ch);            
         }
         return r;
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends

/*
1
zvvooz
*/