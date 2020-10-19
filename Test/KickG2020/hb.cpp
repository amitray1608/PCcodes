#include <bits/stdc++.h>
using namespace std;

void solve(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    map<int, int> check;
    bool ans = 0;
    for(int i = 0;  i < m; i++) {
        if(ans) continue;
        int c, aa = a[i].first, bb = a[i].second;
        (aa <= bb) ? c = bb - aa : c = bb + n - aa;
        while(c >= 0 and check[aa] == 0) {
            int p = check[aa];
            if(p > c)
                check[aa] = c, c = p;
            aa++, c--;
            if(aa == n) aa = 0;
        } 
        if(c >= 0) 
            check[aa] = c;
        else
            ans = 1;    
    }
    cout << (ans ? "NO" : "YES") << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
