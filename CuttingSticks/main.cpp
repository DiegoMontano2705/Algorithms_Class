#include <iostream>
#include <climits>
#include <limits.h>

using namespace std;

int multMatrices(int d[],int n){
    int D[51][51],aux;
    for(int j = 1; j <= n;j++){
        for(int i = j-1; i >= 0 ; i--){
            if(i+1 == j){
                D[i][j] = 0;
            } else {
            aux = INT_MAX;
            for(int k = i+1; k < j; k++){
                aux = min(aux,D[i][k] + D[k][j]);
            }
            D[i][j] = aux + d[j] - d[i];
        }
      }
    }
    return D[0][n];
}


int main(){
	int l,n,ans;
	l = 1;
	while(l != 0){
        cin >> l;
        if(l != 0){
            cin >> n;
            int ci[52];
            ci[0] = 0;
            ci[n+1] = l;
            for(int i = 1; i <= n; i++){
                cin >> ci[i];
            }
            n++;
            ans = multMatrices(ci,n);
            cout << "The minimum cutting is " << ans << "." << endl;
        }

	}
	return 0;
}

/*

      int D[52][52],aux;
    for(int i = 0; i < n;i++){
        D[i][i] = 0;
        for(int s = 0; s < n; s++){
            D[i][s] = 0;
        }
    }







    for(int diag = 1; diag < n; diag++){
        for(int i = 0; i < n-diag; i++){
            j = i + diag;
            aux = INT_MAX;
            for(int k = i ; k < j;k++){
                //if(min(aux,D[i][k] + D[k][j] + d[j] + d[k] - d[i]) < aux){
                    aux = min(aux,D[i][k] + D[k+1][j] + d[j] + d[k] - d[i]); //d[i-1]*d[k+1]*d[j+1];   d[i-1]*d[k]*d[j];
                //}
            }
            D[i][j] = aux;
        }
    }
*/


  /*for(int j = 1; j <= n;j++){
        for(int i = j-1; i >= 0 ; i--){
            if(i+1 == j){
                D[i][j] = 0;
            } else {
            D[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
            D[i][j] = D[i][j] + d[j] - d[i];

        }
      }
    }




    int multMatrices(int d[],int n,int l){
    int D[52][52],aux;
    for(int j = 1; j <= n;j++){
        for(int i = j-1; i >= 0 ; i--){
            if(i+1 == j){
                D[i][j] = 0;
            } else {
            aux = INT_MAX;
            for(int k = i+1; k < j; k++){
                if(aux > D[i][k] + D[k][j]){
                    aux = D[i][k] + D[k][j];
                }
            }
            D[i][j] = aux + d[j] - d[i];
        }
      }
    }


*/




