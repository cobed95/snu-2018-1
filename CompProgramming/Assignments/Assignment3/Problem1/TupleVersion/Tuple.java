public class Tuple<X, Y, Z> {
    private X x;
    private Y y;
    private Z z;

    public Tuple(X x, Y y, Z z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public X first() {
        return this.x;
    }

    public Y second() {
        return this.y;
    }

    public Z third() {
        return this.z;
    }

    public void setFirst(X x) {
        this.x = x;
    }

    public void setSecond(Y y) {
        this.y = y;
    }

    public void setThird(Z z) {
        this.z = z;
    }
}
