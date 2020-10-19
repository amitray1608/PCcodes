//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<char> pref, suf, mid;
    int flag = 1, L = 0, R, tp = 0;
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]){ 
            flag = 0; 
            L = i; 
            break;
        }
        pref.push_back(s[i]);
        tp = i;
    }
    if(flag){
        cout << s;
        cout << endl;
        return;
    }
    R = n-1-L;
    for(int j = L; j <= n-1; j++){
        int tmp = 1;
        for(int i = L; i <= j; i++){
            if(s[i] != s[j+L-i]) tmp = 0;
        }
        if(tmp){
            suf.resize(0);
            for(int i = L; i <= j; i++) 
                suf.push_back(s[i]);
        }
    }
    for(int j = R; j >= 0; j--){
        int tmp = 1;
        for(int i = j; i <= R; i++){
            if(s[i] != s[R+j-i]) tmp = 0;
        }
        if(tmp){
            mid.resize(0);
            for(int i = j; i <= R; i++) 
                mid.push_back(s[i]);
        }
    }
    if((int)suf.size() == 0 && (int)mid.size() == 0){
     
        for(int i = 0; i < (int)pref.size(); i++)
            cout << pref[i];
        cout << pref[tp+1];
        for(int i = (int)pref.size(); i >= 0; i--)
            cout << pref[i];
   
    }else if((int)suf.size() > (int)mid.size()){
	
    	for(int i = 0; i<(int)pref.size(); i++)
            cout << pref[i];
        for(int i = 0; i < (int)suf.size(); i++) 
            cout << suf[i];
        for(int i = (int)pref.size()-1; i>=0; i--)
            cout << pref[i];
   
    }else{

        for(int i = 0; i < (int)pref.size(); i++) 
            cout << pref[i];
        for(int  i = 0; i < (int)mid.size(); i++)
             cout << mid[i];
        for(int i = (int)pref.size()-1; i >= 0; i--)
             cout << pref[i];
   
    }
    cout << endl;
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
