//
// Created by Atanas Dobrev on 11.01.21.
//

#include "Util.h"

/**
 * @brief Method that reads an integer on a single-line from the buffer.
 *
 * @param buffer - the content of the input file.
 * @param start - the start index of the integer.
 * @return ReadResult - collected information from the reading. Returns -1 in case of an error.
 */
ReadResult Util::readInt(char* buffer, int start) {
    ReadResult result;
    int end = start;
    while (buffer[end] != (char) 10 && buffer[end] != (char) 32) {
        end++;
    }
    result.nextIndex = end + 1;
    int number = 0;
    for (int i = start; i < end; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            number = number * 10 + (buffer[i] - '0');
        } else {
            result.number = -1;
            return result;
        }
    }
    result.number = number;
    return result;
}

/**
 * @brief Method that reads a string line from the buffer.
 *
 * @param buffer - the content of the input file.
 * @param start - the start index of the integer.
 * @return ReadResult - collected information from the reading.
 */
ReadResult Util::readString(char* buffer, int start) {
    ReadResult result;
    result.number = 0;
    int end = start;
    while (buffer[end] != (char)10) {
        end++;
    }
    result.nextIndex = end + 1;
    result.str.resize(end - start);
    for (int i = start; i < end; i ++) {
        result.str[i - start] = buffer[i];
    }
    return result;
}
