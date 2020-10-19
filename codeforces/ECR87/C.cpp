//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
 #define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool isPerfectSquare(double x) {    
  double sr = sqrt(x); 
	return ((sr - floor(sr)) == 0); 
} 
void solve(){
    int n, m;
    cin >> n >> m;
    string s[n];
    set<char>st;
    map<char, int> check, x;
    for (string &i: s){ 
        cin >> i;
        for(char c : i)
            st.insert(c);
    }
	string ans = "";
    int count = st.size(), j;
    map<char, vector<char>> neigh;
    for(int i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            char c = s[i][j];
            if (x[c] == 0) {
                x[c] = 1;
                check[c] = 0;
            }
            if (i == n - 1 && check.find(c) == check.end()) {
                check[c] += 0;
            }else if (i != n - 1 && s[i + 1][j] != c){
				char cc = s[i + 1][j];
                check[c] = check[c] + (cc - 'A' + 1);
                neigh[cc].push_back(c);
            }else {
                check[c] += 0;
            }
        }
    }
    j = 0;
    while (j < count) {
        bool flag = 0;
        for (auto &i: check) {
            if (i.second == 0) {
                flag = 1;
                ans += i.first;
                i.second -= 1;
                for (auto &it: neigh[i.first]) {
					int dif = (i.first - 'A' + 1);
                    check[it] = check[it] - dif;
                }
                j++;
            }
        }
        if (!flag && count > j) {
            ans = "-1";
            break;
        }
    }
    cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "n", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 0;
		cin >> t;
		for(int i = 1; i <= t; i++){
			cout << "Case #" << i <<": ";
			solve();
		}
	return 0;
}	
