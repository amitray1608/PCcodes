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
	int n, m;
	cin >> n >> m;
	int sum = 0;
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	int count = 0;
	char x = s[0];
	count++;
	sum = (int)s[0] - 'a' + 1;
	for(int i = 1; i < n; i++){
			if(count == m){
			break;
		}
		if((int)x+1 < (int)(s[i])){
			//cout << s[i+1] << " ";
			x = s[i];
			sum += (int)(s[i] - 'a')+ 1;
		count++;

		}
	}
	if(count == m)
	cout << sum << endl;
	else
		cout << -1 << endl;
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
	
