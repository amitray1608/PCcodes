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
	string s;
	cin >> s;
	map<pair<int, int>, int>bi1, bi2;
	int x = 0, y = 0, u = 0;
		for (auto a: s)
		{
			if (a=='N')
			{
				if (bi1[{x,y+1}]) u+=1;
				else u+=5,bi1[{x,y+1}]=1;
				++y;
			}
			if (a=='S')
			{
				if (bi1[{x,y}]) u+=1;
				else u+=5,bi1[{x,y}]=1;
				--y;
			}
			if (a=='E')
			{
				if (bi2[{x+1,y}]) u+=1;
				else u+=5,bi2[{x+1,y}]=1;
				++x;
			}
			if (a=='W')
			{
				if (bi2[{x,y}]) u+=1;
				else u+=5,bi2[{x,y}]=1;
				--x;
			}
		}
	cout << u << endl;
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
	

