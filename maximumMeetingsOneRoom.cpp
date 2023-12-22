//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// TERMINADO PERO EL COMPILADOR DE GFG ESTABA DANDO PROBLEMAS.

// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
      class Meeting
      {
      private:
            int begin;
            int end;
            int index;
      public:
            Meeting()
            {
                  begin=0;
                  end = 0;
                  index = 0;                  
            }
            Meeting(int i, int b, int e)
            {
                  this->begin = b;
                  this->end = e;
                  this->index = i;
            }
            int getBegin()
            {
                return this->begin;
            }
            int getEnd()
            {
                return this->end;
            }
            int getIndex()
            {
                return index;
            }
            bool operator<(const Meeting &item) const
            {
                  if(this->end == item.end && this->index < item.index)
                        return true;
                  if(this->end < item.end )
                        return true;
                  else
                        return false;
            }
            bool operator<=(const Meeting &item) const
            {
                  if(this->end <= item.end && this->index < item.index)
                        return true;
                  else
                        return false;
            }
            bool operator==(const Meeting &item) const
            {
                  if(this->end == item.end && this->index < item.index)
                        return true;
                  else
                        return false;
            }


      };

public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F)
    {
        vector<Meeting> meetings;
        vector<Meeting> aux;
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            meetings.push_back( Meeting(i+1, S[i],F[i]));
        }
        sort(meetings.begin(), meetings.end());
        aux.push_back(meetings[0]);
        for (int i = 0; i < N; i++)
        {
            if(meetings[i].getEnd() < meetings[i+1].getBegin())
                aux.push_back(meetings[i]);                
        }

        sort(aux.begin(), aux.end());
        for(Meeting m : aux)
        {
            res.push_back(m.getIndex());
        }
        return res;
        
    }
};

/*
1
3
5 1 3
5 3 3
*/
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends