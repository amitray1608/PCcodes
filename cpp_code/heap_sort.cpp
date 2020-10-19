//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void heapify(int a[], int n, int i){
	int large = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l < n && a[l] > a[large])
		large = l;
		
	if(r < n && a[r] > a[large])
		large = r;
		
	if(large != i){
		swap(a[i], a[large]);
		heapify(a, n, large);
	}
}

void heap_sort(int a[], int n){
	for(int i = n/2-1; i >= 0; i--)
		heapify(a, n, i);
		
	for(int i = n-1; i >= 0; i--){
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
	
}


void solve(){
	int n;
	cin >> n;
	int a[n];
	
	for(int &i : a)
		cin >> i;
	
	heap_sort(a, n);
	
	for(int i : a)
		cout << i << " ";
  cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
return 0;
}
