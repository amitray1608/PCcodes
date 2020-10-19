#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int N = 1e5+5;


struct Node{
  int val = 0, type, maxi = 0, sum = 0;
  
  Node merge(struct a, struct b) {
    struct node;
    node.val = 0;
    node.maxi = max(a.maxi, b.maxi);
    node. sum = a.sum + b.sum;
  }
};

vector<int> a;
vector<Node> tree(4*siz);


void solve(){
	int n, m;
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(1, 0, n-1);
  while(m--) {
    int typ;
    cin >> typ;
    if(typ == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      l--, r--;
      update(x)
      :
    } else if(typ == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      l--, r--;
      update();
      :
    } else if(typ == 3) {
      int l, r;
      cin >> l >> r;
      l--, r--;

      :
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      :
    }
  }
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//	cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
