//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n, x, p, k;
  cin >> n >> x >> p >> k;
  vector<int>a(n);
  set<int> st;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    st.insert(a[i]);
  }
  sort(a.begin(), a.end());
  int pth = 1;
  bool present = false;
  for(auto i : st) {
    if(i == x and pth == p) {
      cout << 0 << endl;
      return;
    } else if(i == x)
      present = true;
    pth++;
  }
  if() {

  }

  //if element does not exist in the array.
  int lx = 0, gx = 0;
  if(first == -1){
    if(p > k) {
      for(int i = k; i < n; i++) {
        if(a[i] > x)
          gx++;
      }
      if(abs(p-k) <= p) {
        cout << abs(p-k) << endl; 
      } else 
       cout << -1 << endl;
    }
    return;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
