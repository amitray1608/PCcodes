#include<bits/stdc++.h>

using namespace std;

void pythagoras(int A){
  for (int i = 0; i <= A / 2; i++) {
    int val = A - (i * i);
    int ce = ceil(sqrt(val));
    int fl = floor(sqrt(val));
    if (ce < i) break;
    if (ce * fl == val) {
      cout << "(" << i << ',' << ce << ") ";
    }
  }
}
int main(){
  int A;
  cout << "write a number \n";
  cin >> A;
  pythagoras(A);
  return 0;
}
