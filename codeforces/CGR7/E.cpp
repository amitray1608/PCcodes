#include <bits/stdc++.h>
 
#define ull unsigned long long int
#define ll long long int
#define vll vector<ll>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define itr vll::iterator
#define all(c) c.begin(),c.end()
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000001
 
#define rep(i, n)      for(ll i = 0; i <  n; ++i)
#define repA(i, a, n)  for(ll i = a; i <= n; ++i)
#define repD(i, a, n)  for(ll i = a; i >= n; --i)
 
using namespace std;
 
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<char> v;
    int fl = 1;
    int lf = 0, rt, tp = 0;
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]){ fl = 0; lf = i; break;}
        v.pb(s[i]);
        tp = i;
    }
    if(fl){
        cout << s;
        return;
    }
    rt = n-1-lf;
    vector<char> v1, v2;
    for(int j = lf; j < n-1; j++){
        int flg = 1;
        for(int i = lf; i < j; i++){
            if(s[i] != s[j+lf-i]) flg = 0;
        }
        if(flg){
            v1.resize(0);
            for(int i = lf; i < j; i++) v1.pb(s[i]);
        }
    }
    for(int j = rt; j >= 0; j--){
        int flg = 1;
        for(int i = j; i <rt; i++){
            if(s[i] != s[rt+j-i]) flg = 0;
        }
        if(flg){
            v2.resize(0);
            for(int i = j; i < rt; i++) v2.pb(s[i]);
        }
    }
    if(v1.size() == 0 && v2.size() == 0){
        for(int i = 0; i < v.size(); i++)cout << v[i];
        cout << v[tp+1];
        for(int i = v.size(); i >= 0; i--)cout << v[i];
    }else if(v1.size() > v2.size()){
		for(int i = 0; i<v.size(); i++)cout << v[i];
        for(int i = 0; i < v1.size(); i++) cout << v1[i];
        for(int i = v.size()-1; i>=0; i--)cout << v[i];
    }else{
        for(int i = 0; i < v.size(); i++) cout << v[i];
        for(int  i = 0; i < v2.size(); i++) cout << v2[i];
        for(int i = v.size()-1; i >= 0; i--) cout << v[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, tmp = 0;
    cin >> t;
    // t = 1;
    while(tmp++ < t){
        // cout << "Case #" << tmp << ": ";
        solve();
        if(t-tmp) cout << "\n";
    }
    cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
    return 0;
}
