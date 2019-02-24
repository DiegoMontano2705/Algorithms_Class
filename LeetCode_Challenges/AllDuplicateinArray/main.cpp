#include <iostream>
#include <vector>
//ID 442
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
        vector<int> resVector;
        for(int i = 0; i < nums.size();i++){

        }

}


int main()
{
    vector<int> iV;
    int in;
    for(int x = 0; x < 8 ; x++){
        cin >> in;
        iV.push_back(in);
    }
    findDuplicates(iV);

    for(int x = iV.begin(); x 1= iV.end(); x++){
        cout << *x << endl;
    }

    return 0;
}
