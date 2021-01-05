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
  vector<int> a(n);
  int one = 0, two = 0, sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == 1) one++;
    else two++;
    sum += a[i];
  }

  auto calc = [&]() {
    int p = sum/2;
    if(p&1 and one)
      p--, one--;
    int left = min((p/2) * 2, 2 * two);
    p -= left;
    left = min(p, one);
    p -= left;
    return p;
  };

  int x = calc();
  if(sum&1 or x > 0) {
     cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
