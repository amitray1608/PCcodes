//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
  ll big = 0, small = 0;
ll check(ll n){
       big = 0, small = 0;
       while(n % 10 == 0)
   		big++, n /= 10;
           
   	    while(n % 2 == 0)
   		small++, n /= 2;

    return n;
}

void solve()
{
   	ll n;
   	cin >> n;

    n = check(n);

   	if(n != 1)
   		cout << "No\n" ;
   	else{
   		if(small <= big)
   			cout << "Yes\n";
   		else
   			cout << "No\n";
   	}
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
	
