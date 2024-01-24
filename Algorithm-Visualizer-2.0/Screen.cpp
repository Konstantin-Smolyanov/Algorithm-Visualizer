#include "Screen.h"

void Screen::ClearRow() {
    cout << "\r";
}
void Screen::displayVect(vector<int>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
}
void Screen::displayVect(vector<string>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i];
    }
}
void Screen::displayVect(vector<int>& vect, int& pos) {
    for (int i = 0; i < vect.size(); i++) {
        if (i == pos) {
            cout << vect[i] << "|";
        }
        else {
            cout << vect[i] << " ";
        }
    }
}
void Screen::displayWithSpace(vector<string>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        int neededSpaces = button_spacing - vect[i].size();
        if (neededSpaces > 0) {
            vect[i] += string(neededSpaces, ' ');
        }
    }
    displayVect(vect);
}
void Screen::displayArrow(char& ch, vector<string>& vect) {
    if (ch == 'b' || ch == 'B') {
        vect[0] = "[B]<";
    }
    else if (ch == 's' || ch == 'S') {
        vect[1] = "[S]<";
    }
    ClearRow();
    displayWithSpace(vect);
}

void Screen::updateVect(vector<int>& vect) {
    Sleep(tickSpeed);
    ClearRow();
    displayVect(vect);
}
void Screen::updateVect(vector<int>& vect, int& pos) {
    Sleep(tickSpeed);
    ClearRow();
    displayVect(vect, pos);
}

char Screen::getAlgorithm() {
    vector<string> sorters = { "Bubble", "Selection"};
    vector<string> keys = { "[B]", "[S]"};
    cout << "Choose sorting algorithm:\n";
    displayWithSpace(sorters);
    cout << endl;
    displayWithSpace(keys);

    char buff;
    buff = _getch();
    displayArrow(buff, keys);
    cout << endl;

    return buff;
}
vector<int> Screen::getVector() {
    vector<int> vect;
    string buff;
    getline(cin, buff);

    if (buff == "d" || buff == "D") vect = defaultArray;
    else {
        int num;
        stringstream istr(buff);
        while (istr >> num) {
            vect.push_back(num);
        }
    }

    // speed program up if vector is large
    if (vect.size() > 5) tickSpeed = (tickSpeed * 4) / vect.size();

    return vect;
}
bool Screen::restartProgram() {
    cout << "Press [R] to insert new array  or  press any key to Exit.";
    char key;
    key = _getch();
    if (key == 'r' || key == 'R') {
        ClearRow();
        cout << "Insert numbers  or  type \"d\" for default                   \n";
        return 1;
    }
    else return 0;
}