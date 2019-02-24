//Test Cases
//aab
//abb
//abbcc
//aabbc
//aabcc

#include <iostream>

using namespace std;

char busquedaBinaria(string str){
    int iBajo,iAlto,iCentral;
    char cValorCen;
    int iTam = str.length();
    iBajo = 0;
    iAlto = iTam-1;
    if(iTam%2 == 0){
        return -1;
    }

    while(iBajo <= iAlto){
        iCentral = (iBajo+iAlto)/2;
        cValorCen = str[iCentral];
            if(iAlto-iBajo == 2){
                if(cValorCen == str[iCentral+1]){
                    return str[iCentral-1];
                } else {
                    return str[iCentral+1];
                }
            }
            if(cValorCen != str[iCentral+1] && cValorCen != str[iCentral-1]){
                return cValorCen;
            }

            if ((iAlto/2)%2 == 0){
                if(cValorCen == str[iCentral+1])
                {
                    iBajo = iCentral;
                } else {
                    iAlto = iCentral;
                }
            } else if((iAlto/2)%2 == 1) {
                 if(cValorCen == str[iCentral+1])
                {
                    iAlto = iCentral-1;
                } else {
                    iBajo = iCentral+1;
                }

            }
    }
    return cValorCen;
}

int main() {
    string sWord;
    cin >> sWord;
    cout << busquedaBinaria(sWord) << endl;
    return 0;
}

