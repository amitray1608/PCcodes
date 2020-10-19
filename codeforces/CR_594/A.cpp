//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
		int n;
		cin >> n;
		int A[n];
		ll x=0,y=0;
		for(int i=0;i<n;i++){
			cin >> A[i];
			if(A[i]%2==0)
				y++;
			else
				x++;
		}
		int m;
		cin>>m;
		int B[m];
		ll X=0,Y=0, count = 0;
		for(int i=0; i<m; i++){
			cin >> B[i];
			if(B[i]%2==0)
				Y++;
			else
				X++;
		}
		 count = x*X + y*Y;
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
	
