//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int mod = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll MAX = 1000000000+7;
 
using namespace std;
 
ll modF(ll a) {
    if (a<0) return modF((a%MAX)+MAX);
    else return (a%MAX);
}

void solve(){
  ll n, k, i, a, po=0, ni=0, ans=1;
  vector<ll> vcp, vcn;
  cin >> n >> k;
  for (i=0;i<n;i++) {
      cin >> a;
      if (a<0) {
          a=-a;
          ni++; vcn.push_back(a);
      }
      else {
          po++; vcp.push_back(a);
      }
  }
  if (po>0) sort(vcp.begin(),vcp.end());
  if (ni>0) sort(vcn.begin(),vcn.end());

  if (po==0) {
      if (k%2==0) {
          for (i=0;i<k;i++) {
              ans = ans * (-vcn[ni-1]);
              ans = modF(ans);
              ni--;
          }
      }
      else {
          for (i=0;i<k;i++) {
              ans = ans * (-vcn[i]);
              ans = modF(ans);
          }
      }
  }
  else if (ni==0) {
      for (i=0;i<k;i++) {
          ans = ans * vcp[po-1];
          ans = modF(ans);
          po--;
      }
  }
  else {
      if (k%2==1) {
          ans = vcp[po-1];
          po--; k--;
      }
      while (k>1 && (po>=2 || ni>=2)) {
          ll propo = 0;
          if (po>=2) propo = vcp[po-1]*vcp[po-2];
          ll proni = 0;
          if (ni>=2) proni = vcn[ni-1]*vcn[ni-2];

          if (propo>proni) {
              propo = modF(propo);
              ans = ans*propo;
              ans = modF(ans);
              po = po-2;
          }
          else {
              proni = modF(proni);
              ans = ans*proni;
              ans = modF(ans);
              ni = ni-2;
          }
          k=k-2;
      }
      while (k>0) {
          if (po>0) {
              ans = ans*vcp[po-1];
              ans = modF(ans);
              po--; k--;
          }
          else if (ni>0) {
              ans = ans*(-vcn[ni-1]);
              ans = modF(ans);
              ni--; k--;
          }
      }
  }
  cout << ans << endl;
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