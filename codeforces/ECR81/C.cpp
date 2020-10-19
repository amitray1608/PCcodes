//“Make itr work, make itr right, make itr fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	    string s, t;
	    cin >> s >> t;
        bool fres[26] = {0}, fret[26] = {0};
        for(char c : s)
	        fres[c-'a'] = 1;

        for(char c : t)
	        fret[c-'a'] = 1;

        vector<int>v[26];
	    for(int i = 0; i < (int)s.size(); i++)
                    v[s[i]-'a'].push_back(i);
            
	    bool check=0;
        for(int i = 0; i < 26; i++)	{
	        if(fret[i]==1 && fres[i] == 0)
                check = 1;
	    }
	    if(check){
            cout << -1 << endl;
                return;
        }
            int prev = -1, count=0;
            for(int i = 0; i < (int)t.size(); i++){
                vector<int>::iterator itr, ii = v[t[i]-'a'].begin();
                int pos = 0;
                for(itr = v[t[i]-'a'].begin(); itr!=v[t[i]-'a'].end(); itr++){
                     if(prev < *itr){
                           pos = 1;
                          prev = *itr;
                            continue;
                       }

                }
                if(pos == 0)
                    count++, prev = *ii;
                
            }
            count++;
            cout << count << endl;
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
