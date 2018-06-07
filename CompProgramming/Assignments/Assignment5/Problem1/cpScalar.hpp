#include <iostream>

using namespace std;

class cpScalar {
    public : 
        cpScalar(int num);
        cpScalar(double num);
        ~cpScalar();

        cpScalar Add(const cpScalar &s) const;
        cpScalar Multiply(const cpScalar &s) const;
        cpScalar Inverse() const;

        void Insert(ostream &sout) const;
    protected :
        int GetIntVal() const;
        double GetRealVal() const;
        bool IsInt() const;

        void SetIntVal(int intVal);
        void SetRealVal(double realVal);
        void SetIsInt(bool isInt);
    private :
        int IntVal;
        double RealVal;
        bool IsInt;
};

cpScalar(int num) {
    IntVal = num;
    RealVal = num * 1.0;
    IsInt = true;
}

cpScalar(double num) {
    RealVal = num;
    IsInt = false;
}

cpScalar Add(const cpScalar &s) const {
    if (IsInt() && s.IsInt()) {
        int a = GetIntVal();
        int b = s.GetIntVal();
        return cpScalar(a+b);
    } else {
        double a = GetRealVal();
        double b = s.GetRealVal();
        return cpScalar(a+b);
    }
}

cpScalar Multiply(const cpScalar &s) const {
    if (IsInt() && s.IsInt()) {
        int a = GetIntVal();
        int b = s.GetIntVal();
        return cpScalar(a*b);
    } else {
        double a = GetRealVal();
        double b = s.GetRealVal();
        return cpScalar(a*b);
    }
}

cpScalar Inverse() const {
    return cpScalar(1/GetRealVal());
}

void Insert(ostream &sout) const {
    if (IsInt()) {
        sout << GetIntVal();
    } else {
        sout << GetRealVal();
    }
    return;
}

int GetIntVal() const {
    return IntVal;
}

double GetRealVal() const {
    return RealVal;
}

bool IsInt() const {
    return IsInt;
}

void SetIntVal(int intVal) {
    IntVal = intVal;
}

void SetRealVal(double realVal) {
    RealVal = realVal;
}

void SetIsInt(bool isInt) {
    IsInt = isInt;
}

cpScalar& operator=(const cpScalar& r) {
    if (r.IsInt()) {
        SetIntVal(r.GetIntVal());
    }
    
    SetRealVal(r.GetRealVal());
    SetIsInt(r.IsInt());
    
    return *this;
}

cpScalar operator+(const cpScalar &r, const cpScalar &s) {
    return r.Add(s);
}

cpScalar operator-(const cpScalar &r, const cpScalar &s) {
    return r.Add(s.Multiply(cpScalar(-1)));
}

cpScalar operator*(const cpScalar &r, const cpScalar &s) {
    return r.Multiply(s);
}

cpScalar operator/(const cpScalar &r, const cpScalar &s) {
    return r.Multply(s.Inverse())
}

cpScalar operator<<(ostream &sout, const cpScalar &s) {
    s.Insert(sout);
    return sout;
}
