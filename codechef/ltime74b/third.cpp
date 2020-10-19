#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

void solve(){
        int n;
		cin >> n;
		ll a[n], count=0;
        bool front[n] = {false};
        bool back[n] = {false};
        back[n-1] = true;
        front[0] = true;
		for(ll i=0; i<n; i++) 
            cin >> a[i];
		
        for(ll i = 1; i < n; i++)
			if(a[i] > a[i-1]) 
                if(front[i-1])
                    front[i] = true;
		
		for(ll i= n-2; i >= 0; i--)
			if(a[i] < a[i+1]) 
                if( back[i+1])
                    back[i] = true;
		
	
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(i==0 && j==n-1){
					continue; 
				}
				else if(i==0){
					if(back[j+1]) count++;
				}
				else if(j==n-1){
					if(front[i-1]) count++;
				}
				else {
					if(front[i-1]&& back[j+1] && a[i-1] < a[j+1]){
						count++;
					}
				}
			}
		}
		cout << count << endl;
    
}

int main(){
		int t;
		cin >> t;
		while(t--)
		{
            //memset(DP, 0, sizeof(DP));
			solve();
		}
	return 0;
}


