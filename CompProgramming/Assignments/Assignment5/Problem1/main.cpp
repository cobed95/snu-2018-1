#include "cpVector.hpp"

using namespace std;

int main() {
    cpScalar s = cpScalar(1);
    cpScalar t = cpScalar(2.5);

    cout << s << endl;
    cout << t << endl;
    cout << s + t << endl;
    cout << s - t << endl;
    cout << s * t << endl;
    cout << s / t << endl;

    cpScalar sarr1[2] = {s, t};
    cpVector v = cpVector(sarr1, 2);
    cpScalar sarr2[2] = {cpScalar(3), cpScalar(4.5)};
    cpVector w = cpVector(sarr2, 2);

    cpVector sumvw = v + w;
    cpVector sumvs = v + s;
    cpVector sumsv = s + v;
    cpVector diffvw = v - w;
    cpVector diffvs = v - s;
    cpVector mulvs = v * s;
    cpVector mulsv = s * v;
    cpVector divvs = v / s;

    cout << v << endl;
    cout << w << endl;
    cout << v+w << endl;
    cout << v+s << endl;
    cout << s+v << endl;
    cout << v-w << endl;
    cout << v-s << endl;
    cout << v*w << endl;
    cout << v*s << endl;
    cout << s*v << endl;
    cout << v/s << endl;

    return 0;
}
