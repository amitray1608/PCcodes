#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double x,y,v1,v2;
    int h,c,t,T;
    cin>>T;
    while (T--) {
        cin>>h>>c>>t;
        if (t == h) {
            cout<<1<<endl;
            continue;
        }
        if (h - t == t - c) {
            cout<<2<<endl;
            continue;
        }
        y = (t - c) / (double)(h - t);
        x=(h-t)/(double)(2*t-h-c);
        long low = long(x);
        long high = x+1;
        v1 = abs(((low + 1) / (double)low) - y);
        v2 = abs(((high + 1) / (double)high) - y);
        if (v2 < v1)
            cout<<2 * high + 1<<endl;
        else
            cout<<2 * low + 1<<endl;
    }
    
}
