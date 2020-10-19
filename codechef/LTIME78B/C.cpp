//“Make it work, make it R, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
    int n, k;
	cin >> n >> k;
    string a;
    cin >> a;
	//~ int fre[n] = {0};
	//~ (a[0] == 1) ? fre[0] = 1 : fre[0] = 0;
	//~ for(int i = 1; i < n; i++){
		//~ if(a[i] == 1)
			//~ fre[i] = fre[i] + 1;
		//~ else
			//~ fre[i] = fre[i-1];
	//~ }
		int L[n], R[n];
		L[0] = 0, R[n-1] = 0;
		for(int i = n-2; i >= 0; i--)
			(a[i+1] == '1') ? R[i] = R[i+1] + 1 : R[i] = 0;
		for(int i = 1; i < n; i++)
			(a[i-1] == '1') ? L[i] = L[i-1] + 1 : L[i] = 0;
		
		
		int count = k, f = 0, l = k-1;
		while(l < n)
            count = max(count, k + L[f++] + R[l++]);
		
		cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
