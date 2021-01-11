#include <iostream>
#include "models/Reader.h"

using namespace std;

int main() {

    Solver* solver = Reader::read();

    solver->solve();

    return 0;
}
