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
	//char c[] ={'0', '1', 'a', 'A'};
	string c = "01aA", p = "";
	//cout << c << endl;
	vector<string>s, ss;
	//int n = 4;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			//cout << c[i] << "&" << c[j] << endl;
			p += c[i];
			p +='&';
			p +=c[j];
			s.push_back(p);
			//cout << p << endl;
			p ="";
		}
	}
	for(string x : s){
		for(int i = 0; i < 4; i++){
			p += x;
			p += '|';
			p += c[i];
			ss.push_back(p);
			p ="";
		}
	}int count = 0;
	int a[4] = {9, 1, 3, 3};
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < a[i]; j++){
			for(int k = 0; k < 4; k++){
				cout << c[i] << " | " << c[k] << endl; 
				count++;
			}
		}
	}
	cout << count << endl;
	//for(string i : ss)
		//cout << i << endl;
		
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
/*
0 | 0 = 0
0 | 1 = 1
0 | a = a
0 | A = A
0 | 0 = 0
0 | 1 = 1
0 | a = a
0 | A = A
0 | 0 = 0
0 | 1 = 1
0 | a = a
0 | A = A
0 | 0 = 0
0 | 1 = 1
0 | a = 1
0 | A = A
0 | 0 = 
0 | 1
0 | a
0 | A
0 | 0
0 | 1
0 | a
0 | A
0 | 0
0 | 1
0 | a
0 | A
0 | 0
0 | 1
0 | a
0 | A
0 | 0
0 | 1
0 | a
0 | A
//
1 | 0 = 1
1 | 1 = 1
1 | a = 1
1 | A = 1
//
a | 0 = a
a | 1 = 1
a | a = a
a | A = 1
a | 0 = a
a | 1 = 1
a | a = a
a | A = 1
a | 0 = a
a | 1 = 1
a | a = a
a | A = 1
//
A | 0 = A
A | 1 = 1
A | a = 1
A | A = A
A | 0 = A
A | 1 = 1
A | a = 1
A | A = A
A | 0 = A
A | 1 = 1
A | a = 1
A | A = A
64
*/
/*	
0&0|0
0&0|1
0&0|a
0&0|A
0&1|0
0&1|1
0&1|a
0&1|A
0&a|0
0&a|1
0&a|a
0&a|A
0&A|0
0&A|1
0&A|a
0&A|A
1&0|0
1&0|1
1&0|a
1&0|A
1&1|0
1&1|1
1&1|a
1&1|A
1&a|0
1&a|1
1&a|a
1&a|A
1&A|0
1&A|1
1&A|a
1&A|A
a&0|0
a&0|1
a&0|a
a&0|A
a&1|0
a&1|1
a&1|a
a&1|A
a&a|0
a&a|1
a&a|a
a&a|A
a&A|0
a&A|1
a&A|a
a&A|A
A&0|0
A&0|1
A&0|a
A&0|A
A&1|0
A&1|1
A&1|a
A&1|A
A&a|0
A&a|1
A&a|a
A&a|A
A&A|0
A&A|1
A&A|a
A&A|A
*/
