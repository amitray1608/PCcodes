
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  vector<vector<T>> tree;
  int n;
public:
  fenwick(int _n) : n(_n){
    tree.resize(n + 1 , vector <T>(n + 1,0));
  }

  void modify(int x , int y , T val){
    for(int i = x ; i <= n ; i += (i&-i)){
      for(int j = y ; j <= n ; j += (j&-j)){
        tree[i][j] += val;
      }
    }
  }

  T query(int x , int y){
    T res = 0;
    for(int i = x ; i ; i -= (i&-i)){
      for(int j = y ; j ; j-= (j&-j)){
        res += tree[i][j];
      }
    }
    return res;
  }

  T query(int x1 , int y1 , int x2 , int y2){
    return (query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1));
  }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, q;
  cin >> n >> q;
  fenwick<int> f(n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      f.modify(i + 1, j + 1, (c == '*'));
    }
  }
  while (q--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << f.query(x1, y1, x2, y2) << '\n';
  }
  return 0;
} //Hajimemashite

