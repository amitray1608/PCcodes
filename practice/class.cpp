#include<bits/stdc++.h>
using namespace std;
class sime
{
  int h,m,s,a,b;
  public:
  //sime();
  void input(){
      cout<<"enter seconds \n";
      cin>>s;
      cout<<"enter minutes \n";
      cin>>m;
      cout<<"enter hour \n";
      cin>>h;
  }
    void display(){
        cout<<h<<"hour";
        cout<<m<<"minutes";
        cout<<s<<"seconds";
    }
    void add(sime a,sime b)
    {
        h=a.h +b.h;
        m=a.m +b.m;
        s=a.s +b.s;
        if(s>59){
            m=m+s/60;
            s=s%60;
        }
        if(m>59){
            h=h+m/60;
            m=m%60;
        }
    }
    
};
int main() { 
  sime c1,c2,c3;
  c1.input();
  c2.input();
  c1.display();
  c2.display();
  c3.add(c1,c2);
  c3.display();
    return 0;
}
