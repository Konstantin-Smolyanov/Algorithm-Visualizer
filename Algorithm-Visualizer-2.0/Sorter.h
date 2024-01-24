#pragma once
#include "Screen.h"

class Sorter : public Screen {
private:
    void bubbleSort(vector<int>& vect);
    void selectionSort(vector<int>& vect);
public:
    void sort(vector<int>& vect, char& ch);
};