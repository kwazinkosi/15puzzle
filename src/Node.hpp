#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public:
        Node() {};
        Node(vector<vector<int>> puzzle, int depth, int cost, Node* parent);
        vector<vector<int>> getPuzzle();
        
        // Getters and setters
        int getDepth();
        int getCost();
        Node* getParent();
        bool isGoalState();
        void setPuzzle(vector<vector<int>> puzzle);
        void setGoalState(bool goalState);
        void setVisited(bool isVisited);
        void setDepth(int depth);
        void setCost(int cost);
        void setMisplacedTiles(int misplacedTiles);
        void setParent(Node* parent);
        void printPuzzle();

    private:
        vector<vector<int>> puzzle;
        bool goalState;
        int depth;
        int cost;
        bool isVisited;
        bool isInPathToGoal;
        int misplacedTiles;
        Node* parent;
        int initMisplacedTiles();
};

#endif //NODE_HPP