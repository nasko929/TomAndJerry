//
// Created by Atanas Dobrev on 11.01.21.
//
#include <iostream>
#include "Solver.h"
#include "Graph.h"

using namespace std;


Solver::Solver(int m, int n, int k, int l, const pair<int, int> &tom, const pair<int, int> &jerry,
               const vector<vector<bool>> &grid, const vector<vector<bool>> &paintFields)
               : m(m), n(n), k(k), l(l), tom(tom), jerry(jerry), grid(grid), paintFields(paintFields) {

}

int getIdOfCell(pair<int, int> point, int m) {
    return point.first * m + point.second;
}

int Solver::getM() const {
    return m;
}

void Solver::setM(int m) {
    Solver::m = m;
}

int Solver::getN() const {
    return n;
}

void Solver::setN(int n) {
    Solver::n = n;
}

int Solver::getK() const {
    return k;
}

void Solver::setK(int k) {
    Solver::k = k;
}

int Solver::getL() const {
    return l;
}

void Solver::setL(int l) {
    Solver::l = l;
}

const pair<int, int> &Solver::getTom() const {
    return tom;
}

void Solver::setTom(const pair<int, int> &tom) {
    Solver::tom = tom;
}

const pair<int, int> &Solver::getJerry() const {
    return jerry;
}

void Solver::setJerry(const pair<int, int> &jerry) {
    Solver::jerry = jerry;
}

const vector<vector<bool>> &Solver::getGrid() const {
    return grid;
}

void Solver::setGrid(const vector<vector<bool>> &grid) {
    Solver::grid = grid;
}


const vector<vector<bool>> &Solver::getPaintFields() const {
    return paintFields;
}

void Solver::setPaintFields(const vector<vector<bool>> &paintFields) {
    Solver::paintFields = paintFields;
}

Graph* Solver::buildGraph() {
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto* graph = new Graph(n * m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int currentVer = i * m + j;
            for(int dir = 0; dir < 4; dir++) {
                int x = i + dx[dir], y = j + dy[dir];
                if(x >= 0 && y >= 0 && x < n && y < m && !grid[x][y]) {
                    int adjacentVer = x * m + y;
                    graph->addEdge(currentVer, adjacentVer, true);
                }
            }
        }
    }

    return graph;
}

void Solver::solve() {

    auto* graph = buildGraph();

    auto levels = graph->BFS(getTom().first * getM() + getTom().second);

    int tomId = getIdOfCell(getTom(), getM());
    int jerryId = getIdOfCell(getJerry(), getM());

    cout << "Shortest path to Jerry is: " << levels[jerryId] << endl << endl;

    auto* dag = graph->optimalDAG(tomId);

    auto allPaths = dag->allPathsDFS(tomId, jerryId);

    cout << "All shortest paths from Tom to Jerry: " << endl;
    for (int i = 0; i < allPaths.size(); i++) {
        int numberOfPaintFields = 0;
        cout << (i + 1) << ") " << endl;
        for (int j = 0; j < allPaths[i].size(); j++) {
            cout << "(" << allPaths[i][j] / getM() << ", " << allPaths[i][j] % getM() << ")";
            if (j != allPaths[i].size() - 1) {
                cout << " -> ";
            }
            numberOfPaintFields += getPaintFields()[allPaths[i][j] / getM()][allPaths[i][j] % getM()];
        }
        cout << endl;
        cout << "Total amount of " << numberOfPaintFields << " units of paint could be spilt.\n";

        int numberOfTurns = 0;
        for (int j = 0; j < allPaths[i].size() - 2; j++) {
            if ((allPaths[i][j] / getM() - allPaths[i][j + 1] / getM() != allPaths[i][j + 1] / getM() - allPaths[i][j + 2] / getM())
            ||  (allPaths[i][j] % getM() - allPaths[i][j + 1] % getM() != allPaths[i][j + 1] % getM() - allPaths[i][j + 2] % getM())) {
                numberOfTurns++;
            }
        }

        cout << "During this path, there were a total of " << numberOfTurns << " turns.\n";
        string droneCommands = "";
        for (int j = 0; j < allPaths[i].size() - 1; j++) {
            int x1 = allPaths[i][j] / getM(), y1 = allPaths[i][j] % getM();
            int x2 = allPaths[i][j + 1] / getM(), y2 = allPaths[i][j + 1] % getM();
            int dx = x1 - x2, dy = y1 - y2;
            if (getPaintFields()[x1][y1]) {
                droneCommands += "P";
            }
            if (dx == 1 && dy == 0) {
                droneCommands += "N";
            }
            if (dx == -1 && dy == 0) {
                droneCommands += "S";
            }
            if (dx == 0 && dy == 1) {
                droneCommands += "W";
            }
            if (dx == 0 && dy == -1) {
                droneCommands += "E";
            }
        }
        cout << "Drone commands would be: " << droneCommands << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }

}
