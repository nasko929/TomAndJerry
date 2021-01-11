//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_DAG_H
#define TOMANDJERRY_DAG_H

#include <vector>
using namespace std;

class DAG {
private:
    int nbVertices;
    vector <vector<int>> adjacencyList;
public:
    DAG(int _nbVertices);
    void addEdge(int u, int v);
    bool isTargetReachable(int u, int target, vector<int> &cache);
    void allPathsDFSUtil(int u, int target, vector<int> &cache, vector<int> &buff, vector<vector<int>> &allPaths);
    vector<vector<int>> allPathsDFS(int source, int target);
};

#endif //TOMANDJERRY_DAG_H
