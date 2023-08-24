//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
  private:
  
  int toInt(char n)
  {
    if(n == '-') return 0;  
    if(n == '0') return 0;
    if(n == '1') return 1;
    if(n == '2') return 2;
    if(n == '3') return 3;
    if(n == '4') return 4;
    if(n == '5') return 5;
    if(n == '6') return 6;
    if(n == '7') return 7;
    if(n == '8') return 8;
    if(n == '9') return 9;

    return 0;
  }

  string toStr(int n)
  {    
    if(n == 0) return "0";
    if(n == 1) return "1";
    if(n == 2) return "2";
    if(n == 3) return "3";
    if(n == 4) return "4";
    if(n == 5) return "5";
    if(n == 6) return "6";
    if(n == 7) return "7";
    if(n == 8) return "8";
    if(n == 9) return "9";

    return "0";
  }


  public:

    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
      string ans;
      long res = 0;
      int n1 = 0;
      int n2 = 0;
      int m=1;
      int dist = (s1.size() >= s2.size()) ? s1.size() : s2.size();
      int it1 = s1.size()-1;
      int it2 = s2.size()-1;      

      for (int i = 0; i < dist; i++)
      {
        if (it1 >= 0)
        {
          n1 += toInt(s1[it1]) * m;
          it1--;
          
        }
        if (it2 >= 0)
        {
          n2 += toInt(s2[it2]) * m;
          it2--;
          
        }
        m*=10;        
      }


      res = n1 * n2;

      if(res==0)
        return ans+="0";

      while (res > 0)
      {
        ans = toStr(res%10) + ans; 
        //ans.push_back(toChar(res%10));
        res/=10;
        /* code */
      }
      n1 = (s1[0]=='-') ? n1 * -1 : n1;
      n2 = (s2[0]=='-') ? n2 * -1 : n2;
      if(n1 * n2 > 0)
        return ans;
      else
        return ans="-" + ans;
       //Your code here
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends