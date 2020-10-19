#include<bits/stdc++.h>
#include<time.h>
using namespace std;
using ll = long long;
bitset<1000000000>m;
ll mod = 4294967296;
int printPowerSet(int *set, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    ll count(0);
    unsigned int pow_set_size = pow(2, set_size); 
    ll counter, j; 
  
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++) { 
    int gcd = 0;
    for(j = 0; j < set_size; j++){ 
        /* Check if jth bit in the counter is set 
            If set then print jth element from set */
        if(counter & (1 << j)) 
            gcd = __gcd(gcd, set[j]); 
    } 
    if(gcd == 1)
		count++; 
    } 
    return count;
} 
void solve(){
		int n;
		cin >> n;
		int a[n];
		for(int &i : a) cin >> i;
		int div[10005] = {0};
		for(int i = 0; i < n; i++){
			for(int j = 1; j * j <= a[i]; j++){
				if(a[i] % j == 0){
					div[j]++;
					if(a[i] != j * j)
						div[a[i]/j]++;
				}	
			}
		}
		//cout << "DIVs\n";
		//for(int i = 0; i<15; i++) cout << div[i] << " ";
		//cout << endl;
		int64_t gcd[10004] = {0};
		for(int i = 10000; i > 0; i--){
			if(div[i]){
				gcd[i] = (1LL << div[i]) - 1; 
				for(int j = 2; j <=10000/i; j++)
					gcd[i] -= gcd[j*i];
			}
		}
		//cout << "GCD\n";
		//for(int i = 0; i<15; i++) cout << gcd[i] << " ";
		//cout << endl;
		cout << gcd[1] << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
/*
3
4
2 3 5 7
4
3 4 8 16
3
6 10 15

*/
