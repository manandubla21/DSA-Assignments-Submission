#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l; // int *arr
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
        // arr = new int[V]  //intializing dynamic array
    }

    void addEdge(int u , int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs() {
        vector<bool> vis(V , false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int n : l[u]) {  //immediate neighbour
                if(!vis[n]) {
                    q.push(n);
                    vis[n] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.bfs();
    return 0;
}