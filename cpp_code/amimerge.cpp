#include<iostream>
using namespace std;
void merge(int *a,int *l,int left_count,int *r,int right_count){
int i,j,k;
i=0;
j=0;
k=0;
 while(i<left_count&&j<right_count){
  if(l[i]<r[j]){
  a[k]=l[i];
  i++;
  }
  else
    {
  a[k]=r[j];
  j++;
  }
 }
 k++;

while(i<left_count){
a[k]=l[i];
i++;
k++;
}
while(j<right_count){
a[k]=r[j];
j++;
k++;
}

}
void merge_sort(int*a,int n){
 int mid,i;
 if(n<2){
 exit(0);
 }
 mid=n/2;
    int *l=new int[mid];
    int *r=new int[n-mid];
    int j = 0;
    for(i=0;i<mid;i++){
    l[j]=a[i];
    }
     j = 0;
    for(i=mid;i<n;i++){
    r[j]=a[i];
    j++;
    }
    merge_sort(l,mid);
    merge_sort(r,n-mid);
    merge(a,l,mid,r,n-mid);
    delete(l);
    delete(r);
}
int main(){
int i,n,a[1000];
cin>>n;
cout<<"enter a element of arrays";
for(int i=0;i<n;i++){
 cin>>a[i];
}
merge_sort(a,n);
cout<<"\nelemnt after merge sort";
for(i=0;i<n;i++){
cout<<a[i]<<" ";
}
}
