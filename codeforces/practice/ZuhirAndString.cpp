//“Make it work, make it right, make it fast.” – Kent Beck
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
	string s;
	cin >> s;
	int count = 0;
	int check[26] = {0};
	for(int i = 0; i < n-1; i++){
	//	deb(i);
		char x = s[i];
		int cc = 0, j = i;
		while(s[j] == s[j+1] && j < n-1){
			cc++;
			j++;
			deb(j);
		}
		i = j-1;
		check[(int) (x - 'a')] += cc/k;
	}
	count = *max_element(check, check+26);
	cout << count << endl;
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
