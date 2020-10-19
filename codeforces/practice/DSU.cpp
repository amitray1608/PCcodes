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
	int q;
	cin >> q;
	string a[q], b[q];
	int i = 0;
	unordered_map<string, string>check, check1;
	while(q--){
		bool flag = false;
		cin >> a[i] >> b[i];
		for(auto it : check){
			if(it.second == a[i]){
				string s = it.first;
				check.erase(it.first);
				check[s] = b[i];
				flag = true;
				break;
			}
		}
		if(!flag){
			check[a[i]] = b[i];
		}
		i++;
	}
	cout << check.size() << endl;
	for(auto it : check)
		cout << it.first << " " << it.second << endl;
	
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
