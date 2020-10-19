#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

vector<bool> fun(vector <bool> a, vector<bool> b, int n){
	vector<bool>res;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i])
			res.push_back(0);
		else
			res.push_back(1);
	}
	return res;
}

int main(){
		int t;
		cin >> t;
		while(t--){
		int n;
		cin >> n;
		string x, y;
		cin >> x >> y;
		vector<int>a(n);
		vector<int>b(n);
		for(int i = 0; i < n; i++){
			a[i] = (int)((char)x[i]-'0');
		}
		for(int i = 0; i < n; i++){
			b[i] = (int)((char)y[i] - '0');
		}
		set<vector<int>>st;
		do{
			st.insert(a);
		}while(next_permutation(a.begin(), a.end()));
		do{
				st.insert(b);
			}while(next_permutation(b.begin(), b.end()));
			

		cout << st.size()%1000000007 << endl;
	}
	return 0;
}
