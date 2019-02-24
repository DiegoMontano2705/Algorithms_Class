#include <iostream>
//ID 921

using namespace std;
 int minAddToMakeValid(string S) {
    int iContLParentesis = 0;
    int iContRParentesis = 0;

    for(int i = 0; i < S.length() ; i++){
        if(S[i] == '('){
            iContLParentesis++;
        }else {
            if(S[i] == ')' && iContLParentesis < 1)
                iContRParentesis++;
            else
                iContLParentesis--;
        }
    }
    return iContLParentesis + iContRParentesis;


 }


int main()
{
    string sT;
    cin >> sT;
    cout << minAddToMakeValid(sT) << endl;
    return 0;
}

