#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;



void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int &i : a) cin >> i;
  int count = 0, mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = 0; k < n; k++) b[k] = a[k]; 
      swap(b[i], b[j]);
      count = 0;
      for(int k = 0; k < n; k++) {
        for(int l = 0; l < n-k-1; l++) { 
          if(b[l] > b[l+1]) {
            count++;
            swap(b[l], b[l + 1]);
          }
        }
      }
      mini = min(mini, count);
    }
  }

  cout << mini << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
