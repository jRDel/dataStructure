/* Given an array of integers, output an array of equal length such that
the value at each index is equal to the product of every other index value in
the original array.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solveThis(vector<int> arr){
    vector<int> ans;
    int sum = 1;
    for(int i = 0; i<arr.size(); i++){ 
        for(int j = 0; j<arr.size(); j++){
            if(j == i){ //num we are currently on, so sum up all other nums
                if(arr[j]!=0) //If its zero, then we don't need to remove it from the product
                    sum = sum*arr[j]/arr[j];
            }
            else{
                sum = sum*arr[j];
            }
        }
        ans.push_back(sum);
        sum = 1;
    }
    return ans;
}

// 1 2 3 0 5 i0
// * 2 3 0 5 = 0 i0
// 1 * 3 0 5 = 0 i1
// 1 2 * 0 5 = 0 i2
// 1 2 3 * 5 = 30 i3
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    vector<int> answer = solveThis(arr);

    for(auto itr : answer){
        cout<<itr<<" ";
    }
    cout<<endl;
    return 0;
}