#include <iostream>
#include <vector>

using namespace std;

vector<int> AAPL = { 7, 1, 3, 5, 3, 6 };

vector<int> maxProfit(vector<int>& prices) { 
        if(prices.size()<=1) return {};
        
        vector<int> result;
        
        for(int i = 0; i<prices.size(); i++){
            int j = i;
            while(j < prices.size() && prices[j]<prices[j+1]){
                j++;
            }
            if(j>i){
                result.push_back(i);
                result.push_back(j);
                i = j;
            }
        }
        
        return result;
}

int main(){
    vector<int> result = maxProfit(AAPL);

    for(auto i : result){
        cout<< i << " ";
    }
    cout<<endl;

    return 0;
}



