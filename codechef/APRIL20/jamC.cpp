//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool MYcompare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.first.second < b.first.second;
}
class Activity {
public:
    int start;
    int end;
    int index;
};
 
void solve(){
		int n, J = 0, C = 0;
		string ans;
		cin >> n;
		vector<pair<pair<int, int>, int>> lis;
		vector < pair<int, char>> done;
		for (int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;
			lis.push_back(make_pair(make_pair(e, s), i));
		}
		sort(lis.begin(), lis.end(), MYcompare);
		int i;
		for (i = 0; i < n; i++) {
			if (lis[i].first.second >= C) {
				C = lis[i].first.first;
				done.push_back(make_pair(lis[i].second, 'C'));
				continue;
			}
			if (lis[i].first.second >= J) {
				J = lis[i].first.first;
				done.push_back(make_pair(lis[i].second, 'J'));
				continue;
			} else {
				break;
			}
		}
		if (i != n) {
			ans = "IMPOSSIBLE";
			cout << ans << endl;
			return;
		}
		sort(done.begin(), done.end());
		for (i = 0; i < n; i++) {
			ans.push_back(done[i].second);
		}
		cout << ans << endl;
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
