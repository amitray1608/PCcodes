//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, ax, ay, bx, by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	bool flag = true;
	if (x - ax < a - b)
         flag = false;
	if (bx - x < b - a)
         flag = false;

	if (y - ay < c - d) 
        flag = false;
	if (by - y < d - c) 
        flag = false;

	if (a + b != 0 && ax == bx) flag = false;
	if (c + d != 0 && ay == by) flag = false;

    if(flag)
        cout << "Yes" << endl;
    else    
        cout << "No" << endl;

	//if(ax==x && bx==x && (a>0||b>0)){
		//cout << "No" << endl;
		//return;
	//}
	
	//if(ay==y && by == y && (c>0||d>0)){
		//cout << "No" << endl;
		//return;
	//}
	//if(a > b){
		//a -= b;
		//if(abs(x-ax) < a){
			//cout << "No" << endl;
			//return;
		//}
	//} else {
		//b -= a;
		//if(abs(bx-x) < b){
			//cout << "No" << endl;
			//return;
		//}
	//}
	//if(c > d){
		//c -= d;
		//if(abs(y-ay) < c){
			//cout << "No" << endl;
			//return;
		//}
	//} else {
		//d-=c;
		//if(abs(by-ay) < c){
			//cout << "No" << endl;
			//return;
		//}
	//}
	//cout << "Yes" << endl; 
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
	
