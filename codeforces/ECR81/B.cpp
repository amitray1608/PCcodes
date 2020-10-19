#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frr(i,a,b) for(int i=b-1;i>=a;i--)
#define mod 1000000007
#define pb push_back
#define son ll t; cin>>t;while(t--)
#define fst ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main()
{
	fst
	son
	{
	    bool ar[26]={0},ar1[26]={0};
	    string a,b;
	    cin>>a>>b;
	    int n=a.size();
	    int m=b.size();
	    fr(i,0,n)
	    {
	        ar[a[i]-'a']=1;
	    }

	    fr(i,0,m)
	    {
	        ar1[b[i]-'a']=1;
	    }
	    bool flag=0;
	    fr(i,0,26)
	    {
	        if(ar1[i]==1&&ar[i]==0)
                flag=1;
	    }
	    if(flag==1)
            {cout<<-1<<endl;continue;}
            vector<int>s[26];

            fr(i,0,n)
            {
                s[a[i]-'a'].pb(i);
            }
            int g=-1,c=0;
            fr(i,0,m)
            {
                vector<int>::iterator it,it1=s[b[i]-'a'].begin();
                int y=0;
                for(it=s[b[i]-'a'].begin();it!=s[b[i]-'a'].end();it++)
                {
                     if(g<*it)
                       {
                           y=1;
                          g=*it;continue;
                       }

                }
                if(y==0)
                {
                    c++;g=*it1;
                }
            }
            cout<<c+1<<endl;


	}
}
