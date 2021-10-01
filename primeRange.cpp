#include <iostream>
#include <vector>
using namespace std;

void findPrime(vector<int> & arr,int start, int end)
{
    bool isPrime = true;

    while(start<end){
        isPrime = true;
        if(start<2){
            isPrime = false; //0 and 1 not prime
        }
        else{
            for(int i = 2; i<=start/2; i++){ //Highest factor of start will be start/2
                if(start % i == 0){ //If a number i can divide start perfectly then its not prime
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime){
            arr.push_back(start); //start is a prime number because it is only divisible by 1 and itself
        }
        start++;
    }
    return;
}



void printPrimes(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        cout<< arr[i] << " ";
    }
}

int main(){
    vector<int> arr;
    findPrime(arr,0, 25);
    printPrimes(arr);
    return 0;
}