
#include <bits/stdc++.h>
using namespace std;



#define int long long 

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int ans = 0;

		vector<string> s(n);

		for(int i = 0; i < n; i++){
			cin >> s[i];
		}

		vector<set<string>> temp(26);
		vector<int> freq(26, 0);

		for(int i = 0; i < n; i++){
			temp[s[i][0] - 'a'].insert(s[i].substr(1));
			freq[s[i][0] - 'a']++;
		}

		// for(int i = 0; i < 26; i++){
		// 	for(auto x:temp[i]){
		// 		cout << x << " ";
		// 	}
		// 	cout << endl;
		// }
		for(int  i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				if(i != j){
					int num1 = 0, num2 = 0;
					for(auto x: temp[i]){
						if(temp[j].size() != 0 and temp[j].count(x) == 0){
							num1++;
							//cout << i << " " << j << " " << x << endl;
						}
					}
					for(auto x: temp[j]){
						if(temp[i].size() != 0 and temp[i].count(x) == 0){
							num2++;
							//cout << i << " " << j << " " << x << endl;
						}
					}

					ans += (num1 * num2);
				}

			}
		}


		cout << ans << endl;

	}
}
