//
// Created by Utsav Dhanuka on 01/07/23.
//

#ifndef RUBIKSCUBESOLVER_IDDFS_H
#define RUBIKSCUBESOLVER_IDDFS_H

#endif //RUBIKSCUBESOLVER_IDDFS_H
#include "GenericRubiksCube.h"
#include "DFSSolver.h"

template<typename T,typename H>
class IDDFSSolver{
private:
        vector<GenericRubiksCube::MOVE>moves;
public:
    T rubikscube;
    int max_depth;
    IDDFSSolver(T _rubikscube,int _max_depth=8){
        rubikscube=_rubikscube;
        max_depth=_max_depth;
    }
    vector<GenericRubiksCube::MOVE> solve(){
        for(int i=0;i<max_depth;i++){
            DFSSolver<T,H> dfssolve(rubikscube,i);
            moves=dfssolve.solve();
            if(dfssolve.rubiksCube.isSolved()){
                rubikscube=dfssolve.rubiksCube;
                break;
            }
        }
        return moves;
    }
};