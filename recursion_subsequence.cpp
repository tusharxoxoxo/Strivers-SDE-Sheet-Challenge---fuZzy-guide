#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>


using namespace std; 

void recursion(vector<int>&arr, int index, vector<int>&answer){
    if(index >= arr.size()){
        for(auto it: answer){
            cout << it << " "; 
        }
        cout << endl;
        return;
    }

    answer.push_back(arr[index]);
    recursion(arr, index + 1, answer);
    answer.pop_back();


    recursion(arr, index + 1, answer);
}

int main(){
    vector<int> arr = {1, 2, 3, 23 };
    int index = 0;
    vector<int> answer;
    recursion(arr, index, answer);

    cout << "time complexity of this is 2^n * n" << endl;
}
