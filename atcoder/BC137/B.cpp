#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
  ll n, k;
  cin >> n >> k;
	for(ll i = k-n+1; i<k+n; i++)
		cout << i << " ";
		
		cout << endl;
}
int main()
{
		    ios_base::sync_with_stdio(false);
			cin.tie(NULL);
	int t = 1; 
	//cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
