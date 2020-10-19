#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//ll dp[10000][10000];
//ll a[10000][10000];

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <=t; tt++){
       cout << "Case #" << tt << ": ";
		int n, k;
		cin >> n >> k;
		vector<int>a(n), d(n);
		d[0] = 0;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 1; i < n; i++){
			d[i] = a[i]-a[i-1];
		}
		if(k == 1){
			ll maxi = 0, pos = 0;
			for(int i = 0; i <= n-1; i++){
				if(maxi < d[i]){
					pos = i;
					maxi = d[i];
				}
			}
			d[pos] = (d[pos]+1)/2;
			cout << *max_element(d.begin(), d.end()) << endl;
		}else{
			int maxi = 0, m , in = 0, ans = 0;
			pair<int, int>pr;
	    priority_queue<pair<int,int>> pq;
	    vector<int>::iterator it;
	    for(int i = 0; i < n-1; i++){
	            pq.push(make_pair(d[i], i));
	            if(maxi < d[i]){
	                m = d[i];in =i;
	            }
	        }
	    pr = pq.top();
		pq.pop();
	    while(k--){
	      int q = -1;
	        q = m; q=pr.first;in=pr.second;
	        it = a.begin();
	        a.insert(it+in, (a[in-1]+a[in])/2);
	        it = d.begin();
	        d.insert(it+in,a[in]-a[in-1]);
	        pq.push(make_pair(d[in], in));

	        d[in+1]=(a[in+1]-a[in]);
	        pq.push(make_pair(d[in+1],in+1));
	        q=-1;

            pr=pq.top();pq.pop();
            q=pr.first;
            in=pr.second;
	        m = (q<m)?q:m;
	    }
	    ans = m;
    	cout << ans << endl;
		}
	}
    
}
