#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int n, m, c;
	cin >> n >> m >> c;
	vector<int>a(n);
	for(int & i : a)
		cin >> i;
	vector<int>b(m);
	for(int & i : b)
		cin >> i;
	int x = 0;
	//cout << n-m-1 << endl;
	for(int i = 0; i < n-m+1; i++){
		x += b[i];
		 a[i] += x;
		  a[i] =  a[i] % c;
	}

	//cout << endl;
	x = 0;
	 int j = n-1;
		for(int i = m-1; i > 0; i--, j--){
		x += b[i];
		 a[j] += x;
		  a[j] =  a[j] % c;
	}
		

	for(int i : a){
		cout << i <<  " ";		
	}
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
	
