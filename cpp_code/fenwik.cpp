//fenwik tree implementation of partial sum update query.
#include<bits/stdc++.h>
using namespace std;
const int siz = 1e6+5;
class fenwik{
	public:
		int n;
		int BIT[siz] ={ 0 };

	void update(int x, int p){
		for(; p <=n; p += p&-p)
			BIT[p] += x;
	}
	
	int  query(int r){
		int sum = 0;
		for(; r >0; r -= r&-r)
			sum += BIT[r];
		
		return sum;
	}
	int partial(int l, int r){
		return query(r) - query(l);
	}

	void solve(){
		cin >> n;
		for(int i = 1; i<=n; i++){
			int x;
			cin >> x;
			update(x, i);
		}
		int q;
		cin >> q;
		while(q--){
			int typo;
			cin >> typo;
			if(typo == 1){
				int v, p;
				cin >> v >> p;
				update(v, p);
			}
			else{
				int l, r;
				cin >> l >> r;
				cout << partial(l-1, r) << endl;
			}
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >>  t;
	while(t--)
	{
		fenwik obj;
		obj.solve();
	}
		return 0;
}
