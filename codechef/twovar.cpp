//RAY
#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll max = 100005;
vector<pair<ll,ll>> pre(max);
void solve(){
    //vector<ll> second(10005);
        for(ll i = 1; i < max; i++){
        for(ll j = 0; j < i; j++){
            if(pre[j].second < i*i ){
                if(pre[i].first < pre[j].first + 1)
                {
                    pre[i].first = pre[j].first + 1;
                    pre[i].second = pre[j].second + i*i;
                }
            }
        }
    }

}
int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << pre[n].first << endl;
    }

    return 0;
}

