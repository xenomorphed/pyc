#include <builtins.hpp>


void print(pyc::Type content) {
    cout << content.__str__() << endl;
}


string input(pyc::Type message) {
    cout << message.__str__();
    string out;
    cin >> out;
    return out;
}