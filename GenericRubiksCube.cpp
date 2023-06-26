//
// Created by Utsav Dhanuka on 27/06/23.
//

#include "GenericRubiksCube.h"

//
//Given a color return it's first letter
//

 char GenericRubiksCube::getColorLetter(GenericRubiksCube::COLOR color) {
     if (color == COLOR::BLUE) {
         return 'B';
     } else if (color == COLOR::GREEN) {
         return 'G';
     } else if (color == COLOR::RED) {
         return 'R';
     } else if (color == COLOR::YELLOW) {
         return 'Y';
     } else if (color == COLOR::WHITE) {
         return 'W';
     } else if (color == COLOR::ORANGE) {
         return 'O';
     }
}
string GenericRubiksCube::getMove(GenericRubiksCube::MOVE ind) {
    if (ind == MOVE::L) {
        return "L";
    } else if (ind == MOVE::LPRIME) {
        return "L'";
    } else if (ind == MOVE::L2) {
        return "L2";
    } else if (ind == MOVE::R) {
        return "R";
    } else if (ind == MOVE::RPRIME) {
        return "R'";
    } else if (ind == MOVE::R2) {
        return "R2";
    } else if (ind == MOVE::U) {
        return "U";
    } else if (ind == MOVE::UPRIME) {
        return "U'";
    } else if (ind == MOVE::U2) {
        return "U2";
    } else if (ind == MOVE::D) {
        return "D";
    } else if (ind == MOVE::DPRIME) {
        return "D'";
    } else if (ind == MOVE::D2) {
        return "D2";
    } else if (ind == MOVE::F) {
        return "F";
    } else if (ind == MOVE::FPRIME) {
        return "F'";
    } else if (ind == MOVE::F2) {
        return "F2";
    } else if (ind == MOVE::B) {
        return "B";
    } else if (ind == MOVE::BPRIME) {
        return "B'";
    } else if (ind == MOVE::B2) {
        return "B2";
    }
}
/*
 * Perform a move operation on using a Move index.
 */
