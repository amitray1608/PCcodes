#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		int a[26] ={0};
		for(char c : s){
			a[c-'a']++;
		}
		while(q--){
			long long c, ans = 0;
			cin >> c;
			for(int i = 0; i < 26; i++){
				if(c < a[i])
					ans += a[i]-c;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
