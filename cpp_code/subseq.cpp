#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void printsubseq(string s, int n, int index = -1, string curr = ""){
	if(index == n)
		return;
	cout << curr << endl;
	for(int i = index+1; i < n; i++){
		curr +=	s[i];
		printsubseq(s, n, i, curr);
		curr = curr.erase(curr.size()-1);
	}
	return;
}

string subsequence(string s, int binary, int n){
	string sub = "";
	for(int j = 0; j < n; j++)
		if(binary & (1<<j))
			sub += s[j];
	
	return sub;
}

void subs(string s, int n){
	map<int, set<string>> store;
	int lim = pow(2, n);
	for(int i = 0; i <= lim-1; i++){
		string sub = subsequence(s, i, n);
		store[sub.length()].insert(sub);
	}
	for(auto it : store)
		for(auto ii : it.second)
			cout << ii << endl;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	//subs(s, n);
	printsubseq(s, n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
