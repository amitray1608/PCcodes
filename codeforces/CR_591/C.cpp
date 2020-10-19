#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;
ll lcm(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 }

void solve()
{
		ll n, x, y, a, b;
		ll k;
		cin >> n;
		ll arr[n];
		for(ll j=0; j<n; j++) {
			cin >> arr[j];
			arr[j]/=100;
		}
		sort(arr, arr + n);
		cin >> x >> a >> y >> b;
		cin >> k;
		ll c = lcm(a, b);	
		if(x>y) {
            swap(a, b);
            swap(x, y);
		}
		ll sol = -1,  maxi=0, A=0, B=0, C=0;
		for(ll j=0; j<n; j++) {
			if((j+1)%c==0) {
				maxi += arr[n-1-C]*x + arr[n-1-C-B] * (y-x) + arr[n-1-C-B-C]*x;
				C++;
			}
			else if((j+1)%a==0) {
				maxi += arr[n-1-C-B-C]*x;
				A++;
			}
			else if((j+1)%b==0) {
				maxi += arr[n-1-C-B]*(y-x)+arr[n-1-C-B-C]*x;
				B++;
				
			}
			if(maxi>=k) {
				sol=j+1;
				break;
			}
		}
		
		cout << sol << "\n";
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
