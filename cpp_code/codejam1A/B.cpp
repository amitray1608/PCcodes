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
	int n;
	cin >> n;
	string v[n];
	int maxi = 0;
    string ans = "";
    int flag = 1;
	for(int i=0;i<n;i++){
		cin >> v[i];
		reverse(v[i].begin(),v[i].end());
		if(v[i].size() > v[maxi].size())
			maxi = i;
	}
	for(int i=0; i < (int)v[maxi].size(); i++){
		char c = v[maxi][i];
		for(int j = 0; j < n; j++)
			if(i < (int)v[j].size() && (v[j][i] != c && v[j][i] != '*')){
				flag = 0;
				break;
			}
		if(flag == 0)
			break;
	}
	if(flag == 0)
		cout << '*' << endl;
	else{
		ans = v[maxi].substr(0, v[maxi].size()-1);
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 1;
		cin >> t;
		while(t--){
			cout << "Case #" << tt++ << ": ";
			solve();
		}
	return 0;
}	
