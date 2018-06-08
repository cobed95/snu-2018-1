//
// Created by Eundo Lee on 2018. 6. 7..
//
#include "cpScalar.hpp"

class cpVector {
public:
    cpVector(cpScalar* sarr, unsigned int size);
    cpVector(const cpVector &copy);
    ~cpVector();

    cpVector Add(const cpVector &v) const;
    cpScalar Dot(const cpVector &v) const;

    cpVector Add(const cpScalar &s) const;
    cpVector Multiply(const cpScalar &s) const;

    ostream& Insert(ostream &sout) const;
    
    cpVector& operator=(const cpVector &copy);
protected:
    cpScalar GetScalar(int i) const;
    unsigned int GetSize() const;
private:
    cpScalar *ScalarArr;
    unsigned int Size;
};

cpVector::cpVector(cpScalar *sarr, unsigned int size) {
    ScalarArr = new cpScalar[size];
    for (int i = 0; i < size; i++) {
        ScalarArr[i] = sarr[i];
    }
    Size = size;
}

cpVector::cpVector(const cpVector &copy) {
    Size = copy.GetSize();
    ScalarArr = new cpScalar[Size];
    for (int i = 0; i < Size; i++) {
        ScalarArr[i] = copy.GetScalar(i);
    }
}

cpVector& cpVector::operator=(const cpVector &copy) {
    Size = copy.GetSize();
    ScalarArr = new cpScalar[Size];
    for (int i = 0; i < Size; i++) {
        ScalarArr[i] = copy.GetScalar(i);
    }
    return *this;
}

cpVector::~cpVector() {
    delete[] ScalarArr;
}

cpScalar cpVector::GetScalar(int i) const {
    return ScalarArr[i];
}

unsigned int cpVector::GetSize() const {
    return Size;
}

cpVector cpVector::Add(const cpVector &v) const {
    cpScalar newArr[Size];
    if (Size == v.GetSize()) {
        for (int i = 0; i < Size; i++) {
            newArr[i] = GetScalar(i) + v.GetScalar(i);
        }
    } else {
        cerr << "Error: Addition of two vectors of different lengths" << endl;
    }
    cpVector result = cpVector(newArr, Size);
    return result;
}

cpScalar cpVector::Dot(const cpVector &v) const {
    cpScalar s = cpScalar(0);
    if (Size == v.GetSize()) {
        for (int i = 0; i < Size; i++) {
            s = s.Add(GetScalar(i).Multiply(v.GetScalar(i)));
        }
    } else {
        cerr << "Error: Multiplication of two vectors of different lengths" << endl;
    }
    return s;
}

cpVector cpVector::Add(const cpScalar &s) const {
    cpScalar sarr[Size];
    for (int i = 0; i < Size; i++) {
        sarr[i] = s.Add(GetScalar(i));
    }
    cpVector result = cpVector(sarr, Size);
    return result;
}

cpVector cpVector::Multiply(const cpScalar &s) const {
    cpScalar sarr[Size];
    for (int i = 0; i < Size; i++) {
        sarr[i] = s.Multiply(GetScalar(i));
    }
    cpVector result = cpVector(sarr, Size);
    return cpVector(sarr, Size);
}

ostream& cpVector::Insert(ostream &sout) const {
    sout << "[";
    for (int i = 0; i < Size-1; i++) {
        sout << GetScalar(i) << ", ";
    }
    sout << GetScalar(Size-1) << "]";
    return sout;
}

cpVector operator+(const cpVector &v, const cpVector &w) {
    return v.Add(w);
}

cpVector operator+(const cpVector &v, const cpScalar &s) {
    return v.Add(s);
}

cpVector operator+(const cpScalar &s, const cpVector &v) {
    return v.Add(s);
}

cpVector operator-(const cpVector &v, const cpVector &w) {
    const cpVector negated = w.Multiply(cpScalar(-1));
    return v.Add(negated);
}

cpVector operator-(const cpVector &v, const cpScalar &s) {
    const cpScalar negated = s.Multiply(cpScalar(-1));
    return v.Add(negated);
}

cpScalar operator*(const cpVector &v, const cpVector &w) {
    return v.Dot(w);
}

cpVector operator*(const cpVector &v, const cpScalar &s) {
    return v.Multiply(s);
}

cpVector operator*(const cpScalar &s, const cpVector &v) {
    return v.Multiply(s);
}

cpVector operator/(const cpVector &v, const cpScalar &s) {
    const cpScalar inverse = s.Inverse();
    return v.Multiply(inverse);
}

ostream& operator<<(ostream &sout, cpVector v) {
    return v.Insert(sout);
}
