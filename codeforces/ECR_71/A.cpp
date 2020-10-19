#include<bits/stdc++.h>
using namespace std;

int main()
{
		int t;
		cin >> t;
		while(t--)
		{
			int b, p, f, dollar=0;
			cin >> b >> p >> f;
			int h, c;
			cin >> h >> c;
			int bun = b/2;
			if(h>c)
			{
				dollar += h*min(bun, p);
				bun-=p;
				dollar += c*min(f, max(0, bun));
			}
			else
			{
				dollar += c*min(bun, f);
				bun-=f;
				dollar += h*min(max(0, bun), p);
			}
			
			cout << dollar << endl;
		}
}
