#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> lst;
list<char>::iterator lst2; //basically a list to make a lookahead mechanism

void G();
void M();
void Y();
void Z();

void check(char expected) {
    if (lst2 != lst.end() && *lst2 == expected) {
        ++lst2;
    } else {
        cout << "Sequence is not acceptable." << endl;
        exit(1);
    }
}

void G() {
    check('(');
    M();
    check(')');
}

void M() {
    Y();
    Z();
}

void Z() {
    if (lst2 != lst.end() && *lst2 == '*') {
        check('*');
        M();
    } else if (lst2 != lst.end() && (*lst2 == '+' || *lst2 == '-')) {
        check(*lst2);
        M();
    } else {

    }
}

void Y() {
    if (lst2 != lst.end() && (*lst2 == 'a' || *lst2 == 'b')) {
        ++lst2;
    } else if (lst2 != lst.end() && *lst2 == '(') {
        G();
    } else {
        cout << "Sequence is not acceptable." << endl;
        exit(1);
    }
}

int main() {
    string input;
    cout << "Give a string: ";
    cin >> input;

    for (char c : input) {
        lst.push_back(c);
    }

    lst2 = lst.begin();

    G();

    if (lst2 != lst.end()) {
        cout << "Sequence is not acceptable." << endl;
    } else {
        cout << "Sequence is acceptable." << endl;
    }

    return 0;
}
