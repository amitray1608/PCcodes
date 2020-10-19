//“Make it work, make it right, make it fast.” – Kent Beck
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
	int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	long long count= 0;
	for(int i = 0; i < n - 2; ++i){
		for(int j = i + 1; j < n - 1; ++j){
			for(int k = j + 1; k < n; ++k){
				if(a[i] + a[j] > a[k]) count++;
			}
		}
	}
	cout << count;
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
	
