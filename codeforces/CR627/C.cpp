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
    string s;
    cin >> s;
    int n = (int)s.size();
    char check[n + 3];
    check[0] = check[n + 1] = 'R';
    for(int i = 0; i < n; i++) check[i + 1] = s[i];
    int prev = 0, mini = 0;
    for(int i = 1; i <= n + 1; i++){
        if(check[i] == 'R'){
            mini = max(mini, i - prev);
            prev = i;
        }
    }
    cout << mini << endl;
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
