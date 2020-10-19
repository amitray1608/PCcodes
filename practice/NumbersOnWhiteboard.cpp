#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  deque<int> q;
  for(int i = n; i > 0; i--) {
    q.push_back(i);
  }
  vector<array<int, 2>> ans;
  while(q.size() > 1) {
    int x = q.front();
    q.pop_front();
    int y = q.front();
    q.pop_front();
    int av = (x + y + 1) / 2;
    ans.push_back({x, y});
    q.push_front(av);
  }
  cout << q.front() << endl;
  for(auto i : ans)
    cout << i[0] << ' ' << i[1] << endl;
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
