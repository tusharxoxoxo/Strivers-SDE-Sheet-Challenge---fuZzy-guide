#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> &arr, int target, int index, vector<int> &answer, int sum){
    if(index == arr.size()){
        if(sum == target){
            for(auto it: answer){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }   
        answer.push_back(arr[index]);
        sum += arr[index];
        recursion(arr, target, index + 1, answer, sum);
        answer.pop_back();
        
        sum -= arr[index];
        recursion(arr, target, index + 1, answer, sum);

}

int main(){
    int target = 5;
    vector<int> arr = {2, 4, 1, 2, 3};
    int index = 0;
    vector<int> answer;
    int sum = 0;
    recursion(arr, target, index, answer, sum);
}
