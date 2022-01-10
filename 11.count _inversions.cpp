#include <iostream>
using namespace std;
long long c=0;
void count(long long a[],int l,int m,int r){
   int t[r+1];
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m and j<=r){
      if(a[i]<a[j]){
          t[k]=a[i++];k++;
      }
        else{
            t[k]=a[j++];k++;
            c+=(m-i)+1;
        }
    }
    while(i<=m){
      t[k]=a[i++];k++;
    }
    while(j<=r){
      t[k]=a[j++];k++;
    }
    for(int x=l;x<=r;x++){
        a[x]=t[x];
    }
}
void merge(long long a[],int l,int r ){
    int m=(l+r)/2;
    if(l<r){
       merge(a,l,m);
        merge(a,m+1,r);
        count(a,l,m,r);
    }
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    merge(arr,0,n-1);
    return c;
}
int main() {
	  long long myarray[5];
  //int arr_size = sizeof(myarray)/sizeof(myarray[0]);
  int arr_size = 5;

  cout << "Enter 5 integers in any order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }
  cout << "Before Sorting" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  cout<< getInversions(myarray,  5);// mergesort(arr,left,right) called

  

  return 0;
}
