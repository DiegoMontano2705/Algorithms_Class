#include <iostream>
//ID 767
using namespace std;
string reorganizeString(string S) {
    int aux;
    if(S.length()%2 == 0){
        return "";
    }

    for(int i = 0; i < S.length(); i++){
        if(S[i+1] == S[i]){
            for(int j = i+1; j < S.length(); j++){
                if(S[j] != S[i]){
                    aux = S[i];
                    S[i] = S[j];
                    S[j] = aux;
                }
            }
        }

    }
    return S;


}

int main()
{
 string sT;
 cin >> sT;
 cout << reorganizeString(sT) << endl;

    return 0;
}
