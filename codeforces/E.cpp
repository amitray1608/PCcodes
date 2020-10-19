#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int count = 0, fre[n+1]={0};
	for(int i = 0; i < n; i++){
		int sum = a[i], j = i+1;
		for(; j < n; j++){
			sum += a[j];
			if(sum > 0 and sum <= n)
				fre[sum]++;
		}
	}
	for(int &i : a)
		count += (fre[i] > 0);
	cout << count << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
