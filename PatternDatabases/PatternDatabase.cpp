//
// Created by Utsav Dhanuka on 04/07/23.
//

#include <fstream>
#include "PatternDatabase.h"

using namespace std;

PatternDatabase::PatternDatabase(const size_t size) :
        database(size, 0xFF), size(size), numItems(0) {
}

PatternDatabase::PatternDatabase(const size_t size, uint8_t init_val) :
        database(size, init_val), size(size), numItems(0) {
}
uint8_t PatternDatabase::getNumMoves(const uint32_t ind) const {
    return this->database.get(ind);
}
bool PatternDatabase::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
    uint8_t oldMoves = this->getNumMoves(ind);

//    New item is getting added
    if(oldMoves == 0xF){
        ++this->numItems;
    }

    if(oldMoves > numMoves){
        this->database.set(ind, numMoves);
        return true;
    }
    return false;

}
bool PatternDatabase::setNumMoves(const GenericRubiksCube &cube, const uint8_t numMoves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), numMoves);
}
uint8_t PatternDatabase::getNumMoves(const GenericRubiksCube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}
size_t PatternDatabase::getNumItems() const {
    return this->numItems;
}
size_t PatternDatabase::getSize() const {
    return this->size;
}
bool PatternDatabase::isFull() const {
    if(this->numItems == this->size)
        return true;
    else
        return false;
}
void PatternDatabase::toFile(const string& filePath) const {
    ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

    if (!writer) {
        throw runtime_error("Failed to open the file to write");
    }

    const uint8_t* dataPtr = this->database.data();
    size_t dataSize = this->database.storageSize();

    writer.write(reinterpret_cast<const char*>(dataPtr), dataSize);
    writer.close();
}
bool PatternDatabase::fromFile(const string& filePath) {
    ifstream reader(filePath, ios::in | ios::binary);

    if (!reader.is_open())
        return false;

    reader.read(reinterpret_cast<char*>(this->database.data()), this->database.storageSize());

    if (reader.fail()) {
        reader.close();
        throw runtime_error("Failed to read data from the file");
    }

    reader.close();
    this->numItems = this->size;
    return true;
}
vector<uint8_t> PatternDatabase::inflate() const {
    vector<uint8_t> inflated;
    this->database.inflate(inflated);
    return inflated;
}

void PatternDatabase::reset() {
    if(this->numItems != 0){
        this->database.reset(0xFF);
        this->numItems = 0;
    }
}
