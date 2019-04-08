// Diego Fernando Montaño Pérez A01282875
#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int iN,iNumLines,iNum,iAux;
    int iMatrix[11][11];
    int iX = 0;
    cin >> iN;
    while(iX != iN){
        cin >> iNumLines;
        iAux = 1;
        for(int i = 0; i < iNumLines; i++){
            for(int j = 0; j < iAux; j++){
                cin >> iNum;
                iMatrix[i][j] = iNum;
            }
            iAux++;
        }

        for(int i = iNumLines-1; i > 0; i--){
            for(int j = 0; j < iAux; j++){
               iMatrix[i-1][j] = max(iMatrix[i-1][j]+iMatrix[i][j],iMatrix[i-1][j]+iMatrix[i][j+1]);
            }
            iAux--;
        }
        cout << iMatrix[0][0] << endl;
        iX++;
    }

    return 0;
}
