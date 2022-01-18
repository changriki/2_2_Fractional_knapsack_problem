#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std; 


class Item { 
public:
    int value, weight; 
}; 



bool cmp(Item a, Item b) { 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 

    return r1 > r2; 
} 


double fractionalKnapsack(Item arr[], int capacity, int size) { 
    sort(arr, arr+size, cmp); 
    int curWeight = 0; 
    double finalValue = 0.0; 

    for (int i = 0; i < size; i++) { // i = load
        if (curWeight + arr[i].weight <= capacity) { 
            curWeight += arr[i].weight; 
            finalValue += arr[i].value; 
        } 
        else { 
            int remain = capacity - curWeight; 
            finalValue += arr[i].value  * ((double)remain / arr[i].weight); 
            break; 
        } 
    } 
    return finalValue; 
} 


int main() {
    int BackpackCapacity;
    cin >> BackpackCapacity;

    int n = 50000;
    int size;
    Item arr[n];
    for(int j=0; j<=n; j++) {
        cin >> arr[j].value >> arr[j].weight;
        size = j-1;
        if(cin.eof()) break;
    }

    cout << fixed << setprecision(6) << fractionalKnapsack(arr, BackpackCapacity, size) << endl; 

    return 0; 
}