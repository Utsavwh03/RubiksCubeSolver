//
// Created by Utsav Dhanuka on 05/07/23.
//

#ifndef RUBIKSCUBESOLVER_CORNERDBMAKER_H
#define RUBIKSCUBESOLVER_CORNERDBMAKER_H
#include "CornerPatternDatabase.h"
#include "../RubiksCubeBitboard.cpp"
using namespace std;
class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};


#endif //RUBIKSCUBESOLVER_CORNERDBMAKER_H
