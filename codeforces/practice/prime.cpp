#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int n;
	cin >> n;
	for(int i = 2; i <= n-1; i++)
		{
			if(n % i ==0)
			{	cout << "Not prime"
				break;
			}
		}
		
		if(i == n)
			cout << "prime";
			
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
	
