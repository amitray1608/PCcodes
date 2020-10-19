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
  std::vector<int> a(n);
  for(int &i : a) cin >> i;
  int ten = 0, five = 0;
  bool flag = true;
  for(int i : a){
    if(i == 5)
      five++;
    else if(i == 10){
      ten++;
      if(five){
        five--;
      }else{
        flag = false;
        break;
      }
    }else if(i == 15){
      if(ten > 0){
        ten--;
      }else if(five >= 2){
        five -= 2;
      }else{
        flag = false;
        break;
      }
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
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