#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MAX 101
using namespace std;
 
typedef long long ll;

int main(){
     ll n;
     cin>>n;
     string s;
     cin>>s;
     if((n%2)!=0){
          cout<<"-1"<<endl;
          return 0;
     }
     ll cnt=0;
     ll cnt1=0;
     bool ok=true;
     for(ll i=0;i<n;i++){
          if(s[i]=='('){
          	cnt1+=1;
          }
          else if(s[i]==')' && cnt1>0){
               cnt1-=1;
          }
          else if(cnt1==0 &&  s[i]==')'){
          	ok=false;
          	break;
          }
     }
     if(ok && cnt1==0){
     	 cout<<"0"<<endl;
     	 return 0;
     }
     for(ll i=0;i<(n-1);){
            if(s[i]=='(' && s[i+1]==')'){
                 i+=2;
                 continue;  
            }
            else if(s[i]==')' && s[i+1]=='('){
                 cnt+=2;
                 s[i]='(';
                 s[i+1]=')';
                 i+=2;
            }
            else if(s[i]=='(' && s[i+1]=='('){
                 cnt+=2;
                 s[i+1]=')';
                 i+=2;
            }
            else if(s[i]==')' && s[i+1]==')'){
                 cnt+=2;
                 s[i]='(';
                 i+=2;
            }
     }
     cout<<cnt<<endl;
     return 0;
}
