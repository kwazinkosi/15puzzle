#include "Node.hpp"

Node::Node(vector<vector<int>> puzzle, int depth, int cost, Node *parent)
{
    this->puzzle = puzzle; // Initialize the puzzle vector to 4x4
    this->misplacedTiles = initMisplacedTiles();
    this->depth = depth;
    this->cost = cost;
    this->parent = parent;
    this->isInPathToGoal = false;
    this->isVisited = false;
    this->goalState = false;
}

vector<vector<int>> Node::getPuzzle()
{
    return puzzle;
}

int Node::getDepth()
{
    return depth;
}

int Node::getCost()
{
    return misplacedTiles + depth;
}

Node* Node::getParent()
{
    return parent;
}

bool Node::isGoalState()
{
    return goalState;
}

void Node::setPuzzle(vector<vector<int>> puzzle)
{
    this->puzzle = puzzle;
}

void Node::setGoalState(bool goalState)
{
    this->goalState = goalState;
}

void Node::setVisited(bool isVisited)
{
    this->isVisited = isVisited;
}

void Node::setDepth(int depth)
{
    this->depth = depth;
}

void Node::setCost(int cost)
{
    this->cost = cost;
}

void Node::setMisplacedTiles(int misplacedTiles)
{
    this->misplacedTiles = misplacedTiles;
}

void Node::setParent(Node* parent)
{
    this->parent = parent;
}   
void Node::printPuzzle()
{
    for(size_t i = 0; i < puzzle.size(); i++) {
        for(size_t j = 0; j < puzzle[i].size(); j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

int Node::initMisplacedTiles()
{
    int num = 1;
    for(int i =0; i< 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(puzzle[i][j] != num && puzzle[i][j] != -1) {
                misplacedTiles++;
            }
            num++;
        }
    }
}
