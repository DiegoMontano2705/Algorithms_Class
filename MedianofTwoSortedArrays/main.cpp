#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //nums1.merge(nums2);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());

        int left, right;
        left = nums2[(nums2.size()-1)/2];
        if(nums2.size()% 2 == 0){
            return left;
        } else {
            right = nums2[((nums2.size()-1)/2)+1];
            return (left+right)/2;
        }
    }


};


int main()
{
    vector <int> datos;
    vector <int> datos2;
    datos.push_back(1);
    datos.push_back(3);
    datos2.push_back(2);
    double ans;
    ans = findMedianSortedArrays(datos,datos2);
    //cout << ans << endl;
    return 0;
}
