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
	cin>>n;
	string v[n];
	for(int i=0; i<n; i++) cin >> v[i];
	string ans = "", curr = "";
	string s = v[0];
	int pos = s.find("*");
	string tmp = s.substr(pos+1);
	ans = tmp;
	curr = tmp;
	int flag = 0;
	for(int i=1; i<n; i++){
		s = v[i];
		pos = s.find("*");
		tmp = s.substr(pos+1);
		for(int j = curr.size()-1, k = tmp.size()-1; j>=0 && k>=0; j--, k--){
			if(tmp[k]!=curr[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){  
            ans = "*";
            break;
        }
		if(tmp.size() > ans.size())
		    ans = tmp;
		if(tmp.size() < curr.size())
		    curr = tmp;
	}
	cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int flag = 1, tt = 1;
		cin >> flag;
		while(flag--){
			cout << "Case #" << tt++ << ": ";
			solve();
		}
	return 0;
}	
