#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
ll recc(ll it, ll ans, ll n, ll a[]);
ll DP[100005];
ll dig(ll x)
{
	ll ans = 0;
		while(x>0){
			ans+=x%10;
			x/=10;
		}
		return ans;
}


ll recc(ll it, ll ans, ll n, ll a[])
{
    ll x, y, i;
  DP[n-1] = a[n-1] * n;
 
  for(i = n - 2; i >= 0; i--) {
    x = a[i] * (i + 1) + DP[i+1];
    y = a[i] * (i + 2) + a[i+1] * (i + 1) + DP[i+2];
    DP[i] = max(x, y);
  }
 
  return DP[0];
}

void solve(){
         ll n;
            cin >> n;
        ll a[n];
        ll sum = 0;
        for(ll i=0; i<n;i++)
            cin >> a[i], sum+= a[i]*(i+1);

         sum = recc(0, sum, n, a);
        cout << sum << endl;
    
}

int main(){
		int t;
		cin >> t;
		while(t--)
		{
            memset(DP, 0, sizeof(DP));
			solve();
		}
	return 0;
}


