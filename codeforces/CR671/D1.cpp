#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  sort(a.begin(), a.end());
  deque<int>q;
  for(int i = 0; i < n; i++) {
    q.push_back(a[i]);
  }
  int count = 0;
  a.clear();
  a.push_back(q.back());
  q.pop_back();
  while(!q.empty()) {
   if(!q.empty() and a.back() != q.front())
     a.push_back(q.front()), q.pop_front();
   if(!q.empty() and a.back() != q.back())
     a.push_back(q.back()), q.pop_back();
  }
  vector<int>ans(n, 0);
  for(int i = 1; i < n-1; i++) { 
    if(a[i] < a[i-1] and a[i] < a[i+1]) ans[i] = 1;
  }
  count = accumulate(ans.begin(), ans.end(), count);
  cout << count << endl;
  for(auto i : a)
    cout << i << ' ' ;
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
