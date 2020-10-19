#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve(){
	int n;
	cin >> n;
	if(n < 4){
		cout << -1 << endl;
		return;
	}
	for(int i = n; i >= 1; i--)
		if(i&1)
			cout << i << " ";
	cout << 4 << " " << 2 << " ";
	for(int i = 6; i <= n; i+=2)
		cout << i << " ";
	cout << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
