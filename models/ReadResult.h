//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_READRESULT_H
#define TOMANDJERRY_READRESULT_H

#include <string>
using namespace std;

/**
 * @brief A struct that is used when reading the data from the file.
 *
 * This struct is needed so that it provides information about the just-read
 * value from the buffer that we read from the input file.
 * The field nextIndex is referring to the start index of the next word to read.
 */
struct ReadResult {
    string str;
    int number;
    int nextIndex;
};

#endif //TOMANDJERRY_READRESULT_H
