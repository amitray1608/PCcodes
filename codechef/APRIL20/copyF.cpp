#include<bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int mod = int(1e9 + 7);
vector<int> perfect;

//seek and ye shall find;
void paradiso() {
    int n, sum = 0; cin >> n;
    sum += n;
    for(auto& k: perfect) {
        if(k > n) break;
        int term = (((n / k) % mod) * (k % mod)) % mod;
        sum = ((sum % mod) + (term % mod)) % mod;
    }
    cout << sum << endl;
}

signed main() {
    int t; cin >> t;
    vector<int> squares;
    for(int i = 1, odd = 3; i <= int(1e13); i += odd, odd += 2) squares.push_back(i);
    squares.erase(begin(squares));
    int MAX = int(1e12);
    map<int, int> okay;
    for(auto& p: squares) {
        if(p > MAX) break;
        for(int k = p, s = sqrtl(p); k <= MAX; k *= s) {
            if(okay.find(k) != okay.end()) continue; okay[k] = 1;
            perfect.push_back(k);
        }
    }
    sort(begin(perfect), end(perfect));
    while(t--) paradiso();
    return 0;
} //raise hellish blaze!
