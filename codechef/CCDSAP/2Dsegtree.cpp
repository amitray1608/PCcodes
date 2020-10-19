//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n, m;
int t[1024 << 4][1024 << 4], a[1024][1024];

void buildy(int nx, int lx, int rx, int ny, int ly, int ry) {
  if(lx == ry) {
    if(lx == rx) 
      t[nx][ny] = a[lx][ly];
    else
      t[nx][ny] = t[nx+nx][ny] + t[nx+nx+1][ny];
  } else {
    int mid = (lx+rx) >> 1;
    buildy(nx, lx, rx, ny+ny, ly, mid);
    buildy(nx, lx, rx, ny+ny+1, mid+1, ry);
    t[nx][ny] = t[nx][ny+ny] + t[nx][ny+ny+1];
  }
}

void buildx(int nx, int lx, int rx) {
  if(lx != rx) {
    int mid = (lx + rx) >> 1;
    buildx(nx+nx, lx, mid);
    buildx(nx+nx+1, mid+1, rx);
  } 
  buildy(nx, lx, rx, 1, 0, m-1);
}


int sumy(int nx, int ny, int tly, int try_, int ly, int ry) {
  if(ly > ry) 
    return 0;
  if(ly == tly and try_ == ry)
    return t[nx][ny];
  int tmid = (tly + try_) >> 1;
  return sumy(nx, ny+ny, tly, tmid, ly, min(ry, tmid)) + sumy(nx, ny+ny+1, tmid+1, try_, max(ly, tmid + 1), ry);
}

int sumx(int nx, int tlx, int trx, int lx, int rx, int ly, int ry) {
  if(lx > rx)
    return 0;
  if(lx == tlx and trx == rx) 
    return sumy(nx, 1, 0, m-1, ly, ry);
  int tmid = (tlx + trx) >> 1;
  return sumx(nx+nx, tlx, tmid, lx, min(rx, tmid), ly, ry) + sumx(nx+nx+1, tmid+1, trx, max(lx,tmid+1), rx, ly, ry);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
  if (ly == ry) {
    if (lx == rx)
        t[vx][vy] = new_val;
    else
        t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
  } else {
    int my = (ly + ry) / 2;
    if (y <= my)
        update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
    else
        update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
    t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
  }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
  if (lx != rx) {
    int mx = (lx + rx) / 2;
    if (x <= mx)
        update_x(vx*2, lx, mx, x, y, new_val);
    else
        update_x(vx*2+1, mx+1, rx, x, y, new_val);
  }
  update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

void solve(){
  cin >> n;
  m = n;
  string s;
  memset(t, 0, sizeof t);
  while(true) {
    cin >> s;
    if(s == "END")
      break;
    else if(s == "SET") {
      int x, y, v;
      cin >> x >> y >> v;
      update_x(0, 0, n-1, x, y, v);
    } else {
      int x, y, ex, ey;
      cin >> x >> y >> ex >> ey;
      // int sumx(int nx, int tlx, int trx, int lx, int rx, int ly, int ry)
      int ans = sumx(0, 0, n-1, x, y, ex, ey);
      cout << ans << endl;
    }
  }
  for(int i = 0; i < 15; i++) {
    for(int j = 0; j < 15; j++)
        cout << t[i][j] << ' ';
    cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tx = 1;
  cin >> tx;
  while(tx--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  