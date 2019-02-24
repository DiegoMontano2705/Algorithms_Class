#include <iostream>
#include <vector>
using namespace std;
int contComp = 0;

void Une(vector<int> &d, int ini, int m, int fin){
    vector<int> aux(d.size());
    int i,j,k;
  	i = ini;
    j = m+1;
    k = ini;
	while(i <= m && j <= fin) {
     	 if (d[i] < d[j]) {
              aux[k] = d[i];
              i = i+1;


        }
     	else {
              aux[k] = d[j];
              j = j+1;
        }
    		 k = k +1;
    		 contComp++;
	}

	while(i <= m){
        aux[k] = d[i];
        k++;
        i++;
	}

	while(j <= fin){
        aux[k] = d[j];
        k++;
        j++;
	}


	for(int x = ini; x <= fin; x++){
        d[x] = aux[x];
    }

}

void MergeSort (vector<int> &d, int ini, int fin){
	if(ini < fin){
      int mit = (ini+fin)/2;
      MergeSort(d,ini,mit);
      MergeSort(d,mit+1,fin);
      Une(d,ini,mit,fin);
    }
      for(int i = 0; i < 6; i++){
        cout << d[i] << " ";
      }
      cout << endl;
}

int main() {
  vector <int> v;
  int value;
  for(int i = 0; i < 6;i++){
    cin >> value;
    v.push_back(value);
  }

  MergeSort(v,0,5);
  cout << contComp << endl;
  return 0;
}

