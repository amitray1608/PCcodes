#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> st, pq;
  st.insert(0); st.insert(n);
  int x; cin >> x;
  st.insert(x);
  pq.insert(abs(n - x));
  pq.insert(x);
  cout << max(x, n - x) << ' ';
  for(int i = 1; i < m; i++) {
    cin >> x;
    st.insert(x);
    auto p = st.find(x);
    auto c = p, d = p; d--, c++;
    pq.erase(pq.find(abs(*d - *c)));
    pq.insert(abs(*p - *c));
    pq.insert(abs(*p - *d));
    auto ans = pq.end();
    ans--;
    cout << *ans << ' ';
  }
  return 0;
}
