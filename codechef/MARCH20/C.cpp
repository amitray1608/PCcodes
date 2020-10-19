#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++){
		int r, c;
		cin >> r >> c;
		vector<int>s;	
		vector<pair<int, int>>ans;
		if(r != 1 or c != 1){
			ans.push_back({(r+c)/2, (r+c)/2 });
			ans.push_back({1, 1});	
		}	
		int j = 3, x = 1;
		for(int i = 2; i <= 8; i++){
			if(i == 8)
				ans.push_back({8, 8});
			else{
			ans.push_back({i, i});
			ans.push_back({x, (j)});
			ans.push_back({i, i});
			ans.push_back({(j), x});
			ans.push_back({i, i});
			}
			if(i == 4)
				j = 0, x = 8;	
				
			j+=2;
		}
		cout << ans.size() << endl;
		for(auto cx : ans){
			cout << cx.first << " " << cx.second << endl;
		}
	}
}
