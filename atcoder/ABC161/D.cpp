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
	int k;
	cin >> k;
	vector<string>s;
	for(int i = 1; i < 10; i++){
		s.push_back(to_string(i));
	}
	int curr = 0, total = 9;
	while(total < k){
		string get = s[curr];
		curr++;
		ll z = get.back()-'0';
		string ans;
		if(z - 1 > -1){
			ans = get+char(z-1 + '0');
			s.push_back(ans);
			total++;
		}
		if(z > -1 and z < 10){
			ans = get+char(z + '0');
			s.push_back(ans);
			total++;
		}
		if(z + 1 < 10){
			ans = get+char(z+1+'0');
			s.push_back(ans);
			total++;
		}
	}
	cout << s[k-1] << endl;
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
	
