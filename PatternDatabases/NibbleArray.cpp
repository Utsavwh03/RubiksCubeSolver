//
// Created by Utsav Dhanuka on 04/07/23.
//

#include "NibbleArray.h"
#include "vector"
#include <cassert>
using namespace std;

NibbleArray::NibbleArray(const size_t size, const uint8_t val) :
        size(size), arr(size / 2 + 1, val) {
}

uint8_t NibbleArray::get(const size_t pos) const {
    size_t i = pos / 2;
    assert(pos <= this->size);
    uint8_t val = this->arr.at(i);

//    Odd pos: last 4 bits
    if (pos % 2) {
        return val & ((1<<4)-1);
    }
//    Even pos: first 4 bits from the left
    else {
        return (val >> 4);
    }
}

void NibbleArray::set(const size_t pos, const uint8_t val) {
    size_t i = pos / 2;
    uint8_t currVal = this->arr.at(i);
    assert(pos <= this->size);

    if (pos % 2) {
        this->arr.at(i) = (currVal & ~((1<<4)-1)) | (val & ((1<<4)-1));
    }
    else {
        this->arr.at(i) = (currVal & ((1<<4)-1)) | (val << 4);
    }
}
uint8_t *NibbleArray::data() {
    return this->arr.data();
}

const uint8_t *NibbleArray::data() const {
    return this->arr.data();
}

size_t NibbleArray::storageSize() const {
    return this->arr.size();
}
void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->get(i));
}

// Reset the array
void NibbleArray::reset(const uint8_t val) {
    fill(this->arr.begin(), this->arr.end(), val);
}