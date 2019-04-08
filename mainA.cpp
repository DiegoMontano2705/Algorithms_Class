#include <iostream>
// El Tesoro de la Tortuga
// Matricula:A01282875
// Nombre: Diego Fernando Montaño Pérez

using namespace std;
#define MAX 100

int turtle(int mat[MAX][MAX], int n, int m){
// Aquí va tu codigo

   for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               if(i == 0){
                    if(j > 0){
                        mat[i][j] = mat[i][j] + mat[i][j-1];
                    }
               } else {
                   if(j == 0){
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                   } else {
                       if(mat[i][j] + mat[i-1][j] > mat[i][j] + mat[i][j-1]){
                            mat[i][j] = mat[i][j] + mat[i-1][j];
                       } else
                            mat[i][j] = mat[i][j] + mat[i-1][j];
                   }

               }

            }
        }

	return mat[n-1][m-1];
}

void print(int mat[MAX][MAX], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
		 cout << mat[i][j]<< " ";
		}
		cout << endl;
	}
}

int main(){
	int n, m;
	int mat[MAX][MAX];
	cin >> n  >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	print(mat, n, m);
	cout << turtle(mat, n, m)<<endl;
}




