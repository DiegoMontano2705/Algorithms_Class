#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

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
			contComp++
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

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
	QuickSort(datos, 0, n-1);
	cout << contComp<<endl;
	/*
	for (int i=0; i<n; i++){
		cout<<datos[i]<< " ";
	}
	cout << endl;
	*/
}
