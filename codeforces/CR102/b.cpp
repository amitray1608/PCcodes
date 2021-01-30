#include <bits/stdc++.h>
using namespace std;

string solve(){
	string s, t;
	cin >> s >> t;
	if(s.size() > t.size())swap(s, t);
	string d = "";
	string ans = "";
	for(int i = 0; i < s.size(); i++){
		d += s[i];
		if((t.size() % d.size()) != 0)continue;
		bool ok = true;
		for(int j = 0; j < t.size(); j += d.size()){
			if(t.substr(j, (int)d.size()) != d) ok = false;
		}
		if(ok){
			string res = "";
			int a = s.size()/d.size(), b = t.size()/d.size();
			for(int i = 0; i < a * b / __gcd(a,b); i++){
				res += d;
			}
			if((int)ans.size() == 0)ans = res;
			else if(ans.size() > res.size())ans = res;
		}
	}
	if(ans.size() == 0)return "-1";
	else return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while(t--){
		cout << solve() << endl;
	}

	return 0;
}
