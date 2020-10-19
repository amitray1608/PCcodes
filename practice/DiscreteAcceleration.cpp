//Ryuzaki
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sine() {
  ll n, l;
  cin >> n >> l;
  vector<ll> v(n);
  for(ll &i : v) cin>> i;
  double starta = 1, startb = 1, enda = 0, endb = l, t = 0;
  ll i = 0, j = n-1;
  while(i <= j){
    double TS = (v[i] - enda) / starta;
    double TE = (endb - v[j]) / startb;
    if(TS < TE){
      t += TS;
      enda = v[i];
      starta += 1;
      endb -= (TS * startb);
      i++;
    }
    else if(TS > TE){
      t += TE;
      endb = v[j];
      startb += 1;
      enda += (TE * starta);
      j--;
    }
    else{
      t += TS;
      enda = v[i], endb = v[j];
      starta += 1, startb += 1;
      i++, j--;
    }
    if(enda >= endb) break;
  }
  if(enda < endb){
      t += (endb - enda) / (starta + startb);
  }
  cout << t << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  cout << fixed << setprecision(10);
  while(t--) sine();
  return 0;
}
