#include<bits/stdc++.h>
using namespace std;
int stackk[100], top = -1;

void pop() {
  if(top == -1) {
    cout << "Parking lot is empty." << endl;
  } else {
    cout << stackk[top--] << endl; 
  }
}

void push(int v) {
  if(top == 100) {
    cout << "Parking lot is full." << endl;
  } else {
    stackk[++top] = v;
  }
}

int main(){
  cout << "Enter the no of cars." << endl;
  int n;
  cin >> n;
  cout << "Enter the car no in which they enter the parking lot." << endl;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    push(x);
  }
  cout << "Exit order of the cars" << endl;
  while(top > -1) {
    pop();
  }
  return 0;
}
