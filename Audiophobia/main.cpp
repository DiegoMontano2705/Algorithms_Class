//Algoritmo de Floyd

#include <iostream>

using namespace std;

void floyd(int D[100][100],int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // INT_MAX es para que cuando el valor sea el maximo , no haya un Overflox al hacer la suma
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > max(D[i][k],D[k][j])){
                    D[i][j] = max(D[i][k],D[k][j]);
                }
            }
        }
    }
}


int main()
{
    int n,c,s,q,a,b,e;
    cin >> n;
    for(int x = 0; x != n; x++){
        cin >> c;
        cin >> s;
        cin >> q;

    int D[100][100];

    for (int i = 0 ; i < c; i++){
        D[i][i] = 0;
        for(int j = 0 ; j < c; j++){
            D[i][j] = D[j][i] = INT_MAX;
        }
    }

    for (int i = 0; i < s; i++){
        cin >> a >> b >> e;
        D[a-1][b-1] = D[b-1][a-1] = e;
    }

    floyd(D,c);

    cout << "Case " << x+1 << ":\n";

    for (int i=0; i < q; i++){
        cin >> a >> b;
        if(D[a-1][b-1] < INT_MAX)
            cout << D[a-1][b-1] << endl;
         else
            cout << "no path" << endl;
        }
    }

    return 0;
}















