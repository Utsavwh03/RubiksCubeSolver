//
// Created by Utsav Dhanuka on 30/06/23.
//
#include "GenericRubiksCube.h"
 class RubiksCubeBitboard : public GenericRubiksCube
 {
 private:
     uint64_t solved_side_config[6]{};

     uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;
     int arr[3][3] = {{0, 1, 2},
                      {7, 8, 3},
                      {6, 5, 4}};
     void rotateFace(int ind){
         uint64_t side=bitboard[ind];
         side=side>>48;
         bitboard[ind]=(bitboard[ind]<<16)|(side);
     }


 public:
     uint64_t bitboard[6]={};
     RubiksCubeBitboard(){
         for(int side=0;side<6;side++)
         {
             uint64_t set_bit= 1<<side ;
             bitboard[side]=0;
             for(int fac_id =0;fac_id<=7;fac_id++)
             {
                 bitboard[side]|=set_bit<<(8*fac_id);
             }
             solved_side_config[side]=bitboard[side];
         }
     }

     COLOR getColor(FACE face, unsigned row, unsigned col) const override {
         int idx = arr[row][col];
         if (idx == 8) return (COLOR)((int) face);

         uint64_t side = bitboard[(int) face];
         uint64_t color = (side >> (8 * idx)) & one_8;

         int bit_pos = 0;
         while (color != 0) {
             color = color >> 1;
             bit_pos++;
         }
         return (COLOR)(bit_pos - 1);
     }
     bool isSolved() const override {
         for (int i = 0; i < 6; i++) {
             if (solved_side_config[i] != bitboard[i]) return false;
         }
         return true;
     }

 };
