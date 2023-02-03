
#include<bits/stdc++.h>
using namespace std;

//PASÓ ESTÁ TERMINADO.

class Solution{
    private:
        struct posibleChamp
        {
            int farthestI;
            int arrIndex;
            posibleChamp()
            {
                farthestI = 0;
                arrIndex = 0;
            }
        };
        
  public:
    int minJumps(int arr[], int n)
    {
        int jump = 0;
        int idx = 0;
        int ini = 0;
        int fin = 0;
        posibleChamp psc;

        if(n == 1 && arr[0] !=0)
            return 1; // return 1 jump.
        else if(n == 1 && arr[0] ==0)
            return -1;
             

        //TODO: VER QUE PASA CUANDO FIN SE MAYOR QUE EL NUMERO DEL ARREGLO.

        while (arr[idx] != 0)
        {

           ini = idx + 1;
           fin = arr[idx] + idx;

           if((arr[idx] + idx) >= (n - 1) )
           {
                jump++;
                return jump;
           }

           psc.farthestI = arr[idx] + idx;
           psc.arrIndex = idx;



           //TODO: REVISAR QUE PASA SI EN EL INDICE QUE LLEGA MAS LEJOS HAY UN CERO EN EL DESTINO.

           for (int i = ini; i <= fin; i++)
           {
                if( arr[i] + i >=  psc.farthestI)
                {
                    psc.farthestI = arr[i] + i;
                    psc.arrIndex = i; 
                }            
           }

           idx = psc.arrIndex;

           jump++;
           
           if(idx >= n-1)
                return jump;

        }
        return -1;             
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends

/*
1
11
1 3 5 8 9 2 6 7 6 8 9
*/

/*
1
10
2 3 1 1 2 4 2 0 1 1

1 -> 3
2 -> 2
3 -> 4
4-> FIN
 */