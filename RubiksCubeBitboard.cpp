//
// Created by Utsav Dhanuka on 30/06/23.
//
#include "GenericRubiksCube.h"
 class RubiksCubeBitboard : public GenericRubiksCube
 {
 private:
     void rotateFace(int ind){
         uint64_t side=bitboard[ind];
         side=side>>48;
         bitboard[ind]=(bitboard[ind]<<16)|(side);
     }

 public:
     uint64_t bitboard[6]={};
 };
