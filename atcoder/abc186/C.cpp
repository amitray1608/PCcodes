#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

int decimaltoOctal(int deciNum){

    // initializations
    int octalNum = 0, countval = 1;
    int dNo = deciNum;

    while (deciNum != 0) {

        // decimals remainder is calculated
        int remainder = deciNum % 8;

        // storing the octalvalue
        octalNum += remainder * countval;

        // storing exponential value
        countval = countval * 10;
        deciNum /= 8;
    }
    return octalNum;
   // cout << octalNum << endl;
}

void solve() {
  int n;
  cin >> n;
  int count = 0;
  for(int i = 1; i <= n; i++) {
    string s = to_string(i);
    bool ok = true;
    for(char c : s) 
      if(c == '7') ok = false;
    int oc = decimaltoOctal(i);
    s = to_string(oc);
    for(char c : s) 
      if(c == '7') ok = false;
    if(ok) count++;
  }
  cout << count << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
