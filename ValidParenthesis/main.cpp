#include <iostream>
//ID 20

using namespace std;

 bool isValid(string s) {
        int iContLC = 0, iContRC = 0;
        int iContLK = 0, iContRK = 0;
        int iContLV = 0, iContRV = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == '('){
                iContLC++;
            }
             if(s[i] == ')'){
                iContRC++;
            }
             if(s[i] == '['){
                iContLK++;
            }
             if(s[i] == ']'){
                iContRK++;
            }
             if(s[i] == '{'){
                iContLV++;
            }
             if(s[i] == '}'){
                iContRV++;
            }
        }
        if( iContLC-iContRC == 0 && iContLK-iContRK == 0 && iContLV-iContRV == 0){
            return false;
        } else{
            return true;
        }
    }

int main()
{
    string st;
    cin >> st;
    bool b = isValid(st);
    if(b){
       cout << "true"  << endl;
    } else {
        cout << "false"  << endl;
    }
    return 0;
}





if(nums.size() == 0 ){
            return aux;
          }
         if(nums.size() == 2 ){
            if(nums[0] == nums[1]){
                aux.push_back(nums[0]);
                return aux;
            } else {
                return aux;
            }
          }
        for(int i = 0; i < nums.size(); i++){

            for(int j = i+1; j < nums.size(); j++){
               if(nums[i] == nums[j]) {
                   aux.push_back(nums[i]);
               }
            }

        }
        return aux;



for(int i = 0; i < nums.size(); i ++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums [i]));
        }
        return res;
    }











 vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }
