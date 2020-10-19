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
	int a[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
	int n;
	cin >> n;
		bool flag = false;
	while(n--){
		int c;
		cin >> c;
		for(int i = 0; i < 3; i++)
		{	for(int j= 0; j <3;  j++){
				if(a[i][j] == c){
						a[i][j] = -1;
					}
			}
		}
	}
	for(int i = 0; i<3; i++)
	{int count = 0;
		for(int j = 0; j <3; j++){
			if(a[i][j] == -1)
				count++;
		}
		if(count == 3)
			flag = true;
	}
	for(int i = 0; i<3; i++)
	{
		int count = 0;
		for(int j = 0; j <3; j++){
			if(a[j][i] == -1)
				count++;
		}
		if(count == 3)
			flag = true;
	}		
	int count = 0;

	for(int i= 0; i<3; i++)
	{
		if(a[i][i] == -1)
			count++;
	}
	if(count == 3)
		flag = true;
		
	count = 0;
	for(int i= 0; i<3; i++)
	{
		if(a[i][3-i-1] == -1)
			count++;
	}	if(count == 3)
		flag = true;
	
	if(flag)	
	cout <<"Yes";
	else
		cout <<"No";
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
