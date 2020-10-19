#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long int t, test, i, n, B, N, wt, h;
	int a[1000000];
	cin>>t;
	test = 1;
  
	while(t--){
		cin>>n>>B;
		for(i=0; i<n; i++) cin>>a[i];
		N = n/sizeof(a[0]);
		sort(a, a+N);
		wt = 0;
		h = 0;
    	for(i=0; i<n; i++)
    		if ((wt<=B) && (wt+a[i] <= B)){
    			wt += a[i];
    			h++;
    		}
        cout<<"Case #"<<test<<": "<<h<<endl;
        test++;
	}
	
	return 0;
}
