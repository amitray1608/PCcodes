#include<bits/stdc++.h>
using namespace std;
void fill(int a[], int n){
	for(int i = 0; i <= 2*n; i++){
		a[i] = i;
	}
}
void root(int a[], int x){
	if(a[x] == x)
		return x;
	else 
		return root(a, a[x]);
}
void unions(int a[], int x, int y){
	int u = root(x);
	int v = root(y);
	a[u] = v;
}

int main(){
	int n;
	cin >> n;
	int a[2*n+1];
	fill(a, n);
	for(int i = 0; i < n ; i++){
		int x, y;
		cin >> x >> y;
		unions(a, x, y);
	}
	int mini = INT_MAX, maxi = 0;
	int ans[2*n+1] = {0};
	for(int i = 0; i <= 2*n; i++){
		ans[a[i]]++;
		mini = min(mini, ans[a[i]]);
		maxi = max(maxi, ans[a[i]]);
	}
	
	cout << mini << " " << maxi << endl;
	return 0;
