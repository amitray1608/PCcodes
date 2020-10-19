//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const ll MOD = 998244353;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll ansz = 1, anso = 1, ansa = 1, ansA = 1;
stack<ll>ss;
vector<ll>v[100004];
ll pos = 0;
//long long modinv(long long a) {
	//long long b = MOD, u = 1, v = 0;
	//while (b) {
		//long long t = a / b;
		//a -= t * b; swap(a, b);
		//u -= t * v; swap(u, v);
	//}
	//u %= MOD;
	//if (u < 0) u += MOD;
	//return u;
//}

ll power(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		n = n >> 1;
	}
	return ans;
}
ll modinv(ll x){
	return power(x, MOD-2);
}

void And(){
	vector<ll>x;
	ll p = ss.top();
	deb(p);
	x = v[p];
	ss.pop();
	ll z = x[0], o = x[1], a = x[2], A = x[3];
	x.clear();
	p = ss.top();
	x = v[p];
	ss.pop();
	ll zz = x[0], oo = x[1], aa = x[2], AA = x[3];
	ll zzz = (z*zz+z*oo+z*aa+z*AA) + o*zz + a*AA + A*aa + a*zz+ A*zz;
	ll ooo = oo*o;
	a = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	A = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	vector<ll>ans = {zzz, ooo, a, A};
	ss.push(pos);
	v[pos] = ans;
	pos++;
}
void Or(){
	vector<ll>x;
	ll p = ss.top();
	deb(p);
	x = v[p];
	ss.pop();
	ll z = x[0], o = x[1], a = x[2], A = x[3];
	x.clear();
	p = ss.top();
	x = v[p];
	ss.pop();
	ll zz = x[0], oo = x[1], aa = x[2], AA = x[3];
	ll ooo = (oo*z+o*zz+o*oo+o*aa+o*AA)+ a*oo + a*AA + A*aa + A*oo;
	ll zzz = zz*z;
	a = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	A = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	vector<ll>ans = {zzz, ooo, a, A};
	ss.push(pos);
	v[pos] = ans;
			pos++;
}
void Xor(){
	vector<ll>x;
	ll p = ss.top();
	deb(p);
	x = v[p];
	ss.pop();
	ll z = x[0], o = x[1], a = x[2], A = x[3];
	x.clear();
	p = ss.top();
	x = v[p];
	ss.pop();
	ll zz = x[0], oo = x[1], aa = x[2], AA = x[3];
	ll zzz = z*zz+o*oo+a*aa+A*AA;
	ll ooo = z*oo+o*zz+a*AA+A*aa;
	a = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	A = ((ll)sqrt(zzz)*(ll)sqrt(ooo))%MOD;
	vector<ll>ans = {zzz, ooo, a, A};
	ss.push(pos);
	v[pos] = ans;
	pos++;

}
void solve(){
	string s;
	cin >> s;
	stack<char>st;
	ll count = 0;
	vector<ll>one = {1, 1, 1, 1};
	//stack<vector<ll>a(4)>ss;
	for(char c: s){
		if(c == '#'){
			count ++;
			ss.push(pos);
			v[pos] = one;
			pos++;
			cout << c << " ";
		}else if(c == ')'){
			char x = st.top();
			cout << x << " ";
			st.pop();
			cout <<st.top() << " ";
			st.pop();
			cout << ')' << " ";
			if(x == '&')
				And();
			else if(x == '|')
				Or();
			else if(x == '^')
				Xor();
	//cout << ansz << " " << anso << " " << ansa << " " << ansA << endl;
		}else
			st.push(c);
	}
	//while(!ss.empty()){
		//cout << ss.top() << " ";
		//ss.pop();
	//}
	//cout << endl;
	//ll ans = power(4LL, count);
	//cout << ans << endl;
	//ans = modinv(ans);
	//cout << ans << endl;
	ll p = ss.top();
	vector<ll>tmp = v[p];
	for(ll i : tmp)
		cout << i << ' ';
		cout << pos << endl;
	//cout << endl;
	//for(int i = 0; i < 5; i++){
		//for(int j = 0; j < 4; j++)
			//cout << v[i][j] << " ";
		//cout << endl;
	//}
	while(!ss.empty())
    ss.pop();
    for(ll i = 0; i < 100004; i++)
		v[i].clear();
	pos = 0;
	//cout << ans*tmp[0] << " " << anso << " " << ansa << " " << ansA << endl;
	//cout << (ansz*ans)%MOD << " " << (anso*ans)%MOD << " " << (ansa*ans)%MOD << " " << (ansA*ans)%MOD << endl;
	//ansz = anso = ansa = ansA = 1LL;
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
/*
1
(((#^#)&#)&(((#^#)&#)&(((#&#)&#)^(((#|#)|#)&#))))

2
#
(#&#)
4
(((#&#)&#)|(#^#))
((#|#)|(#^#))    
((#&#)|((#^#)&(#|#)))
(((#^#)&#)&(#|#))

4
((#&#)|#)
((#^#)&#)
((#|#)|#)
((#&#)&#)
*/
