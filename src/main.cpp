#include <iostream>
#include "Filer.hpp"
#include "PuzzleSolver.hpp"

using namespace std;

int main() {
    
    Filer filer("15_puzzle.txt");
    
    for (int i = 0; i < filer.getNumPuzzles(); i++)
    {
        PuzzleSolver puzzleSolver(filer.getPuzzles()[i]);
        puzzleSolver.solvePuzzle();
        puzzleSolver.printPathToGoal();
    }
    

    // filer.printPuzzles();
    return 0;
}