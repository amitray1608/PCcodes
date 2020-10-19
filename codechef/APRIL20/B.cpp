#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int f = 1;
		for(int i = 0; i < n; i++){			
			if(a[i] == 1){
			int j = i+1;
			while(j < i+6 && j < n){
				if(a[j] == 1){
					f = 0;
				}
				j++;
			}
					
			}
		}
		if(f == 1)
			cout<<"YES"<<endl;
		else
			cout << "NO" << endl;
	}
}
