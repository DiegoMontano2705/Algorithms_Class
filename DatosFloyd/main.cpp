//Algoritmo de Floyd

#include <iostream>

using namespace std;

void floyd(int D[20][20],int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // INT_MAX es para que cuando el valor sea el maximo , no haya un Overflox al hacer la suma
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][k]+D[k][j] < D[i][j]){
                    D[i][j] = D[i][k]+D[k][j];
                }
            }
        }
    }
}


int main()
{
    int n,m,q,a,b,c;
    cin >> n;
    cin >> m;
    cin >> q;
    int D[20][20];
    for (int i = 0 ; i<n; i++){
        D[i][i] = 0;
        for(int j = 0; j < n; j++){
            D[i][j] = D[j][i] = INT_MAX;
        }
    }
    for (int i = 0; i<m; i++){
        cin >> a >> b >> c;
        D[a-1][b-1] = D[b-1][a-1] = c;
    }
    floyd(D,n);
    cout << endl;
    for (int i=0; i<q; i++){
        cin >> a >> b;
        cout << D[a-1][b-1] << endl;
    }



    return 0;
}
