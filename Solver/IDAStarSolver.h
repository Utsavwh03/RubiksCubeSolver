//
// Created by Utsav Dhanuka on 04/07/23.
//

#ifndef RUBIKSCUBESOLVER_IDASTARSOLVER_H
#define RUBIKSCUBESOLVER_IDASTARSOLVER_H
#include "../GenericRubiksCube.h"
#include "vector"
#include "../PatternDatabases/CornerPatternDatabase.h"
#include "unordered_map"
#include "queue"

template<typename T,typename H>
class IDAStarSolver{
private:
    unordered_map<T, GenericRubiksCube::MOVE, H> move_done;
    unordered_map<T, bool, H> visited;
    struct Node{
        int depth,estimate;
        T cube;
        Node(T _cube,int _depth,int _estimate){
            cube=_cube;
            depth=_depth;
            estimate=_estimate;
        }
    };
    class CompareCube{
    public:
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2){
                auto n1=p1.first ;
                auto n2=p2.first;
                if(n1.depth+n1.estimate!=n2.depth+n2.estimate){
                    return n1.depth + n1.estimate > n2.depth + n2.estimate;
                }
                else
                {
                    return n1.estimate > n2.estimate;
                }
        }
    };
    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }
    pair<T, int> IDAstar(int bound) {
//        priority_queue contains pair(Node, move done to reach that)
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, CompareCube> pq;
        Node start = Node(rubiksCube, 0, cornerDB.getNumMoves(rubiksCube));
        pq.push(make_pair(start, 0));
        int next_bound = 100;
        while (!pq.empty()) {
            auto p = pq.top();
            Node node = p.first;
            pq.pop();

            if (visited[node.cube]) continue;

            visited[node.cube] = true;
            move_done[node.cube] = GenericRubiksCube::MOVE(p.second);

            if (node.cube.isSolved()) return make_pair(node.cube, bound);
            node.depth++;
            for (int i = 0; i < 18; i++) {
                auto curr_move = GenericRubiksCube::MOVE(i);
                Node temp=node;
                temp.cube.move(curr_move);
                if (!visited[temp.cube]) {
                    temp.estimate = cornerDB.getNumMoves(temp.cube);
                    if (temp.estimate + temp.depth > bound) {
                        next_bound = min(next_bound, temp.estimate + temp.depth);
                    } else {
                        pq.push(make_pair(temp, i));
                    }
                }
            }

        }
        return make_pair(rubiksCube, next_bound);
    }

public:
    T rubiksCube;
    vector<GenericRubiksCube::MOVE>moves;
    CornerPatternDatabase cornerDB;
    IDAStarSolver(T _rubiksCube, string fileName) {
        rubiksCube = _rubiksCube;
        cornerDB.fromFile(fileName);
    }
    vector<GenericRubiksCube::MOVE> solve() {
            int bound = 1;
            auto p = IDAstar(bound);
            while (p.second != bound) {
                resetStructure();
                bound = p.second;
                p = IDAstar(bound);
            }
            T solved_cube = p.first;
            assert(solved_cube.isSolved());
            T curr_cube = solved_cube;
            while (!(curr_cube == rubiksCube)) {
                moves.push_back(move_done[curr_cube]);
                curr_cube.invert(move_done[curr_cube]);
            }
            rubiksCube = solved_cube;
            reverse(moves.begin(), moves.end());
            return moves;
    }

};

#endif //RUBIKSCUBESOLVER_IDASTARSOLVER_H
