#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(temp) cout << #temp << "temp = " << temp << endl;

ll calc(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
 ll temp, temp2;
    temp = min(x2, x4) - max(x1, x3);
     temp2 = min(y2, y4) - max(y1, y3);
    ll ar = temp * temp2;
    if(temp <= 0 || temp2 <= 0)
        return 0;
    return ar;
}

void solve()
{
    ll x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
	cin >> x1 >> y1 >> x2 >> y2;
     ll white_area = abs(x1-x2) * abs(y1-y2);
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    
    ll black_both, black_one, black_two, cover, left;
	 black_one = calc(x1, y1, x2, y2, x3, y3, x4, y4);
	 black_two = calc(x1, y1, x2, y2, x5, y5, x6, y6);
	 black_both = calc(x3, y3, x4, y4, x5, y5, x6, y6);
	cover = black_one + black_two - black_both;
	left = white_area - cover;
	(left > 0) ? cout << "YES" : cout << "NO";
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
	
