#include<iostream>
using namespace std;

void selection_sort(int a[], int n) {
  for(int i = 0; i < n-1; i++) {
    int mini = i;
    for(int j = i+1; j < n; j++)
      if(a[j] < a[mini])
        mini = j;
    swap(a[mini], a[i]);
  }
}

int main() {
	int n;
	cin >> n;
  int a[n];
  for(int &i : a) cin >> i;
  selection_sort(a, n);
  for(int i : a) cout << i << ' ';
  cout << endl;
	return 0;
}
