#include <iostream>

using namespace std;

int main()
{
    int iNum, iX;
    int iCont0= 0,iCont1= 0;
    string sCode;
    cin >> iNum;
    cin >> sCode;
    for(iX = 0; iX < iNum ; iX++){
        if(sCode[iX] == '1'){
            iCont1++;
        }
         if(sCode[iX] == '0'){
            iCont0++;
        }
    }

    if(iCont1 >= iCont0){
        cout << iCont1-iCont0 << endl;
    } else {
        cout << iCont0-iCont1 << endl;
    }

    return 0;
}

 /*
    do{
            if(bDatoBorrado){
                iX=0;
            }
            if(sCode[iX] != sCode[iX+1] && sCode[iX+1] != NULL){
                sCode.erase(iX,2);
                bDatoBorrado = true;
            }
            cout << s
            iNum = sCode.length();
            iX++;
        } while (iX <= iNum);
    cout << sCode.length() << endl;
*/
