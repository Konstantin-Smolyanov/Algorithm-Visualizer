#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <utility>

using namespace std;

class Screen {
private:
    vector<int> defaultArray = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    const int button_spacing = 25;
    int tickSpeed = 300;
    void ClearRow();
    void displayVect(vector<int>& vect);
    void displayVect(vector<string>& vect);
    void displayVect(vector<int>& vect, int& pos);
    void displayWithSpace(vector<string>& vect);
    void displayArrow(char& ch, vector<string>& vect);

protected:
    void updateVect(vector<int>& vect);
    void updateVect(vector<int>& vect, int& pos);

public:
    char getAlgorithm();
    vector<int> getVector();
    bool restartProgram();
};
