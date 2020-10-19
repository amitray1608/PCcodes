//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
//int dp[1000];
//int rec(int n){
	//if(n == 1)
		//return 0;
	//if(dp[n] != -1)
		//return dp[n];
	//if(~n&1)
		//dp[n] = rec(n/2)+1;
	//else
		//dp[n] = min(rec(n+1)+1, rec(n-1)+1);
	//return dp[n];
//}
int minSteps(int n) 
{ 
    int ans = 0; 
  
    while (n != 1) { 
  
        // If n is even then divide it by 2 
        if (n % 2 == 0) 
            n /= 2; 
  
        // If n is 3 or the number of set bits 
        // in (n - 1) is less than the number 
        // of set bits in (n + 1) 
        else if (n == 3 
                 or __builtin_popcount(n - 1) < __builtin_popcount(n + 1)) 
            n--; 
        else
            n++; 
  
        // Increment the number of steps 
        ans++; 
    } 
  
    // Return the minimum number of steps 
    return ans; 
} 
string longDivision(string number, int divisor) 
{ 
    string ans; 

    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while ((int)number.size() > (int)idx) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
      
    if (ans.length() == 0) 
        return "0"; 
          return ans; 
} 
int recc(string s){
	int n = s.size(), count = 0;
    while (n > 0) {
		if(n == 1){
			if((int)(s[n-1] - '0') == 3){
				count+=2;
				break;
			}
			if((int)(s[n-1] - '0') == 1)
				break;
		}
			if ((int)(s[n-1] - '0')% 2 == 0) {
				s = longDivision(s, 2);
				n = s.size();
				count++;
			}else{
				int x;
				if(n == 1){
					x = s[0]-'0';
				}else{
					x = s[n-2]-'0';
					x *= 10;
					x += s[n-1]-'0';
					cout << x << endl;
				}
				if ((x-1)%4 == 0){
					x = (int)s[n-1]-'0';
					s[n-1] = (x-1) + '0';
					count++;
				}else{
					x = (int)s[n-1]-'0';
					s[n-1] = (x+1) + '0';
					count++;
				}
			}
    }
  
   return count; 
}

void solve(){
	string n;
	cin >> n;
	int ans = recc(n);
	cout << ans << endl;
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
