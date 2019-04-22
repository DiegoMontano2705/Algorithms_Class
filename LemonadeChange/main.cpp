// LeetCode.com problem
// ID: 860. Lemonade Change
/*
At a lemonade stand, each lemonade costs $5.

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.

Test Cases:
Input: [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Input: [5,5,10]
Output: true

Input: [10,10]
Output: false

*/


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
         int five = 0,ten = 0;
        if(bills[0] == 10 || bills[0] == 20){
            return false;
        }
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            if(bills[i] == 10){
                if(five == 0){
                    return false;
                }
                five--;
                ten++;
            }
            if(bills[i] == 20){
                if(ten < 1 && five < 3){
                    return false;
                }
                if(five == 0){
                    return false;
                }
                if(ten == 0){
                    five = five - 3;
                } else {
                    five--;
                    ten--;
                }

            }
        }

        if(five < 0){
            return false;
        } else {
            return true;
        }

}

int main()
{
    vector<int> b;
    int n;
    int input;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        b.push_back(input);
    }

    if(lemonadeChange(b)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}




/*
 int aux[bills.size()];
 for(int i = 0; i < bills.size(); i++){
            aux[i] = bills[i]
            if(bills[i] > 5){
                for(int j = i-1; j >= 0; j--){

                }
            }


        }

*/
