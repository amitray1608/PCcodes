#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
        ll n, m;
        cin >> n >> m;
        ll query, flag, sect = __gcd(n, m);
         ll x, y, X, Y;
        if(sect == 1)
            flag = 0;
        else if(sect == max(n, m))
            flag = 2;
        else
            flag = 1;
        
        cin >> query;
        while(query--)
        {
            cin >> x >> y >> X >> Y;
            if(flag == 0)
                cout << "YES\n";
            else if(flag == 1)
            {
                ll a = n/sect, b = m/sect;
                ((x == 1 && y%a == Y%b) || (X == 2 && y%b == Y%a)) ? cout << "YES\n" : cout << "NO\n" ;
            }
            else
            {
                (y == Y) ? cout << "YES\n" : cout << "NO\n";
            }
        }

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
