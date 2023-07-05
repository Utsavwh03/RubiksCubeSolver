//
// Created by Utsav Dhanuka on 27/06/23.
//

#ifndef RUBIKSCUBESOLVER_GENERICRUBIKSCUBE_H
#define RUBIKSCUBESOLVER_GENERICRUBIKSCUBE_H
using namespace std;
#include "vector"
#include "string"
#include "iostream"
#include <time.h>

/**
 * A base class for all Rubik's Cube Model. There are various representation for Rubik's Cube.
 * Each one has it's own special ways of definitions. This class provides a shared functionality
 * between all models.
 * We'll benchmark all models and observe which one is better for performance.
 */
class GenericRubiksCube { // defining enums for notations
public:
   enum class FACE {
       UP,
       LEFT,
       FRONT,
       RIGHT,
       BACK,
       DOWN
   };
   enum class COLOR{
       WHITE,
       GREEN,
       RED,
       BLUE,
       ORANGE,
       YELLOW
   };
   enum class MOVE{
       L, LPRIME, L2,
       R, RPRIME, R2,
       U, UPRIME, U2,
       D, DPRIME, D2,
       F, FPRIME, F2,
       B, BPRIME, B2
   };

    /*
        * Returns the color of the cell at (row, col) in face.
        * If Rubik's Cube face is pointing at you, then the row numbering starts from the
        * top to bottom, and column numbering starts from the left to right.
        * The rows and columns are 0-indexed.
        * @param Face, row, and column index
        */
    virtual COLOR getColor(FACE face,unsigned int row,unsigned int col) const=0;

    /*
   * Returns the first letter of the given COLOR
   * Eg: For COLOR::GREEN, it returns 'G'
   */
    static char getColorLetter(COLOR color);
    /*
     * Returns true if the Rubik Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const=0;
    /*
   * Returns the move in the string format.
   */
    static string getMove(MOVE ind);
    /*
    * Print the Rubik Cube in Planar format.
    *
    * The cube is laid out as follows.
    *
    * The sides:
    *    U
    *  L F R B
    *    D
    *
    * Color wise:
    *
    *          W W W
    *          W W W
    *          W W W
    *
    *  G G G   R R R   B B B   O O O
    *  G G G   R R R   B B B   O O O
    *  G G G   R R R   B B B   O O O
    *
    *          Y Y Y
    *          Y Y Y
    *          Y Y Y
    *

    */
    void print() const;
    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
    vector<MOVE> randomShuffleCube(unsigned int times);
    /*
   * Perform moves on the Rubiks Cube
   */
    GenericRubiksCube & move(MOVE ind) ;
    /*
    * Invert a move
    */
    GenericRubiksCube & invert(MOVE ind) ;

    /*
     * Rotational Moves on the Rubik Cubes
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual GenericRubiksCube &f() = 0;

    virtual GenericRubiksCube &fPrime() = 0;

    virtual GenericRubiksCube &f2() = 0;

    virtual GenericRubiksCube &u() =0;

    virtual GenericRubiksCube &uPrime() = 0;

    virtual GenericRubiksCube &u2() = 0;

    virtual GenericRubiksCube &l() = 0;

    virtual GenericRubiksCube &lPrime() = 0;

    virtual GenericRubiksCube&l2() = 0;

    virtual GenericRubiksCube &r() = 0;

    virtual GenericRubiksCube &d() = 0;

    virtual GenericRubiksCube &dPrime() = 0;

    virtual GenericRubiksCube &d2() = 0;

    virtual GenericRubiksCube&rPrime() = 0;

    virtual GenericRubiksCube &r2() = 0;

    virtual GenericRubiksCube &b() = 0;

    virtual GenericRubiksCube &bPrime() = 0;

    virtual GenericRubiksCube &b2() = 0;

 string getCornerColorString(uint8_t ind) const;

 uint8_t getCornerIndex(uint8_t ind) const;

 uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif //RUBIKSCUBESOLVER_GENERICRUBIKSCUBE_H
