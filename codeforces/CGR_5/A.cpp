//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int n; cin >> n;
	int odd = 0, tmp;
	while (n--) { 
			cin >> tmp;
		if (tmp & 1) {
			odd++;
			tmp >>= 1;
			if (odd & 1) tmp++;
		} 
			else tmp >>= 1;
		
		cout << tmp << endl;
	}
	
}

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
	
