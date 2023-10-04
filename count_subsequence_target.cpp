#include<vector>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int counter(int ind, int s, int sum, int arr[], int n){
    if(ind == n){
        if(sum == s)
            return 1;
        else return 0;
    }
    s += arr[ind];
    int l = counter(ind + 1, s, sum, arr, n);
    s -= arr[ind];
    int r = counter(ind + 1, s, sum, arr, n);
    return l + r;
}

int main(){
    int arr[] = {2, 4, 1, 2, 3};
    int n = 5;
    int sum = 5;
    cout << counter(0, 0, sum, arr, n);
}
