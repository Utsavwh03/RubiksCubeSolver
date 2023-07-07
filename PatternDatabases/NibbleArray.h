//
// Created by Utsav Dhanuka on 04/07/23.
//

#ifndef RUBIKSCUBESOLVER_NIBBLEARRAY_H
#define RUBIKSCUBESOLVER_NIBBLEARRAY_H

#include "vector"
#include "assert.h"
using namespace std;
class NibbleArray {
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    unsigned char *data();

    const unsigned char *data() const;

    void set(const size_t pos, const uint8_t val);

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);

};


#endif //RUBIKSCUBESOLVER_NIBBLEARRAY_H
