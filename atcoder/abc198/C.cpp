
#include<bits/stdc++.h>

using namespace std;
double distanceCalculate(double x1, double y1, double x2, double y2) {
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  

	return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  double r, x, y;
  cin >> r >> x >> y;
  double dist = distanceCalculate(0.0, 0.0, x, y);
  cout << ceil(dist / r) << '\n'; 
  return 0;
} //Hajimemashite

