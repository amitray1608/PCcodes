//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 2001;
const int MOD = 1e9;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool isnum(char c){
    if(c > '1' && c <= '9')
		return true;
	else
		return false;
}
bool isclose(char c){
	if(c == ')')
		return true;
	else
		return false;
}
void solve(){
    string s;
	cin >> s;
    int n = (int)s.size();
	int digit[siz] = {0}, times = 0;
	int x = 1, y = 1, X = 0, Y = 0;
	for(int i = 0; i < n; i++){
		
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int times = 1, tt = 1;
		cin >> times;
		while(times--){
			cout << "Case #" << tt++ << ": "; 
			solve();
		}
	return 0;
}	
