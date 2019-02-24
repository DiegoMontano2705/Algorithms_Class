#include <iostream>
using namespace std;

int algoritmo(int A[], int n){
  if(A[n] != NULL){
    if(A[n]%2 == 1){
        return (A[n]+algoritmo(A,n+1));
    } else {
        return algoritmo(A,n+1);

    }

  } else {
      return 0;
  }

}

int main() {
  int iA[10];
  for(int i = 0; i < 10; i++){
    iA[i] = i+1;
  }
  int n = 0;
  cout << "Suma impares es de " << algoritmo(iA,n) << endl;
}
