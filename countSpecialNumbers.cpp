//{ Driver Code Starts
// Initial Template for C++

//COUNT SPECIAL NUMBERS
// TERMINADO Y PASO 1114 CASOS DE GFG

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// 1.- Crear un arbol ordenado para guardar el numero como clave y sus repeticiones como valor.
// 2.- Iterar y cada elemento de menor a mayor.
// 3.- Cada vez que se cumpla la condicion, borrar ese elemento 

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr)
    {
        map<int,int> mp;
        short ones = 0;
        for(int el : arr)
        {
            if(el == 1 && ones > 1)
                return N;
            if(el == 1)
                ones++;

            pair<map<int,int>::iterator, bool> res;
            res = mp.insert({el, 1}); // After insert the method return a pair.

            if(res.second == false)
               res.first->second = res.first->second + 1;  // Because the first element of pair is an iterator, an is pointing to the element with the same key of el;
        }

        if(ones == 1)
            return N-1;

        int counter = 0;
        int debtam = mp.size();

        // To check, count and delete each time the condition is met   
        for (map<int,int>::iterator firstElem = mp.begin(); firstElem != mp.end();)
        {
            for(map<int,int>::iterator it = ++mp.begin(); it != mp.end();)
            {
                int deb = it->first;
                if(it->first % firstElem->first == 0)
                {
                    if(it->second > 1)
                        counter += it->second;
                    else
                        counter++;
                    it = mp.erase(it);
                }
                else
                    ++it;
            }               
            if(firstElem->second > 1)
            {
                counter += firstElem->second;                
            }
            firstElem = mp.erase(mp.begin());
        }
        if(mp.rbegin()!= mp.rend() && mp.rbegin()->second > 1)
             counter+= mp.rbegin()->second;
        return  counter;
        // Code here
    }
};

/*
1
6
1 1 1 1 1 1

1 
6
3 5 5 5 5 5

1
3
2 4 6

1
2
*/
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends