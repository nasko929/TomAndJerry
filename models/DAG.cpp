//
// Created by Atanas Dobrev on 11.01.21.
//

#include "DAG.h"
#include <vector>

using namespace std;

DAG::DAG(int _nbVertices) {
    nbVertices = _nbVertices;
    adjacencyList.assign(nbVertices, vector<int>());
}

void DAG::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
}

bool DAG::isTargetReachable(int u, int target, vector<int> &cache) {
    if(cache[u] != -1) {
        return cache[u];
    }

    if(u == target) {
        return cache[target] = 1;
    }

    cache[u] = 0;
    for(int v: adjacencyList[u]) {
        if(!cache[u]) {
            cache[u] = isTargetReachable(v, target, cache);
        }
    }

    return cache[u];
}

void DAG::allPathsDFSUtil(int u, int target, vector<int> &cache, vector<int> &buff, vector<vector<int>> &allPaths) {
    if(!isTargetReachable(u, target, cache)) {
        return;
    }

    if(u == target) {
        allPaths.push_back(buff);
        return;
    }

    for(int v: adjacencyList[u]) {
        buff.push_back(v);
        allPathsDFSUtil(v, target, cache, buff, allPaths);
        buff.pop_back();
    }
}

vector<vector<int>> DAG::allPathsDFS(int source, int target) {
    vector<vector<int>> allPaths;
    vector<int> cache(nbVertices, -1), buff = {source};
    allPathsDFSUtil(source, target, cache, buff, allPaths);
    return allPaths;
}