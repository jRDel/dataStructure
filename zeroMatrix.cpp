#include <iostream>
#include <vector>
#include <set>
using namespace std;

void zeroMatrix(vector<vector<int>> & matrix){
  set<int> rowSeen;
  set<int> colSeen;
  
  for(int i=0; i<matrix.size(); i++){
    for(int j=0; j<matrix[0].size(); j++){
      if (matrix[i][j] == 0){
        rowSeen.insert(i);
        colSeen.insert(j);
      }
    }
  }
  for(int i=0; i<matrix.size(); i++){
    for(int j=0; j<matrix[0].size(); j++){
      if(rowSeen.count(i) == 1 || colSeen.count(j) == 1){
        matrix[i][j]=0;
      }
    }
  }
}

int main() {
  vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 0}
    };
    cout << "Before: " << endl;
    for(int i=0; i<vect.size(); i++){
      for(int j=0; j<vect[0].size(); j++){
        cout << vect[i][j] << " ";
      }
      cout<<endl;
    }
    zeroMatrix(vect);
    cout << "After: " << endl;
    for(int i=0; i<vect.size(); i++){
      for(int j=0; j<vect[0].size(); j++){
        cout << vect[i][j] << " ";
      }
      cout<<endl;
    }

}