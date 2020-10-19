#include<bits/stdc++.h>
#define int long long int 
#define TRY_HARD ios_base::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
using namespace std;

//TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD TRY_HARD 

signed main()
 {
	TRY_HARD ;
	int t ;
	 cin >> t ;
	 while ( t-- )
	 {
	 	int n , k ;
	 	cin >> n >> k ;
	 	int a[n] ;
	 	map < int , int > m ; 
	 	for ( int i = 0 ; i < n ; i++ )
	 	cin >> a[i] ;
	 	int Max = INT_MIN , ans = 0 ;
	 	for ( int i = 0 ; i < n/2 ; i++ )
	 	{
	 		int sum = 0 ;
	 		sum = sum + a[i] + a[n-i-1] ;
	 		m[sum]++ ;
	 		
	 		if ( Max < m[sum] )
	 		{
 				Max = m[sum] ;
				ans = sum ;
	 		}
	 	
	 	}
	 	int cnt = 0 ;
	 	for ( int i = 0 , j = n-1 ; i < j;  i++ , j-- )
	 	{
	 		if ( (a[i] + a[j] ) != ans )
	 	
	 		{
	 			int p = ans - a[i] ;
	 			int q = ans - a[j] ;
	 			if ( (p > k) and ( q > k ))
	 			cnt += 2;
	 			else
	 			cnt++ ;
	 			
	 		}
	 	}
	 	cout << min(cnt , n / 2) << '\n' ;
	 	
	 }
	
}
