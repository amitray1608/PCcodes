#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb push_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2210, mod = 1e9 + 7, inf = LLONG_MAX / 1000ll;

int N, ans; 
int x[maxN], y[maxN];

void de(int r)
{
//	cout << r << endl;
	set<ii> M;
	loop(i, 1, N) 
	{
		if(i == r) continue;
		int dx = x[i] - x[r];
		int dy = y[i] - y[r];
		int g = abs(__gcd(dx, dy));
		dx /= g;
		dy /= g;
		M.insert({dx, dy});
	}
	ans += 2 * (N - 1) - M.size();
}
bool check1()
{
	int r = 1;
	loop(i, 1, N)
	{
		if(x[r] > x[i] or (x[r] == x[i] and y[r] > y[i])) r = i; 
	}
	set<ii> M;
	loop(i, 1, N) 
	{
		if(i == r) continue;
		int dx = x[i] - x[r];
		int dy = y[i] - y[r];
		int g = abs(__gcd(dx, dy));
		dx /= g;
		dy /= g;
		M.insert({dx, dy});
	}
	if(M.size() == 1) return 1;
	return 0;
}
signed main()
{
//	freopen("ball.inp", "r", stdin);
//	freopen("ball.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	loop(i, 1, N) cin >> x[i] >> y[i];
	if(check1()) 
	{
//		cout << 1 << endl;
		loop(i, 1, N)
		{
			loop(j, 1, N) ans += abs(j - i);
		}
	}
	else
	{
		loop(i, 1, N) de(i);
	}
	cout << ans;
}
