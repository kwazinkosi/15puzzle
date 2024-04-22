#ifndef PUZZLESOLVER_HPP
#define PUZZLESOLVER_HPP

#include <iostream>
#include <vector>
#include <queue>
#include "Node.hpp"
#include <algorithm>

using namespace std;

// PuzzleSolver class, which will solve the 15-puzzle(IDS + heuristic)
class PuzzleSolver
{
    public:
        PuzzleSolver(vector<vector<int>> puzzle);
        void solvePuzzle();
        void printPathToGoal();
        void printPuzzle();

    private:
        vector<vector<int>> goalState;
        vector<vector<int>> puzzle;
        vector<Node> pathToGoal;
        vector<Node> visitedNodes;
        vector<Node> createChildren(Node *parent);
        void sortChildren(vector<Node> &children);
        bool isVisited(vector<vector<int>> puzzle);
        int expansionDepth();
        int getMisplacedTiles(vector<vector<int>> puzzle);
        int getDepth(Node *n);
        
};
#endif //PUZZLESOLVER_HPP
        