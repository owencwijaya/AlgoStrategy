#include <bits/stdc++.h>
using namespace std;

//di sini main OOP
//1. graph, ada edge dkk
//2. disjoint set union untuk tau apakah dua node berhubungan atau tidak

//jangan lupa kalo MST itu tree, jadi 
//pakai istilah parent dan rank
class DSU{ //disjoint set union
    private:
        vector <int> parent, rank;
    public:
        DSU(int n){
            for(int i = 0; i < n; i++){
                parent.push_back(-1);
                rank.push_back(1);
            }
        }
        int find(int x){
            //cari root element dari x
            if(parent[x] == -1){
                return x;
            }
            return find(parent[x]);
        }

        void unite(int x, int y){
            //anggap operasi penggabungan, jadi dua
            //node yang berbeda digabungin jadi 1
            int xpos = find(x);
            int ypos = find(y);
            //kalo titik awal dan akhir beda
            if (xpos != ypos){
                //kalau rank xpos lebih kecil, 
                //ganti parent node xpos ke ypos
                if (rank[xpos] < rank[ypos]){
                    parent[xpos] = ypos;
                    rank[ypos] += rank[xpos];
                }//..vice versa
                else {
                    parent[ypos] = xpos;
                    rank[xpos] += rank[ypos];           
                }
            }
        }
};

class Graph{
    friend DSU;

    private:
        vector<vector<int>> edgeList;
        int nodes;

    public:
        // constructor
        Graph(int nodes){
            this->nodes = nodes;
        }

        void addEdge(int start, int end, int weight){
            //tambahin edge
            edgeList.push_back({weight, start, end});
        }

        int MST(){
            //sort edgeList berdasarkan weight
            sort(edgeList.begin(), edgeList.end());
            //init DSU
            DSU dsu(this->nodes);
            int totalWeight = 0;
            for (auto edge: edgeList){
                int weight = edge[0];
                int start = edge[1];
                int end = edge[2];
                //misalnya root elementnya beda, gabungin jadi 1
                if (dsu.find(start) != dsu.find(end)){
                    dsu.unite(start, end);
                    totalWeight += weight;
                }
            }
            return totalWeight;
        }

};

int main()
{
    Graph g(4);
    //tambahin start, end, weight
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
 
    cout << g.MST();
    return 0;
}