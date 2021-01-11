//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_READER_H
#define TOMANDJERRY_READER_H

#include <fstream>
#include "Solver.h"

using namespace std;

class Reader {
public:
    static Solver* read();
};

#endif //TOMANDJERRY_READER_H
