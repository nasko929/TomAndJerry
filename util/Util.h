//
// Created by Atanas Dobrev on 11.01.21.
//

#ifndef TOMANDJERRY_UTIL_H
#define TOMANDJERRY_UTIL_H

#include "../models/ReadResult.h"

/**
 * @brief A util class.
 *
 * This class is making the code more clear as it divides the not so good-looking logic into separate class.
 */
class Util {
public:
    static ReadResult readInt(char *, int);
    static ReadResult readString(char *, int);
};

#endif //TOMANDJERRY_UTIL_H
