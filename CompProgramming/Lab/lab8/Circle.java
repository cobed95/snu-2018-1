interface Shape {
    double getArea();
    double getPerimeter();
}

public class Circle implements Shape {
    double radius;
    public Circle(double newRadius) {
        radius = newRadius;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    public static void main(String[] args) {
        Circle c = new Circle(1.0);
        Triangle t = new Triangle(3.0, 4.0, 5.0);
        Regtangle r = new Regtangle(2.0, 5.0);

        System.out.println(c.getArea());
        System.out.println(c.getPerimeter());
        System.out.println(t.getArea());
        System.out.println(t.getPerimeter());
        System.out.println(r.getArea());
        System.out.println(r.getPerimeter());
    }
}

class Triangle implements Shape {
    double a;
    double b;
    double c;
    public Triangle(double newA, double newB, double newC) {
        a = newA;
        b = newB;
        c = newC;
    }

    public double getArea() {
        double s = (a + b + c)/2;
        return Math.sqrt(s * (s-a) * (s-b) * (s-c));
    }

    public double getPerimeter() {
        return a + b + c;
    }
}

class Regtangle implements Shape {
    double w;
    double h;
    public Regtangle(double newW, double newH) {
        w = newW;
        h = newH;
    }

    public double getArea() {
        return w * h;
    }

    public double getPerimeter() {
        return (w * 2) + (h * 2);
    }
}
