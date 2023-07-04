//
// Created by Utsav Dhanuka on 04/07/23.
//

#ifndef RUBIKSCUBESOLVER_PATTERNDATABASE_H
#define RUBIKSCUBESOLVER_PATTERNDATABASE_H
#include "NibbleArray.h"
#include "../GenericRubiksCube.h"

class PatternDatabase {
    NibbleArray database;
    size_t size;
    size_t numItems;

protected:
    PatternDatabase();

public:
    PatternDatabase(const size_t size);
//    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const GenericRubiksCube &cube) const = 0;

    virtual bool setNumMoves(const GenericRubiksCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const GenericRubiksCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual bool fromFile(const string &filePath);

    virtual void toFile(const string &filePath) const;


    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};


#endif //RUBIKSCUBESOLVER_PATTERNDATABASE_H
