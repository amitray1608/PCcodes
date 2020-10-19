#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define ll long long
#define test(t) ll int t; cin>>t; while(t--)
#define F(i,L,R) for(ll int i=L;i<R;i++)
#define F2(i,L,R) for(ll int i=L;i>=R;i--)
#define get1(a) ll int a; cin>>a;
#define get2(a,b) ll int a,b; cin>>a>>b;
#define get3(a,b,c) ll int a,b,c; cin>>a>>b>>c;
#define pb push_back
#define mp make_pair
#define MAX 1000000001
using namespace std;



int main()
{ 
 

 ios_base::sync_with_stdio(0);

 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif

 test(t)
 {
 	get2(n,k);
 	
    string s=string(n,'a');
    int a=( 3 + sqrt(8*k - 7) ) / 2 ;
    int b;
    

    int x = (int)floor((-1 + sqrt(1 + 8 * k - 8)) / 2); 
  
    int base = (x * (x + 1)) / 2 + 1; 
  
    b = k - base + 1; 
    
    s[a-1]='b';
    s[b-1]='b';
 	for(int i=s.length()-1;i>=0;i--)
        {
           cout<<s[i];
         }

   cout<<"\n";
 }

  return 0;
 
}
