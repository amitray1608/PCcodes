#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
		string s, r;
		cin >> s >> r;
		ll freq_s[27] ={0}, freq_r[27] = {0};
		for(char c:s)
		{
			freq_s[(ll) ((c-'a')+1)]++;
		}
		for(char c:r)
		{
			freq_r[(ll) ((c-'a')+1)]++;
		}
		/*
		for(ll i = 1; i<26; i++)
		{
			cout << "s " << i << " " << freq_s[i] << " ";
						cout << "f " << i << " " << freq_r[i] << endl;
		}*/
		
		bool flag = true;
		for(ll i = 1; i<27; i++)
		{
			if(freq_s[i] <= freq_r[i])
			continue;
			
			else
			{	flag = false;
				break;
			}
		}
		string beg, last;
		if(!flag)
		{
			cout << "Impossible\n";
		}
		else
		{
			for(char c : s)
			{
			freq_r[(ll) ((c-'a')+1)]--;
			}
			for(ll i=1; i<=26; i++)
			{
				for(int j=0; j < freq_r[i]; j++)
				{
					if((char)(i-1 +'a') <= s[0])
						beg += (char)(i-1 + 'a');
					else
						last += (char)(i-1 +'a');
				}
			}
			sort(beg.begin(), beg.end());
			sort(last.begin(), last.end());
			beg.append(s);
			beg.append(last);
			cout << beg << "\n";
		}
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
