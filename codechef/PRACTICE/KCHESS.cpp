#include<bits/stdc++.h>
using namespace std;
typedef  long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll MOD = 1e9+7;
vector<pair<ll, ll>> v;
long k[100000][2];
int N;

int check( ll A, ll B)
{
    for (int i = 0; i < N; i++) {
        if ((k[i][0] + 2 == A && k[i][1] + 1 == B) ||
            (k[i][0] + 2 == A && k[i][1] - 1 == B) ||
            (k[i][0] - 2 == A && k[i][1] + 1 == B) ||
            (k[i][0] - 2 == A && k[i][1] - 1 == B) ||
            (k[i][0] + 1 == A && k[i][1] + 2 == B) ||
            (k[i][0] + 1 == A && k[i][1] - 2 == B) ||
            (k[i][0] - 1 == A && k[i][1] + 2 == B) ||
            (k[i][0] - 1 == A && k[i][1] - 2 == B))
            return 1;
    }
    return 0;
}
void solve()
{
	int n;
	cin >> n;
	ll a, b;
	memset(k, 0, sizeof k);
        for (int i = 0; i < n; i++) {
            cin >> k[i][0];
            cin >> k[i][1];
        }
	cin >> a >> b;
	
		if(check(a-1, b-1) && check(a, b-1) &&check(a+1, b-1) &&check(a, b-1) &&check(a, b) &&check(a, b+1) &&check(a+1, b-1) && check(a+1, b) && check(a+1, b+1) )
			cout << "YES\n";
		else
		cout << "NO\n";

}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	




