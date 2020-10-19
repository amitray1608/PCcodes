#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    int n;
    cin >> n;
    int l = 1, h = n;
    char ff, ss, th, fr, fi;
    map<char, int>check;
    while(l <= h){
      check.clear();
      int mid = (h-l)/2+l;
      cout << mid << endl;
      cin >> ff;
      if(ff == 'E')
        return 0;
      check[ff]++;
      cout << mid << endl;
      cin >> ss;
      check[ss]++;
      cout << mid << endl;
      cin >> th;
      check[th]++;
      cout << mid << endl;
      cin >> fr;
      check[fr]++;
      cout << mid << endl;
      cin >> fi;
      check[fi]++;
      if(check['G'] > check['L']){
        l = mid+1;
      }else{
        h = mid-1;
      }
    }
  }
}