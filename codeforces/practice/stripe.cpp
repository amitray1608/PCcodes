#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(times) cout << #times << " = " << times << endl;

void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	int sum = 0;
	for(int &i : v)
		cin >> i, sum += i;
	int tmp = 0, count = 0;
			tmp += v[0];
	for(int i = 1; i<n; i++){
		if(tmp == sum - tmp)
			count++;
		tmp += v[i];

	}
	cout << count ;
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
	
