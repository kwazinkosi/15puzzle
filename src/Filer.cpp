#include "Filer.hpp"

Filer::Filer(string filename)
{   
    puzzle.resize(4, vector<int>(4)); // Initialize the puzzle vector to 4x4
    ifstream file(filename);
    if (file.is_open()) {
        string lineStr;
        int row = 0;
        string puzzleArr[4];
        while (getline(file, lineStr, '\n')) {
            
            if(row == 4) {
                initPuzzle(puzzleArr);
                puzzles.push_back(puzzle);
                row = 0;
            } else {
                puzzleArr[row] = lineStr;
                row++;
            }
        }
        // Process the last puzzle if the file doesn't end with an empty line
        if (row == 4) {
            initPuzzle(puzzleArr);
            puzzles.push_back(puzzle);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    numPuzzles = puzzles.size();
}

int Filer::getNumPuzzles()
{
    return numPuzzles;
}

void Filer::printPuzzles()
{
    for(size_t i = 0; i < puzzles.size(); i++) {
        for(size_t j = 0; j < 4; j++) {
            for(size_t k = 0; k < 4; k++) {
                cout << puzzles[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Filer::initPuzzle(string puzzleStr[4])
{
    for(size_t i = 0; i < 4; i++) {
        string num = "";
        int col = 0;
        for(size_t j = 0; j < puzzleStr[i].length(); j++) {
            if(puzzleStr[i][j] != ' ' && j <= puzzleStr[i].length() ) {
                num += puzzleStr[i][j];
                if(j == puzzleStr[i].length()-1) {
                    puzzle[i][col] = stoi(num);
                }
            } 
            else {
                puzzle[i][col] = stoi(num);
                col++;
                num = "";   
            }
        }
    }
    // puzzle.clear();
    // puzzle.resize(4, vector<int>(4));
}