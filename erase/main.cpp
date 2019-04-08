/*#include<stdio.h>
#define MIN(x,y) ( (x) >= (y) ? (y) : (x) )
int main(){
	int L;
	while(scanf("%d",&L)==1&&L!=0){
		int DP[52][52];
		int m[52];
		int n;
		int i,j,k,min;

		scanf("%d",&n);
		m[0]=0;
		m[n+1]=L;
		for(i=1;i<=n;i++)
			scanf("%d",&m[i]);
		for(i=0;i<=n;i++)
			DP[i][i+1]=0;

		for(j=2;j<=n+1;j++)
			for(i=j-2;i>=0;i--){
				min=2e9;
				for(k=i+1;k<j;k++)
					min=MIN(min,DP[i][k]+DP[k][j]+m[j]-m[i]);
				DP[i][j]=min;
			}

			for(i = 0; i <=n+1;i++){
                for(j = 0; j <= n+1; j++){
                    printf("%d.",DP[i][j]);
                }
                printf(".\n");
			}


		printf("The minimum cutting is %d.\n",DP[0][n+1]);
	}
	return 0;
}
*/

//
//  main.cpp
//  Cutting Sticks
//
//  Created by Enrique Barragán on 3/5/17.
//  Copyright © 2017 Enrique Barragan. All rights reserved.
//

#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[]) {

    int length, cuts, price;

    cin >> length >> cuts;

    while (length != 0) {

        int prices[51], A[51][51]; // n <= 50
        prices[0] = 0;

        for (int i = 1; i <= cuts; i++) { // Arreglo de precios
            cin >> price;
            prices[i] = price;
        }

        cuts++;
        prices[cuts] = length;

        // Cut the sticks

        for (int j = 1; j <= cuts; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (i + 1 == j){ // Diagonal
                    A[i][j] = 0;
                } else {
                    A[i][j] = INT_MAX;
                    for (int k = i + 1; k < j; k++) {
                        if (A[i][k] + A[k][j] < A[i][j]) { // Sacar el mínimo
                            A[i][j] = A[i][k] + A[k][j];
                        }
                    }
                    A[i][j] += prices[j] - prices[i];
                }
            }
        }

        for(int i = 0; i <= cuts;i++){
         for(int j = 0; j <= cuts;j++){
            cout << A[i][j] << " ";
         }
         cout << endl;
    }
        // End of cut the sticks

        cout << "The minimum cutting is " << A[0][cuts] << "." << endl;

        cin >> length >> cuts;
    }

    return 0;
}
