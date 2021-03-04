#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"? "<<i+1<<"\n";
		cin>>a[i];
		if (i==1&&a[i - 1]<a[i])
        {
            cout <<"! "<<i<<"\n";
            break;
       }
       else if(i==n-1)
       {
            if (a[i]<a[i - 1])
            {
               cout << "! "<<i+1<<"\n";
               break;
            }
            if(a[i-1]<min(a[i],a[i-2]))
            {
                cout << "! " <<i<<"\n";
                break;
            }
       }
       if(a[i - 1]<min(a[i - 2],a[i]))
        {
            cout << "! " <<i<<"\n";
            break;
        }
	}
}
