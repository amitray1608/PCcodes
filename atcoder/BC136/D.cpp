#include<bits/stdc++.h>
using namespace std ;
int main () {
  
  string s ;
  cin >> s ;
  
  int N=(int)s.length() ;
  int l[N] , r[N] ;
  
  for(int i =0 ; i < N ;i++) {
    
    if(i == 0) {
      if(s[i]=='R') l[i] = i ;
      else l[i] = -1 ;
    }
    else {
      if(s[i]=='R') l[i] = i ;
      else l[i] = l[i - 1] ;
    }
  }
  
  for(int i = N - 1; i >=0 ;i--) {
    if(i == N - 1) {
      if(s[i] =='L') r[i] = i ;
      else r[i] = - 1;
    }
    else {
      if(s[i]=='L') r[i] = i ;
      else r[i] = r[i + 1]; 
    }
  }
  
  int t[N] ;
  for(int i = 0 ; i < N ;i++)
    t[i] = 0 ;
  for(int i =0 ; i  < N ;i++)
  {
    if(s[i]=='R'){
      if(r[i] == -1) t[N - 1] ++ ;
      else{
        if( (r[i] - i - 1)%2 == 0 ) t[r[i] - 1]++ ;
        else t[r[i]]++ ;
      }
    }
    else {
      
      if(l[i] == -1) t[0] ++ ;
      else{
        if((i - l[i] - 1)%2 == 0) t[l[i] + 1]++ ;
        else t[l[i]]++ ;
      }
    }
  }
  
  for(int i =0 ; i < N ;i++)
    cout<<t[i]<<" " ;
  cout<<endl;
  return 0;
}
