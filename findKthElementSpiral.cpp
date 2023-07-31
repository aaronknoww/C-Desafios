//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
//TERMINADO Y PASO LOS 1121 CASOS DE GFG
class Solution
{
    private:
    
    
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int row = 0;
        int col = 0;
        int cont = 0;
        int top = 0, bottom = n;
        int left = 0, right = m;
        
        bool reverse = false;

        if(k==1)
            return a[0][0];
        
        while(cont < k)
        {
            //horizontal
            for(int i = 0; i < abs(right - left); i++)
            { 
                //0 1 2
                //
                if(++cont == k)
                    return a[row][col];
                col += (reverse) ? -1 : 1;
                
            }
            
            if(reverse)
            {
                bottom--;
                row--;
                col++;
            }
            else
            {
                top++;
                row++;
                col--;
            }

            //vertical
            for(int i = 0; i < abs(bottom - top); i++)
            {
                if(++cont == k)
                    return a[row][col];                
                row += (reverse) ? -1 : 1;
            }
            if(reverse)
            {
                left++;
                col++;
                row++;
            }
            else
            {
                right--;
                col--;
                row--;
            }
            reverse = !reverse;

        }
        return -100;        
       // Your code goes here.
    }
};

/*
1
3 3 9
1 2 3 
4 5 6 
7 8 9
*/



//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}