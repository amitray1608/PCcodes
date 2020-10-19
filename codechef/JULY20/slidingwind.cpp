//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) cin >> i;
  deque<int>q;
  int left[n+1], right[n+1];
  for(int i = 0; i < n; i++) {
    while(!q.empty() and a[i] <= a[q.back()])
      right[q.back()] = a[i], q.pop_back();
    if(!q.empty()) {
      left[i] = a[q.back()];
    }
    q.push_back(i);
  }
  while(!q.empty()){
    cout << q.front() << ' ';
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
5
5 3 1 2 4
*/