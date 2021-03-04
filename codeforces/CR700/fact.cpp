
#include <bits/stdc++.h>
using namespace std;
int primeCount[1000007];
void preComp(int n = 1000007){
	bool prime[n + 1];
    memset(prime, true, sizeof(prime));
	prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
	for(int i=1;i<=n;i++)
	{
        if(prime[i])
        {
        	primeCount[i] = primeCount[i-1]+1;
        }
        else primeCount[i] = primeCount[i-1];
	}
}

int main() {
	int t;
	cin>>t;
	preComp();
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		cout<<primeCount[x]<<" "<< primeCount[y];
		if(primeCount[x] > primeCount[y])
		{
			cout<<"Divyam";
		}
		else
		{
			cout<<"Chef";
		}
		cout<<endl;
	}
	return 0;
}

