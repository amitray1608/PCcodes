#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{	
	    ll n, count = 0, i;
        cin >> n;
        vector <ll> a(n);
        cin >> a[0];
        set <ll> check;
        for(i = 1; i<n; i++){
            cin >> a[i];
            if(a[i] < a[i-1]){
                if(check.find(a[i]) == check.end()){
                    check.insert(a[i]);
                    count++;
                }
            }
        }
        cout << count << endl;
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
	
