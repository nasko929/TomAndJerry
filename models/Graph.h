//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_GRAPH_H
#define TOMANDJERRY_GRAPH_H
#include <vector>
#include "DAG.h"

using namespace std;

class Graph {
private:
    int nbVertices;
    vector<vector<int>> adjacencyList;
    vector<pair<int, int>> edgeList;

public:
    Graph(int _nbVertices);
    void addEdge(int u, int v, bool directed = false);
    vector<int> BFS(int src);
    DAG* optimalDAG(int src);
};
#endif //TOMANDJERRY_GRAPH_H
