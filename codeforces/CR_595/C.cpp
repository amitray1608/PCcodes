//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	ll n;
	cin >> n;
	ll sum = 1, count = 1;
	while(sum < n){
		count *= 3;
		sum += count;
	}
	while(count >= 1){
		if(sum - count >= n)
			sum -= count;
		
		count /= 3;
	}
	cout << sum << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
