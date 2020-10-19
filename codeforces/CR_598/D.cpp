//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(tmp) cout << #tmp << " = " << tmp << endl;
void solve(){
	    int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v;
        v.push_back(0);
        for(int i = 0;i < n; ++i)
            if(s[i] == '0')   v.push_back(i);
        
        for(int i = 1; i <(int) v.size(); ++i)
        {
            if(i-1 == 0 && v[i] == 0) continue;
            
            int tmp = v[i] - v[i-1] - 1;
            
            if(i-1 == 0) ++tmp;
            
            if(k >= tmp) k -= tmp, v[i] -= tmp;
            
            else v[i] = v[i] - k , k = 0;
        }
        int pos = 1;
        for(int i = 0;i < n; ++i)
        {
            if(pos < (int)v.size() && i == v[pos]){
                cout << 0;
                ++pos;
            }
            else
                cout << 1;
        }
        cout << endl;
}

int main(){
	#ifndef RAY
	//	freopen("input.txt", "r", stdin);
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
