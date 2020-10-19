//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int l[5100], r[5100], a[5100];

void solve(){
	int i, j;
	int n;
	string s, t;

	cin >> s;

	n = s.length();
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	memset(a, 0, sizeof(a));

	t = s; t.push_back('#');
	for (i = 1; i <= n; i++)
		t[i] = s[i - 1];

	t[0] = '#';
	for (i = 1; i <= n; i++)
	{
		if (t[i] == 'b')
			l[i + 1] = l[i] + 1;
		else
			l[i + 1] = l[i];

		if (t[i] == 'a')
			a[i] = a[i - 1] + 1;
		else
			a[i] = a[i - 1];
	}

	for (i = n; i >= 1; i--)
	{
		if (t[i] == 'b')
			r[i - 1] = r[i] + 1;
		else
			r[i - 1] = r[i];
	}

	int mx = 0;
	int x, y;
	for (i = 1; i <= n; i++)
	{
		//2nd str starts from i, ends in j
		for (j = i; j <= n; j++)
		{
			//no. of b's in 1st and 3rd str
			x = l[i] + r[j];

			//no. of a's in range i-j
			y = a[j] - a[i];
			mx = max(mx, n - x - y);
		}
	}

	cout << mx << endl;
}

int main(){
	#ifndef RAY
		//~ freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
