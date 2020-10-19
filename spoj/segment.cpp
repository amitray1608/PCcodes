#include<bits/stdc++.h>
using namespace std;
void build(int n, int beg, int end, int a[], int tree[]){
	if(beg == end){
		tree[n] = a[beg];
	}else{
		int mid = (beg+end)/2;
		build(2*n+1, beg, mid, a, tree);
		build(2*n+2, mid+1, end, a, tree);
		tree[n] = tree[2*n+1]+tree[2*n+2];
	}
}
void update(int n, int s, int e, int pos, int val, int tree[], int a[]){
	if(s == e){
		a[pos] = val;
		tree[n] = val; 
	}else{
		int mid = (s+e)/2;
		if(s <= pos and pos <= mid)
			update(2*n+1, s, mid, pos, val, tree, a);
		else
			update(2*n+2, mid+1, e, pos, val, tree, a	);
			
		tree[n] = tree[2*n+1]+tree[2*n+2];
	}	
}

int query(int n, int l, int r, int k, int tree[]){
	if(l == r && k == 1)
		return r;
	int mid = (l+r)/2;
	int lf, rt;
	lf = tree[2*n+1];
	rt = tree[2*n+2];
	if(k > lf){
		k = k- lf;
		return query(2*n+2, mid+1, r, k, tree);
	}else
		return query(2*n+1, l, mid, k, tree);
}

int main(){
	int n;
	cin >> n;
	int tree[4*n], a[n];	
	memset(a, 1, sizeof a);
	memset(tree, 1, sizeof tree);
	memset(tree, 1, sizeof tree);
	build(0, 0, n-1, a, tree);
	int q;
	cin >> q;
	while(q--){
		int typ, pos;
		cin >> typ >> pos;
		if(typ == 0)
			update(0, 0, n-1, pos, 0, tree, a);
		else{
			if(pos > tree[0])
				cout << -1 << endl;
			else
				cout << query(0, 0, n-1, pos, tree) << endl;
			
		}
	}
	return 0;
}
