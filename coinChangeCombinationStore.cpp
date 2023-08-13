// CoinChange.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//{ Driver Code Starts
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;
// } Driver Code Ends
class Solution {
public:
    long long int count(int coins[], int N, int sum)
    {

        set<int> ordCoins(coins, coins + N);// To create a set and order every coin and remove duplicates
        set<int>::iterator itCoin = ordCoins.begin();
        unordered_map<int, set<int>> tbl;
        unordered_map<int, set<int>>::iterator itTbl;
        pair<unordered_map<int, set<int>>::iterator, bool> result;


        int counter = 0;
        if (N == 0 || sum < *ordCoins.begin())
            return 0;

        set<int> auxCode;
        int db = *ordCoins.begin();

        for (int s = *ordCoins.begin(); s <= sum; s++)// to find every combination for sum 0 to sum n
        {

            if (ordCoins.find(s) != ordCoins.end())
                auxCode.insert(s);

            while ( itCoin != ordCoins.end() && *itCoin < s )// to do every rest of coins sum - coin[0], sum - coin[1]...
            {
                if ((s - *itCoin) < *itCoin)
                {
                    itCoin++;
                    continue;
                }
                itTbl = tbl.find(s - *itCoin);
                if (itTbl != tbl.end())
                {

                    for (set<int>::iterator it = itTbl->second.begin(); it != itTbl->second.end(); it++)
                    {
                        auxCode.insert(mergeCoin(*itCoin, *it));
                        counter++;
                    }

                }
                itCoin++;
            }
            if (!auxCode.empty())
            {
                result = tbl.insert({ s,auxCode });
                auxCode.clear();
            }
            itCoin = ordCoins.begin();

        }

        return result.first->second.size();



        // code here.
    }

private:
    int mergeCoin(int coin, long long int codigo)
    {
        multiset<int> setCoin;
        long long int result = 0;
        long long int mul = 1;


        while (codigo > 0)
        {
            setCoin.insert(codigo % 10);
            codigo -= codigo % 10;
            codigo = codigo / 10;
        }
        setCoin.insert(coin);
        for (multiset<int>::reverse_iterator ite = setCoin.rbegin(); ite != setCoin.rend(); ite++)
        {
            result += *ite * mul;
            mul *= 10;
        }
        return result;

    }
};
//{2,5,3,6}
/*
1
7 3
2 4 6

1
4 10
2 5 3 6
*/

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, no;
        int const N = 4;
        cin >> no>> sum;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends