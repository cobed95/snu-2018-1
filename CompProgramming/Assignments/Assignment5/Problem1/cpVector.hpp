#include <iostream>

class cpVector {
    public :
        cpVector(cpScalar[] sarr, unsigned int size);
        ~cpVector();

        cpVector Add(cpVector &v) const;
        cpVector Dot(cpVector &v) const;

        cpVector Add(cpScalar &s) const;
        cpVector Multiply(cpScalar &s) const;
    private :
        cpScalar[] ScalarArr;
        unsigned int Size;
};
