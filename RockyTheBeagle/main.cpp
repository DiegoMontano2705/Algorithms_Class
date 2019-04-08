#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX
#define MIN INT_MIN

int CaminoMayor(vector<int> D){
    int res = MIN;
    int aux;
    for(int i = 0; i < D.size() ; i++){
        if(D[i] > res){
            res = D[i];
            aux = i;
        }
    }
    return aux;

}


int Dijkstra(int N,vector<vector<pair<int,int> > > G,vector<int> Dist) {

    priority_queue<pair<int,int>,
        vector<pair<int,int> >,
        greater<pair<int,int> > > Q; //min heap
        Dist[0] = 0;
        pair<int,int> p(0,0);
        Q.push(p);
        while (!Q.empty()){
            int u = Q.top().first;
            Q.pop();
            for(int i = 0; i < G[u].size(); i++){
                pair<int,int> p = G[u][i];
                int v = p.first;
                int w = p.second;
                //cout << Dist[v] << " " <<  Dist[u]+w << endl;
                if(Dist[v] > Dist[u]+w){
                    Dist[v] = Dist[u]+w;
                    pair<int,int> nvo(v,Dist[v]);
                    Q.push(nvo);
                }
            }
        }

        return CaminoMayor(Dist);

}

int main() {
    int N, M,w,n,intU,intV,ans;
    char u, v,FinalAns;
    int iCont = 0;
    cin >> n;

    while(iCont < n){
        cin >> N >> M;
        vector<vector<pair<int,int> > > G(N);
        vector<int> Dist;
        Dist.assign(N,INF);
        for(int i=0;i<M;++i){
            cin >> u >> v >> w;
            intU = u;
            intV = v;
            pair<int,int> n1(intV-65,w);
            pair<int,int> n2(intU-65,w);
            G[intU-65].push_back(n1);
            G[intV-65].push_back(n2);
        }

        ans = Dijkstra(N,G,Dist);
        ans = ans+65;
        iCont++;
        FinalAns = ans;
        cout << "Case " << iCont << ": " << FinalAns << endl;

    }

    return 0;
}


/*
2
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D  1
*/
