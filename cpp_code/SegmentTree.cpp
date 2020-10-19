#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int tree[2*N];

// SUM RANGE QUERY
void build(int a[], int n){
	for(int i = 0; i < n; i++)
		tree[n+i] = a[i];
	for(int i = n-1; i >= 0; i--)
		tree[i] = tree[i<<1] + tree[i<<1|1];
}
void update(int p, int k, int n){
	tree[p+n] = k;
	p = p+n;
	for(int i = p; i > 1 ; i>>=1)
		tree[i>>1] = tree[i] + tree[i^1];
}

void query(int l, int r, int n){
	int ans = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1)
			ans += tree[l++];
		if(r&1)
			ans += 	tree[r--];
	}
			
}

int main(){
	memset(tree, 0, sizeof tree);
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	
	build(a, n);
	for(int i = 1 ; i < 2*n; i++)
		cout << tree[i] << " ";
		
	cout << endl;
	//int q;
	//cin >> q;
	//while(q--){
		//int 
	//}
	return 0;
}
