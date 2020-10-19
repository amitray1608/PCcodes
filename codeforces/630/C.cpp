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
	vector<string>freq;
	for(int i=0,j=0; i < n/k; i++){
		string t = s.substr(j,k);
		freq.push_back(t);
		j += k;
	}
	int ans=0;
	for(int j=0; j < (k+1)/2; j++){
		map<char, int>check;
		for(int i=0;i < (int)freq.size();i++){

		 if(j==k-j-1)check[freq[i][j]]++;
		 else {
			check[freq[i][j]]++;
			check[freq[i][k-j-1]]++;
		}
		}
		int maxi = 0, count = 0;
		for(auto x:check){
            count += x.second;
			maxi = max(maxi, x.second);
		}
		ans += count-maxi;
	}
	cout << ans << endl;
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
	
