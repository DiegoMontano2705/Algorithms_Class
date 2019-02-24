#include <iostream>
#include <stack>
//ID 402

using namespace std;


int main()
{
    int *arr;
    int z;
    for(int i = 0; i < 5; i++){
        cin >>z;
        arr = new int[i];
        arr[i] = z;
    }
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
