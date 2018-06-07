#include <iostream>
#include "cpVector.hpp"

using namespace std;

int main() {
    cpScalar s = cpScalar(1);
    cpScalar t = cpScalar(2.5);
    cout << s << endl;
    cout << t << endl;
    cout << s + t << endl;
    
    cpScalar v [2] = {s, t};

    return 0;
}
