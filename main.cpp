#include <iostream>
#include "GenericRubiksCube.h"
#include "RubiksCube3dArray.cpp"
#include "DFSSolver.h"
#include "vector"
using namespace std;
int main() {

//    RubiksCube3dArray cube1;
//    cube1.print();
    RubiksCube3dArray cube2;
    cube2.u();
    cube2.print();
//    if(cube1==cube2)
//    {
//        cout<<"Same"<<endl;
//    }
//    else
//    {
//        cout<<"Not Same"<<endl;
//    }
    vector<GenericRubiksCube::MOVE>movestoShuffle=cu
    DFSSolver<RubiksCube3dArray,RubiksCube3dArray::Hash3d> cube3(cube2,5);
    vector<GenericRubiksCube::MOVE>movestoSolve=cube3.solve();
    for(auto m : movestoSolve){
        cout<<cube2.getMove(m)<<" ";
    }
    cube3.rubiksCube.print();

    return 0;

}
