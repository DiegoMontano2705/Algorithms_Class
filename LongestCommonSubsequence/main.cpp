//Problem G
// The longest common subsequence(LCS) problemis the problem of finding the longest subsequencecommon to all sequences in a set of sequences (often just two sequences).
// This problem not required occupyingconsecutive positions within the original sequences.
// For example, having the strings “AAAAAAABBAAB” and “ABAABBAB”, the Longest Common Subsequence is thestring “AAABBAB”with a length of 7.

#include <iostream>

using namespace std;

int LCS(string s1, string s2){
    int r = s1.length();
    int c = s2.length();
    int matrix[r][c];
    //Llena de ceros la primera columna y primer renglon
    for(int i = 0; i < r; i++){
        matrix[i][0] = 0;
    }
    for(int j = 0; j < c; j++){
        matrix[0][j] = 0;
    }

    for(int i = 1; i < r; i++){
        for(int j = 1 ; j < c; j++){
            if(s1[i] == s2[j]){
                matrix[i][j] = matrix[i-1][j-1] + 1;
            } else {
                matrix[i][j] = max(matrix[i][j-1],matrix[i-1][j]);
            }
        }
    }

    return matrix[r-1][c-1] + 1;
}

int main()
{
    int n, ans, i = 0;
    string word1,word2;
    cin >> n;
    while(i < n){
        cin >> word1;
        cin >> word2;
        ans = LCS(word1,word2);
        i++;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
