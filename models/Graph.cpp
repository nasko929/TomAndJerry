//
// Created by Atanas Dobrev on 11.01.21.
//

#include <queue>
#include <vector>
#include <utility>
#include "Graph.h"
#include "DAG.h"

using namespace std;

Graph::Graph(int _nbVertices) {
    nbVertices = _nbVertices;
    adjacencyList.assign(nbVertices, vector<int>());
}

void Graph::addEdge(int u, int v, bool directed) {
    adjacencyList[u].push_back(v);
    edgeList.emplace_back(u, v);
    if (!directed) {
        adjacencyList[v].push_back(u);
        edgeList.emplace_back(v, u);
    }
}

vector<int> Graph::BFS(int src) {
    vector<int> dist(nbVertices, -1);

    queue<int> Q;
    Q.push(src);
    dist[src] = 0;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int v: adjacencyList[u]) {
            if(dist[v] == -1) {
                Q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }

    return dist;
}

DAG* Graph::optimalDAG(int src) {
    vector<int> dist = BFS(src);

    DAG* optDAG = new DAG(nbVertices);

    for(pair<int, int> edge: edgeList) {
        int from = edge.first, to = edge.second;
        if (dist[to] == dist[from] + 1) {
            optDAG->addEdge(from, to);
        }
    }

    return optDAG;
}