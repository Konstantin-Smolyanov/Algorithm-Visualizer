#include "Sorter.h"

void Sorter::bubbleSort(vector<int>& vect) {
    updateVect(vect);
    for (int j = 0; j < vect.size(); j++) {
        for (int i = 0; i < vect.size() - 1; i++) {
            if (vect[i + 1] < vect[i]) {
                int buff = vect[i];
                vect[i] = vect[i + 1];
                vect[i + 1] = buff;

                updateVect(vect, i);
            }
        }
    }

    updateVect(vect);
}

void Sorter::selectionSort(vector<int>& vect) {
    updateVect(vect);

    for (int j = 0; j < vect.size()-1; j++)    {
        int minPos = j;
        for (int i = j+1; i < vect.size(); i++) {
            if (vect[i] < vect[minPos]) {   // find min
                minPos = i;
            }
            updateVect(vect, i);
        }
        if (minPos != j) {
            int buff = vect[j];             // swap
            vect[j] = vect[minPos];
            vect[minPos] = buff;
        }
    } 

    updateVect(vect);
}

void Sorter::sort(vector<int>& vect, char& ch) {
    if      (ch == 'b' || ch == 'B') bubbleSort(vect);
    else if (ch == 's' || ch == 'S') selectionSort(vect);
}