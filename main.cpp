#include <iostream>
#include "GenericRubiksCube.h"
#include "GenericRubiksCube.cpp"
#include "RubiksCube3dArray.cpp"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFS.h"
#include "vector"

using namespace std;

int main(){
    RubiksCube3dArray cube1;
    // cube1.print();
    RubiksCube3dArray cube2;
    cube2.l();
    cube2.u2();
    cube2.print();
    // if(cube1==cube2){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }

    // vector <GenericRubiksCube::MOVE> movestoShuffle;
    BFSSolver <RubiksCube3dArray,RubiksCube3dArray::Hash3d> cube3(cube2);
    vector <GenericRubiksCube::MOVE> movestoSolve = cube3.solve();
    cout << "To solve the above cube, perform following moves:" << endl;
    for(auto m : movestoSolve){
        cout<< cube2.getMove(m) <<" ";
    }
    cout << endl << endl;
    cube3.rubiksCube.print();

    return 0;
}
