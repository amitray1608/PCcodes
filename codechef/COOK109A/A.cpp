#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int a, b;
	cin >> a >> b;
	int sum = a+b;
	string s = to_string(sum);
	
	int count = 0;
	for(char c : s)
	{
		if(c == '0')	
			count += 6;
		if(c == '1')	
			count += 2;
		if(c == '2')	
			count += 5;
		if(c == '3')	
			count += 5;
		if(c == '4')	
			count += 4;
		if(c == '5')	
			count += 5;
		if(c == '6')	
			count += 6;
		if(c == '7')	
			count += 3;
		if(c == '8')	
			count += 7;
		if(c == '9')
			count += 6;
	}
	cout << count << endl;
	
		
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
