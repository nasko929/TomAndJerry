//
// Created by Atanas Dobrev on 11.01.21.
//

#include <iostream>
#include "Reader.h"
#include "../util/Util.h"
#include "Solver.h"

using namespace std;

bool getInt(int &x, int &startIndex, char* buffer) {
    ReadResult result = Util::readInt(buffer, startIndex);
    startIndex = result.nextIndex;
    x = result.number;

    if (x == -1) {
        cerr << "Bad data in the file. Please check again.\n";
        return false;
    }

    return true;
}

bool getString(string &str, int &startIndex, char* buffer) {
    ReadResult result = Util::readString(buffer, startIndex);
    startIndex = result.nextIndex;
    str = result.str;

    if (str.empty()) {
        cerr << "Bad data in the file. Please check again.\n";
        return false;
    }

    return true;
}

Solver* Reader::read() {
    int n, m, k, l;
    pair<int, int> tom, jerry;

    vector<vector<bool>> grid;

    ifstream inputFile("../input.txt", ios::in);

    if(!inputFile) {
        cout << "There was problem with getting the data.\n";
        return nullptr;
    }

    inputFile.seekg(0, inputFile.end);
    int length = inputFile.tellg();
    inputFile.seekg(0, inputFile.beg);

    char* buffer = new char[length];
    inputFile.read(buffer, length);
    inputFile.close();

    int startIndex = 0;

    if (!getInt(n, startIndex, buffer)) {
        return nullptr;
    }

    if (!getInt(m, startIndex, buffer)) {
        return nullptr;
    }

    grid.assign(n, vector<bool>(m, false));

    // Get Jerry's position.
    if (!getInt(jerry.first, startIndex, buffer)) {
        return nullptr;
    }

    if (!getInt(jerry.second, startIndex, buffer)) {
        return nullptr;
    }

    // Get Tom's position.
    if (!getInt(tom.first, startIndex, buffer)) {
        return nullptr;
    }

    if (!getInt(tom.second, startIndex, buffer)) {
        return nullptr;
    }

    if (!getInt(k, startIndex, buffer)) {
        return nullptr;
    }

    if (!getInt(l, startIndex, buffer)) {
        return nullptr;
    }

    for (int i = 0; i < k; i++) {
        pair<int, int> currentPosition;

        if (!getInt(currentPosition.first, startIndex, buffer)) {
            return nullptr;
        }

        if (!getInt(currentPosition.second, startIndex, buffer)) {
            return nullptr;
        }

        string current;
        do {
            if (!getString(current, startIndex, buffer)) {
                return nullptr;
            }

            if (current == "===") {
                break;
            }

            for (int j = 0; j < (int) current.size(); j++) {
                if (current[j] == '1') {
                    grid[currentPosition.first][currentPosition.second + j] = true;
                }
            }
            currentPosition.first++;
        } while (true);
    }

    vector<vector<bool>> paintFields;

    paintFields.assign(n, vector<bool>(m, false));

    for (int i = 0; i < l; i++) {
        int x, y;

        if (!getInt(x, startIndex, buffer)) {
            return nullptr;
        }

        if (!getInt(y, startIndex, buffer)) {
            return nullptr;
        }

        paintFields[x][y] = true;
    }

    return new Solver(m, n, k, l, tom, jerry, grid, paintFields);
}

