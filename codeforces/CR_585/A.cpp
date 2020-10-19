#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve()
{
    cin>>n;
    for(i=0;i<n/2;i++){
        cin>>c;
        if(c=='?') x++;
        else s+=c-'0';
    }
    for(i=n/2;i<n;i++){
        cin>>c;
        if(c=='?') y++;
        else s-=c-'0';
    }
    if(x<y){
        s*=-1;
    }
    x=abs(y-x);
    //cout<<s<<" "<<x<<endl;
    if(s+9*x/2==0) cout<<"Bicarp"<<endl;
    else cout<<"Monocarp"<<endl;

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
