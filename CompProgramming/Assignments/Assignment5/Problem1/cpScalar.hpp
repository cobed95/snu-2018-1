#include <iostream>

using namespace std;

class cpScalar {
public:
    cpScalar(int num = 0);
    cpScalar(double num);
    ~cpScalar();

    cpScalar Add(const cpScalar &s) const;
    cpScalar Multiply(const cpScalar &s) const;
    cpScalar Inverse() const;

    ostream& Insert(ostream &sout) const;
protected:
    int GetIntVal() const;
    double GetRealVal() const;
    bool checkInt() const;
private:
    int IntVal;
    double RealVal;
    bool IsInt;
};

cpScalar::cpScalar(int num) {
    IntVal = num;
    RealVal = num * 1.0;
    IsInt = true;
    cout << "scalar" << endl;
    cout << RealVal << endl;
}

cpScalar::cpScalar(double num) {
    RealVal = num;
    IsInt = false;
    cout << "scalar" << endl;
    cout << RealVal << endl;
}

cpScalar::~cpScalar() {

}

int cpScalar::GetIntVal() const {
    return IntVal;
}

double cpScalar::GetRealVal() const {
    return RealVal;
}

bool cpScalar::checkInt() const {
    return IsInt;
}

cpScalar cpScalar::Add(const cpScalar &s) const {
    if (checkInt() && s.checkInt()) {
        int a = GetIntVal();
        int b = s.GetIntVal();
        return cpScalar(a+b);
    } else {
        double a = GetRealVal();
        double b = s.GetRealVal();
        return cpScalar(a+b);
    }
}

cpScalar cpScalar::Multiply(const cpScalar &s) const {
    if (checkInt() && s.checkInt()) {
        int a = GetIntVal();
        int b = s.GetIntVal();
        return cpScalar(a*b);
    } else {
        double a = GetRealVal();
        double b = s.GetRealVal();
        return cpScalar(a*b);
    }
}

cpScalar cpScalar::Inverse() const {
    return cpScalar(1/GetRealVal());
}

ostream& cpScalar::Insert(ostream &sout) const {
    if (checkInt()) {
        sout << GetIntVal();
    } else {
        sout << GetRealVal();
    }
    return sout;
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
    return r.Multiply(s.Inverse());
}

ostream& operator<<(ostream &sout, const cpScalar &s) {
    return s.Insert(sout);
}
