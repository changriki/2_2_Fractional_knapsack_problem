#include <iostream> 
using namespace std; 
struct activity { int start, finish; };
void GreedySelector(activity vec[], int number) {  
    int i = 0; 
    cout << i+1 << " ";
    for(int m=0; m<number; m++) { 
      if(vec[m].start >= vec[i].finish) { 
          i = m;
          cout << i+1 << " "; } }
    cout << endl;}  
int main(){
  int n = 50000;
  activity arr[n];
  int j;
  for(j=1; j<=n; j++) {
    cin >> j >> arr[j-1].start >> arr[j-1].finish;
    if(cin.eof()) break; }
  n = sizeof(arr) / sizeof(arr[0]); 
  GreedySelector(arr, j-1); 
  return 0; }