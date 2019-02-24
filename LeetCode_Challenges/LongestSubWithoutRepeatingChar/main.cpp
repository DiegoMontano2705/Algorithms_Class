#include <iostream>
//ID 3

using namespace std;

int lengthOfLongestSubstring(string s) {
    int iHigherSub = 0;
    string sHelp = "";
    int i = 0;
    int iX = 0;
    while(i < s.length()){
        sHelp = sHelp + s[i];
        while(iX < sHelp.length()){
            cout << sHelp << endl;

                if(sHelp[iX] == s[i]) {
                    if(sHelp.length() >= iHigherSub){
                    iHigherSub = sHelp.length();
                    }
                    sHelp = "";
                }

            iX++;
        }
        i++;
    }
    return iHigherSub;

}


int main()
{
    string sString;
    cin >> sString;
    cout << lengthOfLongestSubstring(sString) << endl;

    return 0;
}
