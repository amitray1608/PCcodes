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
		int a, b, x;
	cin >> a >> b >> x;
	
	if (x % 2 == 0) {
		if (a > b) {
			for (int i = 0; i < x / 2; ++i)
				cout << "01";
			cout << string(b - x / 2, '1');
			cout << string(a - x / 2, '0');
		} else {
			for (int i = 0; i < x / 2; ++i)
				cout << "10";
			cout << string(a - x / 2, '0');
			cout << string(b - x / 2, '1');
		}
	} else if (a > b) {
		for (int i = 0; i < x / 2; ++i)
			cout << "01";
		cout << string(a - x / 2, '0');
		cout << string(b - x / 2, '1');
	} else {
		for (int i = 0; i < x / 2; ++i)
			cout << "10";
		cout << string(b - x / 2, '1');
		cout << string(a - x / 2, '0');
	}
	cout << endl;
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
	
