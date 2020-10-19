//“Make it work, make it back, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 2e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	// int maxi = *max_element(a, a+n);
	map<int, int>check;
	// vector<pair<int, int>>ans;
    unordered_map<int, int> checkf, checkb;
    vector<int> front(n,0), back(n,0);
	//bool flag = true;
	//for(int i; i < n; i++){
		//check[a[i]]++;
		//if(check[a[i]] == 3) flag = false;
	//}
	//if(!flag){
		//cout << 0 << endl;
	//}
	int maxi = INT_MIN, mini = 1;
        for(int j = 0; j<n; j++){
            maxi = max(maxi, a[j]);
            if(checkf.find(a[j]) == checkf.end()){
                checkf[a[j]] = 1;
                if(maxi-mini+1 == checkf.size()){
                    front[j] = checkf.size();
                }
            }
            else{	
                break;
            }
        }
        mini=1, maxi=INT_MIN;
        for(int j = n-1; j >= 0; j--){
            maxi = max(maxi, a[j]);
            if(checkb.find(a[j]) == checkb.end()){
                checkb[a[j]] = 1;
                if(maxi-mini+1 == checkb.size()){
                    back[j] = checkb.size();
                }
            }
            else{
                break;
            }
        }
        int count=0;
        for(int j=0; j < n-1; j++){
            if((front[j] != 0) && (back[j+1] != 0)){
                count++;
            }
        }
        cout << count << endl;
        for(int j=0;j<n-1;j++){
            if((front[j] !=0 ) && (back[j+1] != 0)){
                cout << front[j] << " " << back[j+1] << endl;
            }
        }

}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
	
