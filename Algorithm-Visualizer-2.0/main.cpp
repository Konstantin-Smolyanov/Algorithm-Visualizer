#include "Screen.h"
#include "Sorter.h"

using namespace std;

int main(void) {
    Sorter sorter;
    Screen screen;

    cout << "Insert numbers (space seperated)  or  type ";
    cout << "\"d\" for default array [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]\n";

    bool running = 1;
    while (running) {
        vector<int> vect = screen.getVector();        
        char ch = screen.getAlgorithm();

        cout << "Sorting array:\n";
        sorter.sort(vect, ch);
        cout << "\nArray sorted.\n";
        
        if (screen.restartProgram()) running = 1;
        else running = 0;        
    }

    return 0;
}