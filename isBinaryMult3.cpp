//{ Driver Code Starts

//TERMINADO Y PASO LOS 1120 CASOS DE GFG

/*
PARA SABER SI ES DIVIBLE ENTRE 3, EL SE DEBEN CONTAR LOS UNOS 
QUE ESTEN EN POSICION PAR Y EN POSICION IMPAR, DESPUES SE RESTAN Y SI EL RESULTADO ES DIVISIBLE ENTRE 3, ES UN MULTIPLO DEL MISMO.
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s)
	{
	    int i=0, odd = 0, eve = 0;
	    
	    for(string::reverse_iterator it = s.rbegin();  it != s.rend(); it++ )
	    {
	        if(*it == '1')
	        {
	            if(i % 2 == 0)
	                eve++;
	            else
	                odd++;
	        }
	        i++;
	    }
	    return (odd - eve)%3 == 0;
	    //complete the function here
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends