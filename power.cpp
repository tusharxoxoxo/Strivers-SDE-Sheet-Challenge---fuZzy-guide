#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath> 

using namespace  std; 

int main(){
    string name = "james";
int counter = 1;
    int n = name.size();

    for(int num = 0; num < (1 << n); ++num){
        string sub = "";
        for(int i = 0; i < n; ++i){
            if(num & (1 << i)){
                sub += name[i];
            }
        }

        cout<< counter  <<" " << sub << endl;
        counter++;
    }
}



