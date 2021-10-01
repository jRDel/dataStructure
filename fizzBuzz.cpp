#include <iostream>
using namespace std;

void fizzBuzz(int n){
    for(int i = 1; i<=n; i++){
        if(i%15==0){
            cout<< "FizzBuzz\t";
        }
        else if(i%3==0){
            cout<< "Fizz\t";
        }
        else if(i%5==0){
            cout<< "Buzz\t";
        }
        else{
            cout<< i <<"\t";
        }
    }
    cout<<endl;
}

int main(){
    fizzBuzz(100);
    return 0;
}