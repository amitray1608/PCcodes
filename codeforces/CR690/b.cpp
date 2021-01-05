#include <iostream>
using namespace std;
 //Stanca Florin cls a 9a D
int main() {
    int m;
    int nr=0;
    cin>>m;
    if ( m != 0 ) {
        nr=nr*10+m%10;
    }
    cout<<nr;
    return 0;
}
