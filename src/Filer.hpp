#ifndef FILER_HPP
#define FILER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Filer {
    public:
        Filer() {};
        Filer(string filename);
        std::vector<std::vector<std::vector<int>>> getPuzzles();
        int getNumPuzzles();
        void printPuzzles();

    private:
        std::vector<std::vector<std::vector<int>>> puzzles;
        vector<vector<int>> puzzle;
        void initPuzzle(string puzzleStr[4]);
        int numPuzzles;
};
#endif //FILER_HPP