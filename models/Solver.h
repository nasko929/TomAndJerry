//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_SOLVER_H
#define TOMANDJERRY_SOLVER_H

#include <utility>
#include <vector>
#include "Graph.h"

#define MAX_SIZE 1024
using namespace std;

class Solver {

private:
    int m, n;
    int k, l;
    pair<int, int> tom;
    pair<int, int> jerry;
    vector<vector<bool>> grid;
    vector<vector<bool>> paintFields;
public:
    Solver(int m, int n, int k, int l, const pair<int, int> &tom, const pair<int, int> &jerry,
           const vector<vector<bool>> &grid, const vector<vector<bool>> &paintFields);

    const vector<vector<bool>> &getPaintFields() const;

    void setPaintFields(const vector<vector<bool>> &paintFields);

    void solve();

    int getM() const;

    void setM(int m);

    int getN() const;

    void setN(int n);

    int getK() const;

    void setK(int k);

    int getL() const;

    void setL(int l);

    const pair<int, int> &getTom() const;

    void setTom(const pair<int, int> &tom);

    const pair<int, int> &getJerry() const;

    void setJerry(const pair<int, int> &jerry);

    const vector<vector<bool>> &getGrid() const;

    void setGrid(const vector<vector<bool>> &grid);

    Graph* buildGraph();
};

#endif //TOMANDJERRY_SOLVER_H
