//SHY GEEK
// TERMINADO Y PASO LOS 1115 CASOS DE GFG


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/ 
//124579
class Solution
{
    
    Shop shop;
    unordered_set<long> chocoPrice;// all prices founded before.
    unordered_map<int,int> nVisited;
    unordered_map<int,int>::iterator Itn;
    long min;
    long max;
    bool right = true;

    long maxVal(long coin, int n)
    {
        int pivote = (n-1)/2;
        int ini = 0;
        int end = n-1;
        int ant = 0;
        int current = 0;
        int pCurr = 0;
        
        while(ini <= end)
        {
            Itn = nVisited.find(pivote);// to know if this n was visited 
            if(Itn != nVisited.end())
            {
                ant = current;
                current = Itn->second;
                pCurr = pivote;
            }
            else
            {
                ant = current;
                current = shop.get(pivote);
                pCurr = pivote;
                nVisited.insert({pivote,current});
                chocoPrice.insert(current);                
            }
            if(current == coin)
            {
                return current;
            }
            else if(coin > current)
            {
                right = true;
                ini = pivote + 1;
                pivote = (end + ini) / 2;                
            }
            else
            {
                right = false;
                end = pivote - 1;
                pivote = (end + ini) / 2;
            }
        }
        
        if(current > coin)
        {
            while(true)
            {                
                Itn = nVisited.find(pCurr-1);// check the left nighborgh 
                if(Itn != nVisited.end())
                {
                    if(Itn->second < coin)
                        return Itn->second;
                }
                else
                {
                    ini = shop.get(pCurr-1);
                    nVisited.insert({pCurr-1,ini});
                    chocoPrice.insert(ini);
                        if(ini < coin)
                            return ini;
                }                
                pCurr--;
            }
        }
        else
        {
            return current;
        }            
        
    }

public:
    Solution(Shop s)
    {
        min = 0;
        max = 0;
        this->shop = s;
    }
    long long find(int n, long k)
    {
        int min = shop.get(0);
        nVisited.insert({0,min});
        chocoPrice.insert(min);
        if(k==1 && min == 1)
            return 1;
        else if(k==1)
            return 0;
        
        int price = 0;
        int counter = 0;
        long coins = k;

        while( coins >= min )
        {
            if(chocoPrice.find(coins) != chocoPrice.end())
            {
                // It was found a chocolate with that price
                return  counter + 1;
            }
            
            price = maxVal(coins, n);
            if(price > coins || price == 0)
                return counter;
            if(price == coins)
            {
                return counter+1;
            }
            counter += coins / price;
            coins = coins % price;
        }
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        return counter;
    }

};
/*
1
4 9
1 2 3 4

1
4 5
1 2 4 9

1
4 2
1 3 4 9

1
2 2
4 6


1
3 5
2 4 6
*/

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends