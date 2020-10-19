//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	int n, k;
	cin >> n >> k;
	int a[n], sum = 0, sum_new = 0;
	
	for(int &i : a)	cin >> i;
	
	sum = accumulate(a, a+n, sum);
		
		vector<int>v;
		v.push_back(a[0]);
	for(int i = 1; i<n; i++){
		int tmp = a[i];
			a[i] = max(a[i]+0, a[i]+(k -a[i] -a[i-1]));			
		v.push_back(a[i]);
	}
	//v.push_back(a[n-1]);
	sum_new = accumulate(v.begin(), v.end(), sum_new);
	cout << max(0,sum_new-sum) << endl;
	for(int i : v)
		cout << i << " ";
}

int main()
{
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
