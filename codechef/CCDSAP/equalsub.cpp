#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(x) cout << #x << " " << x << endl;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	map<int, int>check;
	int sum = 0, count = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 0)
			a[i]  = -1;
		sum += a[i];
		if(sum == 0)
			count++;
		if(check[sum])
			count += check[sum];
		else if(check[sum] == 0)
			check[sum] = 1;
		else
			check[sum]++;
			deb(sum);
			deb(check[sum]);
			deb(count);
	}
	cout << count << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
