//
// Created by Utsav Dhanuka on 01/07/23.
//

#ifndef RUBIKSCUBESOLVER_BFSSOLVER_H
#define RUBIKSCUBESOLVER_BFSSOLVER_H

#endif //RUBIKSCUBESOLVER_BFSSOLVER_H
#include "GenericRubiksCube.h"
#include "unordered_map"
#include "queue"
template<typename T,typename H>
class BFSSolver{
private:
    unordered_map<T,bool,H>visited;
    unordered_map<T,GenericRubiksCube::MOVE,H>move_done;

    T bfs(){
        queue<T>q;
        visited[rubiksCube]=1;
        q.push(rubiksCube);
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            if(node.isSolved())
            {
                return node;
            }
            for(int i=0;i<18;i++)
            {
                GenericRubiksCube::MOVE cur_move=GenericRubiksCube::MOVE(i);
                T neigh=node;
                neigh.move(cur_move);
                if(visited[neigh]==0){
                    visited[neigh]=1;
                    move_done[neigh]=cur_move;
                    q.push(neigh);
                }
            }
        }
        return rubiksCube;

    }


public:
    T rubiksCube;
    vector<GenericRubiksCube::MOVE>moves;
    BFSSolver(T _rubikscube){
        rubiksCube=_rubikscube;
    }
    vector<GenericRubiksCube::MOVE>solve(){
        T solved_cube=bfs();
        while(solved_cube!=rubiksCube){
            moves.push_back(move_done[solved_cube]);
            auto cur_move=move_done[solved_cube];
            solved_cube.invert(cur_move);
        }
        reverse(moves.begin(),moves.end());
        return moves;
    }
};