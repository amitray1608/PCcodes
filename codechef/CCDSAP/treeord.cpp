//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
std::vector<int> v[3];
std::vector<int> pre, post, in;
int n, j = 0;

void inorder(int i) {
  if(i > n)
    return;
  inorder(i*2+1);
  v[0][i] = in[j++];
  // cout << j << ' ';
  inorder(i*2+2);
}

void preorder(int i) {
  if(i > n)
    return;
  v[1][i] = pre[j++];  
  // cout << j << ' ';
  preorder(i*2+1);
  preorder(i*2+2);
}

void postorder(int i) {
  if(i > n)
    return;
  postorder(i*2+1);
  postorder(i*2+2);
  v[2][i] = post[j++];
  // cout << j << ' ';
}


void solve(){
  cin >> n;
  pre.resize(n);
  for(int &i : pre) cin >> i;
  post.resize(n);
  for(int &i : post) cin >> i;
  in.resize(n);
  for(int &i : in) cin >> i;
  for(int i = 0; i < 3; i++)
      v[i].resize(n+1, 0);
  postorder(0);
  j = 0;
  preorder(0);
  j = 0;
  inorder(0);
  bool flag = true;
  for(int i = 1; i <= n; i++) {
    if(v[0][i] == v[1][i] and v[2][i] == v[1][i]) continue;
    flag = false;
    break;
  }
  cout << (flag ? "yes" : "no") << endl;
  for(int i = 0; i < 3; i++){
    for(int jj = 0; jj < n; jj++){
      cout << v[i][jj] << ' ';
    }
    cout << endl;
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