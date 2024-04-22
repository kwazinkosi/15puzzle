#include "PuzzleSolver.hpp"

PuzzleSolver::PuzzleSolver(vector<vector<int>> puzzle)
{
    goalState = {{1, 2, 3, 4},
                 {5, 6, 7, 8},
                 {9, 10, 11, 12},
                 {13, 14, 15, -1}};

    this->puzzle = puzzle; // Initialize the puzzle vector to 4x4
}

void PuzzleSolver::solvePuzzle()
{
    int depthLimit = 1;
    int bestCost = 0;
    while (true)
    {
        // create a queue of nodes
        queue<Node> q;
        // create a node with the initial state
        Node node(puzzle, 0, 0, nullptr); // depth and cost are 0, parent is null(root node)
        // push the node to the queue
        q.push(node);
        // while the queue is not empty
        while (!q.empty())
        {
            // get the front node
            Node n = q.front();
            // pop the front node
            q.pop(); // remove the front node from the queue
            // if the node is the goal state
            if (n.isGoalState())
            {
                // print the path to the goal
                printPathToGoal();
                return;
            }
            // if the depth of the node is less than the depth limit
            if (n.getCost() < bestCost)
            {
                // create children of the node
                vector<Node> children = createChildren(&n);
                n.setVisited(true);
                visitedNodes.push_back(n);

                // push the children to the queue
                for (int i = 0; i < children.size(); i++)
                {
                    q.push(children[i]);
                }
            }
        }
        // increment the depth limit
        depthLimit++;
    }
}

void PuzzleSolver::printPathToGoal()
{
}

void PuzzleSolver::printPuzzle()
{
    cout << endl;
    for (int i = 0; i < puzzle.size(); i++)
    {
        cout << " +---+---+---+---+" << endl;
        for (int j = 0; j < puzzle[i].size(); j++)
        {
            cout << (puzzle[i][j]==-1 || puzzle[i][j] >=10 ? " |" : " | ") << puzzle[i][j] << (j >= 3 ? " |" : "");
        }
        cout << endl;
    }
    cout << " +---+---+---+---+" << endl;
}
vector<Node> PuzzleSolver::createChildren(Node *parent)
{
    vector<Node> children;
    int depth = getDepth(parent) + 1;

    // find the position of the empty tile
    int row = 0;
    int col = 0;
    for (int i = 0; i < puzzle.size(); i++)
    {
        for (int j = 0; j < puzzle[i].size(); j++)
        {
            if (puzzle[i][j] == -1)
            {
                row = i;
                col = j;
            }
        }
    }

    // move the empty tile up(numbered tile move down)
    if (row > 0)
    {
        vector<vector<int>> newPuzzle = puzzle;
        swap(newPuzzle[row][col], newPuzzle[row - 1][col]);
        if(!isVisited(newPuzzle))
        {
            Node n(newPuzzle, depth, getMisplacedTiles(newPuzzle), parent);
            children.push_back(n);
        }
    }
    // move the empty tile down (numbered tile move up)
    if (row < puzzle.size() - 1)
    {
        vector<vector<int>> newPuzzle = puzzle;
        swap(newPuzzle[row][col], newPuzzle[row + 1][col]);
        if(!isVisited(newPuzzle))
        {
            Node n(newPuzzle, depth, getMisplacedTiles(newPuzzle), parent);
            children.push_back(n);
        }
    }
    // move the empty tile left (numbered tile move right)
    if (col > 0)
    {
        vector<vector<int>> newPuzzle = puzzle;
        swap(newPuzzle[row][col], newPuzzle[row][col - 1]); // swap the empty tile with the tile to the left
        if(!isVisited(newPuzzle))
        {
            Node n(newPuzzle, depth, getMisplacedTiles(newPuzzle), parent);
            children.push_back(n);
        }
    }
    // move the empty tile right (numbered tiles move left)
    if (col < puzzle[row].size() - 1)
    {
        vector<vector<int>> newPuzzle = puzzle;
        swap(newPuzzle[row][col], newPuzzle[row][col + 1]);
        if(!isVisited(newPuzzle))
        {
            Node n(newPuzzle, depth, getMisplacedTiles(newPuzzle), parent);
            children.push_back(n);
        }
    }
    // order the children based on the number of misplaced tiles, with the lowest number of misplaced tiles first
    sort(children.begin(), children.end(), [](Node a, Node b) { return a.getCost() < b.getCost(); });
    return children;
}

void PuzzleSolver::sortChildren(vector<Node> &children)
{
    
}

bool PuzzleSolver::isVisited(vector<vector<int>> puzzle)
{
    for (int i = 0; i < visitedNodes.size(); i++)
    {
        if (visitedNodes[i].getPuzzle() == puzzle)
        {
            return true;
        }
    }
    return false;
}
// Hueristic function to determine the depth of the expansion
int PuzzleSolver::expansionDepth()
{
    

}

int PuzzleSolver::getMisplacedTiles(vector<vector<int>> puzzle)
{
    int misplaced = 0;
    for (int i = 0; i < puzzle.size(); i++)
    {
        for (int j = 0; j < puzzle[i].size(); j++)
        {
            if (puzzle[i][j] != goalState[i][j])
            {
                misplaced++;
            }
        }
    }
    return misplaced;
}

// Get the depth of the node, by counting the number of parents from the current node to the root node
int PuzzleSolver::getDepth(Node *n)
{
    int depth = 0;
    while (n->getParent() != nullptr)
    {
        depth++;
        n = n->getParent();
    }
    return depth;
}

