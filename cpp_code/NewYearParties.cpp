//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int getMax(int a[], int n)
{
	int ans = 0, cur = -1e9;
	for(int i = 0; i < n; i++)
	{
		if(a[i] - 1 > cur)
		{
			ans++;
			cur = a[i] - 1;
		}
		else if(a[i] > cur)
		{
			ans++;
			cur = a[i];
		}
		else if(a[i] + 1 > cur)
		{
			ans++;
			cur = a[i] + 1;
		}
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	int a[n+1];
	int maxi = 0;
	int dp[n+1] = {0}, countmini = 0;
	for(int &i : a) cin >> i, maxi = max(i, maxi), dp[i]++;
	for(int i = 1; i <= n ;){
		if(dp[i] == 0) i++;
		else{
			countmini++;
			i+=3;
		}
	}
	cout << countmini << endl;
	sort(a, a+n);
	cout << countmini << " " << getMax(a, n) << endl;
	
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
