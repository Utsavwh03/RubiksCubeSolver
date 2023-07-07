#include <iostream>
#include "GenericRubiksCube.h"
#include "RubiksCube3dArray.cpp"
#include "RubiksCube1dArray.cpp"
//#include "RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFS.h"
#include "Solver/IDAStarSolver.h"
#include "vector"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {
    RubiksCube3dArray cube1;
    // cube1.print();
    RubiksCube3dArray cube2;
//    cube2.l();
//    cube2.u2();
//    cube2.print();
    RubiksCubeBitboard cube4;
    cube4.print();
    cout << endl;
    // if(cube1==cube2){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }
    cube4.u();
    cube4.lPrime();
    cube4.print();
    // vector <GenericRubiksCube::MOVE> movestoShuffle;
//    BFSSolver <RubiksCube3dArray,RubiksCube3dArray::Hash3d> cube3(cube2);
//    vector <GenericRubiksCube::MOVE> movestoSolve = cube3.solve();
//    cout << "To solve the above cube, perform following moves:" << endl;
//    for(auto m : movestoSolve){
//        cout<< cube2.getMove(m) <<" ";
//    }
//    cout << endl << endl;
//    cube3.rubiksCube.print();
    //Testing IDDFS for Bitboard
    IDDFSSolver<RubiksCubeBitboard, RubiksCubeBitboard::HashBitboard> cube5(cube4, 8);
    vector<GenericRubiksCube::MOVE> movetosolve = cube5.solve();
    for (auto m: movetosolve) {
        cout << cube4.getMove(m) << " ";
    }
    cout << endl << endl;
    cube5.rubikscube.print();

    //testing IDA* on 1d Array
    string filename = "Database/cornerDepth5V1.txt";
    CornerDBMaker dbMaker(filename, 0x99);
    dbMaker.bfsAndStore();
    RubiksCube1dArray cube1DArray;
    auto shufflemoves = cube1DArray.randomShuffleCube(10);
    IDAStarSolver<RubiksCube1dArray, RubiksCube1dArray::Hash1d> cube6(cube1DArray, filename);
    auto movesA = cube6.solve();
    for (auto m: movesA) {
        cout << cube1DArray.getMove(m) << endl;
    }
    cout << endl;
    cube6.rubiksCube.print();

    return 0;
}