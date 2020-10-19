#include<bits/stdc++.h>
using namespace std;
// source - https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
struct Point { 
    int x; 
    int y; 
}; 
  
 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
 
int orientation(Point p, Point q, Point r) 
{ 

    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  
  
    return (val > 0)? 1: 2; 
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 

    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) 
        return true; 

    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; 
} 
int main(){
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++){
		int n, q;
		cin >> n >> q;
		int a[n];
		for(int &i : a) cin >> i;
		struct Point p[n+1];
		for(int i = 0; i < n; i++){
			p[i].x = i+1, p[i].y = a[i];
		}
		for(int i = 0; i< n; i++){
			cout << endl << p[i].x << " " << p[i].y;
		}
		while(q--){
			int x, y, c, count = 0;
			cin >> x >> y >> c;
			Point pp, qq;
			pp.x = x, pp.y = c;
			qq.x = y, qq.y = c;
			for(int i = 0; i < n-1; i++){
				if(doIntersect(p[i], p[i+1], pp, qq))
					count++;
			}
			cout << endl << count;
		}
	}
	return 0;
}
