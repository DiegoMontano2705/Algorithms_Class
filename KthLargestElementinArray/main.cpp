//LeetCode.com
//ID : 215
//Kth Largest Element in Array
//Divide and Conquer theme

//Instruction
// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//  You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <vector>

using namespace std;

void Particion(vector<int> &d, int ini, int fin, int &pivote){
		int Elempivote = d[ini];
		int j = ini;
		int aux;
		for (int i=ini+1; i<=fin; i++) {
      		if (d[i] < Elempivote) {
                    j = j+1;
                    aux = d[i];
                    d[i] = d[j];
                    d[j] = aux;
			}
		}
		pivote = j;
		aux = d[ini];
		d[ini] = d[pivote];
        d[pivote] = aux;

 }

void QuickSort(vector<int> &d, int ini, int fin){
    int pivote;
    if(ini < fin){
        Particion(d,ini,fin,pivote);
        QuickSort(d,ini,pivote-1);
        QuickSort(d,pivote+1,fin);
     }
}


int findKthLargest(vector<int> &nums, int k) {
        int res,index;
        QuickSort(nums,0,nums.size()-1);
        index = nums.size() - k;
        res = nums[index];
        return res;
}


int main()
{
    int n,k;
    int answer;
    cin >> k;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
	answer = findKthLargest(datos,k);
	cout << answer << endl;

    return 0;
}
