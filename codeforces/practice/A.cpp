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
	char ch[605], temp[605];
	string str[4] , str2[7];
    for(int j = 0 ; j < 3; j++)
    {
        cin >> ch;
        int len = strlen(ch), k = -1;
        for(int i = 0; i < len; i++)
        {
            if( ch[i] >= 'a' && ch[i] <= 'z' ) temp[++k] = ch[i];
            else if( ch[i] >='A' && ch[i] <= 'Z' ) temp[++k] = ch[i] + 32;
            else continue;
        }
        temp[++k] = '\0';
        str[j] = (string)temp;
    }
    str2[0] = str[0] + str[1] + str[2];
    str2[1] = str[0] + str[2] + str[1];
    str2[2] = str[1] + str[0] + str[2];
    str2[3] = str[1] + str[2] + str[0];
    str2[4] = str[2] + str[0] + str[1];
    str2[5] = str[2] + str[1] + str[0];
    int n;
    cin >> n;
    string t;
    while( n-- )
    {
        cin >> ch;
        int len = strlen(ch), k = -1;
        for(int i = 0; i < len; i++)
        {
            if( ch[i] >= 'a' && ch[i] <= 'z' ) temp[++k] = ch[i];
            else if( ch[i] >='A' && ch[i] <= 'Z' ) temp[++k] = ch[i] + 32;
            else continue;
        }
        temp[++k] = '\0';
        t = string(temp);
        int j;
        for(j = 0; j < 6; j++)
            if( t == str2[j] )  { 
				cout<<"ACC\n"; 
				break; 
			}
        if( j == 6 )  
			cout<<"WA\n"; 
    }
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
