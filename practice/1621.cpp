iik,falsfdjsdfsiik,falsfdjsdfsdiik,falsfdjsdfsdiik,falsfdjsdfsdiik,falsfdjsdfsdd#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  set<int> st;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  cout << (int)st.size();
}
ii{
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Caiise #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashiteii

imap <C-d> <C-[>diwi
noremap <F4> :!<CR>
map <C-DOWN> <C-E>
map <C-UP> <C-Y>[<65;37;20M
map <C-c> "+y<CR>
noremap <c-A> :%y+<CR>
noremap <c-S> :w<CR>
noremap <c-T> :tabn<CR>
noremap <c-N> :tabe<CR>
