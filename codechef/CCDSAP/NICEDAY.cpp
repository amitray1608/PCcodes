//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int arr[siz][3];


struct Node{
  int count = 0;
  int a, b, c;
  void merge(Node x, Node y){
    if(x.a < y.a and x.b < y.b and x.c < y.c){
      a = x.a;
      b = x.b;
      c = x.c;
      count = x.count;
    }else if(x.a > y.a and x.b > y.b and x.c > y.c){
      a = y.a;
      b = y.b;
      c = y.c;
      count = y.count;
    }else{
      count = x.count + y.count;
      a = min(x.a, y.a);
      b = min(x.b, y.b);
      c = min(x.c, y.c);
    }
  }
}tree[siz*4];

bool compare(int )

void build(int node, int s, int e){
  if(s > e)
      return;
  if(s == e){
    tree[node].a = arr[s][0];
    tree[node].b = arr[s][1];
    tree[node].c = arr[s][2];
    tree[node].count = 1;
    return;
  }
  int mid = (s+e)/2;
  build(node << 1, s, mid);
  build((node << 1) | 1, mid+1, e);
  tree[node].merge(tree[node << 1], tree[(node << 1)|1]);
}


void solve(){
  memset(tree, 0, sizeof tree);
  memset(arr, 0, sizeof arr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  build(1, 0, n-1);
  cout << tree[1].count << endl;
  // for(int i = 1; i < 13; i++){
  //   cout << "case " << i << endl;
  //   cout << tree[i].a << ' ' << tree[i].b << ' ' << tree[i].c << ' ' << tree[i].count << endl;
  // }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  