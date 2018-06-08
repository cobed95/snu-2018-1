//
// Created by Eundo Lee on 2018. 6. 7..
//
#include "cpScalar.hpp"

class cpVector {
public:
    cpVector(cpScalar sarr[], unsigned int size);
    ~cpVector();

    cpVector Add(const cpVector &v) const;
    cpScalar Dot(const cpVector &v) const;

    cpVector Add(const cpScalar &s) const;
    cpVector Multiply(const cpScalar &s) const;

    ostream& Insert(ostream &sout) const;

    friend cpVector operator+(const cpVector &v, const cpVector &w);
    friend cpVector operator+(const cpVector &v, const cpScalar &s);
    friend cpVector operator+(const cpScalar &s, const cpVector &v);
    friend ostream& operator<<(ostream &sout, cpVector &v);
protected:
    cpScalar GetScalar(int i) const;
    unsigned int GetSize() const;
private:
    cpScalar *ScalarArr;
    unsigned int Size;
};

cpVector::cpVector(cpScalar *sarr, unsigned int size) {
    ScalarArr = new cpScalar[size];
    ScalarArr = sarr;
    Size = size;
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
    cpScalar *newArr = new cpScalar[Size];
    if (Size == v.GetSize()) {
        for (int i = 0; i < Size; i++) {
            newArr[i] = GetScalar(i) + v.GetScalar(i);
        }
    } else {
        cerr << "Error: Addition of two vectors of different lengths" << endl;
    }
    return cpVector(newArr, Size);
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
    cpScalar *sarr = new cpScalar[Size];
    for (int i = 0; i < Size; i++) {
        sarr[i] = s.Add(GetScalar(i));
    }
    return cpVector(sarr, Size);
}

cpVector cpVector::Multiply(const cpScalar &s) const {
    cpScalar *sarr = new cpScalar[Size];
    for (int i = 0; i < Size; i++) {
        sarr[i] = s.Multiply(GetScalar(i));
    }
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
    return v.Add(w.Multiply(cpScalar(-1)));
}

cpVector operator-(const cpVector &v, const cpScalar &s) {
    return v.Add(s.Multiply(cpScalar(-1)));
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
    return v.Multiply(s.Inverse());
}

ostream& operator<<(ostream &sout, cpVector &v) {
    return v.Insert(sout);
}

