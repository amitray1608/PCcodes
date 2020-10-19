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
	int n;
	string s;
	cin >> n >> s;
	vector<char> s1(n), s2(n);
	int p = n-1;
	for(int i = 0 ;i<n; i++){  
		if(s[i] == '2'){
			s1[i] = '1';
			s2[i] = '1';
		}
		else if(s[i]=='0'){
			s1[i] = '0';
			s2[i] = '0';
		}else if(s[i]=='1'){
			s1[i] = '1';
			s2[i] = '0';
			p = i;
			break;
		}
	}
	for(int i = p+1; i<n; i++){
		if(s[i] == '2'){
			s1[i] = '0';
			s2[i] = '2';
		}else if(s[i] == '1'){
			s1[i] = '0';
			s2[i] = '1';	
		}else if(s[i] == '0'){
			s1[i] = '0';
			s2[i] = '0';
		}
	}	
	for(char c : s1)
		cout << c;
	cout << endl;
	for(char c : s2)
		cout << c;
	cout << endl;
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

