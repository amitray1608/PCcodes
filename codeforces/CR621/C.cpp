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
	string s;
	cin >> s;
	ll  n = s.length();
	ll freq[26] = {0}, maxi = 0;
	for(char c : s){
		freq[c-'a']++;
		maxi = max(maxi, freq[c-'a']);
    }
	for(int i = 0; i < 26; i++)  freq[i] = 0;	
	ll arith[26] = {0};
	for(int ii = 0; ii < 26; ii++){
		for(int i = 0; i < n; i++){
			if(s[i] - 'a' == ii){
				for(int j = 0; j < 26; j++)	
                	arith[j] += freq[j];	
				freq[s[i] - 'a']++;
			}else{
				freq[s[i] - 'a']++;
			}
		}
		ll tmp = *max_element(arith, arith + 26);
		maxi = max(maxi, tmp);
		for(int i = 0; i < 26; i++)
			freq[i] = 0, arith[i] = 0;
	}
	cout << maxi << endl;
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
