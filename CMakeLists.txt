cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp GenericRubiksCube.cpp GenericRubiksCube.h RubiksCube3dArray.cpp RubiksCube1dArray.cpp RubiksCubeBitboard.cpp Solver/DFSSolver.h Solver/BFSSolver.h Solver/IDDFS.h Solver/IDAStarSolver.h PatternDatabases/NibbleArray.cpp PatternDatabases/NibbleArray.h PatternDatabases/CornerPatternDatabase.cpp PatternDatabases/CornerPatternDatabase.h PatternDatabases/PatternDatabase.cpp PatternDatabases/PatternDatabase.h PatternDatabases/math.cpp PatternDatabases/math.h PatternDatabases/PermutationIndexer.h PatternDatabases/CornerDBMaker.cpp PatternDatabases/CornerDBMaker.h)
