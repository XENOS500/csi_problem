#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int success=0,failure=0;
    queue<int>q;
    stack<int> st,temp;
    int t; // no. of testcases  //no. of commands
    cin>>t;
    t++;
    int ct=0;
    int x=0;
    while(t--)
    {
       string s;
       getline(cin,s);
       
       if(s[0]=='A') 
       {
            
            x=(s[7]-'0')*100 + (s[8]-'0')*10 +(s[9]-'0')*1;
            q.push(x);
            
       }
       else if(s[0]=='P')
       {
        st.push(q.front());
        q.pop();
            
       }
       else if(s[0]=='D')
       {
        int y=0;
        y= (s[8]-'0')*100 +(s[9]-'0')*10 + (s[10] - '0')*1;
        int flag=0;
        while(!st.empty()){
            if(st.top()==y){
                flag=1;
                success++;
                st.pop();
                break;
            }
            else {
                temp.push(st.top());
                st.pop();
            }
        }
        ct+=temp.size();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        if(!flag) failure++;
       }

    }

    cout<<success<<" "<<ct<<" "<<failure;


}