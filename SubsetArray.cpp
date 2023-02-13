//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// NO PASA EL CASO 109 GFG

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m)
{
    
    unordered_multiset<int> hashT; // ordena y quita repetidos.
    unordered_multiset<int>::iterator res;   

    if( n>=m )
    {
        for (int i = 0; i < n; i++)
            hashT.insert(a1[i]);
        
        for (int i = 0; i < m; i++)
        {
            res = hashT.find(a2[i]);
            if( res == hashT.end())
                return "No";
            hashT.erase(res); // TODO: REVISAR QUE SOLO BORRE 1
            
        }
        return "Yes";
        
    }
    else
    {
        
        for (int i = 0; i < m; i++)
            hashT.insert(a2[i]);

        for (int i = 0; i < n; i++)
        {
            res = hashT.find(a1[i]);
            if(res == hashT.end())
                return "No";
            hashT.erase(res);
        }
        return "Yes";

    }
}

/*
1
6 4
11 1 13 21 3 7
11 3 7 1
Yes

1
8 4
1 2 3 4 5 6 7 8
1 2 3 1
NO

1
9 4
1 1 2 3 4 5 6 7 8
1 2 3 1

1
4 8
1 2 3 1
1 2 3 4 5 6 7 8
NO

1
4 9
1 2 3 1
1 1 2 3 4 5 6 7 8
*/