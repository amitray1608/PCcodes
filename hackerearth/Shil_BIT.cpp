#include<bits/stdc++.h>
using namespace std;
int BIT[100004][26]={0};
string s;
void update(char c, int n, int pos, int inc){
		
		for(int i = pos; i <=n; i += i&-i){
			 
		}
}

bool query(int l, int r){
		
		if((r-l) & 1){
			for(r = 0; 	)
		}
		
}

int main(){
	int n, q;
		cin >> n >> q;
		cin >> s;
	 
	 for(int i = 0; i<n; i++)
		update(s[i], n, i);
		
	while(q--){
		int typo;
			cin >> typo;
		if(typo == 1){
				int pos;
				char c;
				cin >> pos >> c;
				update(c, n, pos);
		}else{
				int l, r;
				cin >> l >> r;
				cout << query(l, r) << endl;
		}
	}
		return 0;
}
