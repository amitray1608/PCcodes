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
	string s;
	cin >> s;
	pair <string, int> ans[n];
	for(int i = 0; i < n; i++){
		string ss = s.substr(0, i);
	string st = s.substr(i, n-i);
	if(n&1)
		reverse(ss.begin(), ss.end());
			ans[i].first = st + ss;	
			ans[i].second = i+1;
	}
       reverse(s.begin(),s.end());
        ans[n-1].first = s;
        ans[n-1].second = n;
		sort(ans, ans+n);
		cout << ans[0].first << endl;
		cout << ans[0].second << endl;
	//if(n == 1){
		//cout << s << endl << 1 << endl;
		//return;
	//}
	//int mini_pos = INT_MAX;
	//for(int i=0; i<n; i++)
		//if(s[i] < mini_pos)
			//mini_pos = s[i];
	//vector<int> v, temp;
	//for(int i=0; i<n; i++){
		// string half = cp.substr(i-1);
		// string extra = cp.substr(0,i-1);
		// if(cp.size()%2)
		//     reverse(extra.begin(), extra.end());
		// half += extra;
		// if(half <= lexi){
		//     if(half < lexi)
		//     pos = i;
		//     else
		//     pos = min(pos, i);
		//     lexi = half;
		// }
		//int p = s[i];
		//if(p == mini_pos)
		   //v.push_back(i);
	//}
 //vector<int> all[50005];
 //int prev = 0;
	//if(v[0]==0)
	//{
		//int p=s[1];
		//temp.push_back(p);
		//all[p].push_back(0);
		//prev++;
	//}
 
	//for(int i = prev; i < v.size(); i++){
		//int k = s[v[i]-1];
		//temp.push_back(k);
		//all[k].push_back(v[i]);
	//}
 
	//for(int i=0; i <= 5001; i++)
		 //sort(all[i].begin(), all[i].end());
  //int pos;
  //sort(temp.begin(), temp.end());
  //pos = all[temp[0]][0];
  //int k = 0;
 
   //for(int i = 0; i < n-pos; i++){
	  //reverse(s.begin() + k, s.begin() + pos + i + 1);
	  //k++;
   //}
   //cout << s << endl;
   //cout << pos+1 << endl;
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
