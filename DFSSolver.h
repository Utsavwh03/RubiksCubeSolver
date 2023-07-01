//
// Created by Utsav Dhanuka on 01/07/23.
//

#ifndef RUBIKSCUBESOLVER_DFSSOLVER_H
#define RUBIKSCUBESOLVER_DFSSOLVER_H

#endif //RUBIKSCUBESOLVER_DFSSOLVER_H
#include "GenericRubiksCube.h"

template<typename T, typename H>
class DFSSolver{
private:
   vector<GenericRubiksCube::MOVE>moves;
    //    DFS code to find the solution (helper function)
    bool dfs(int depth){
        if(rubiksCube.isSolved())return true;
        if(depth>max_depth_search)return false;
        for(int i=0;i<18;i++)
        {
            rubiksCube.move(GenericRubiksCube::MOVE(i));
            moves.push_back(GenericRubiksCube::MOVE(i));
            if(dfs(depth+1)) return true;
            rubiksCube.invert(GenericRubiksCube::MOVE(i));
            moves.pop_back();

        }
            return false;

    }

public:
    T rubiksCube;
    int max_depth_search;
    DFSSolver(T _rubiksCube,int dep){
            rubiksCube=_rubiksCube;
            max_depth_search=dep;
    }
    vector<GenericRubiksCube::MOVE>solve(){
        dfs(1);
        return moves;
    }
};
