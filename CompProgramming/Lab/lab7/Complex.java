import java.util.*;

public class Complex {
    public int a;
    public int b;

    public Complex(int real, int imaginary) {
        a = real;
        b = imaginary;
    }

    public static Complex sum(Complex c1, Complex c2) {
        Complex result = new Complex(c1.a + c2.a, c1.b + c2.b);
        return result;
    }

    public static Complex difference(Complex c1, Complex c2) {
        Complex result = new Complex(c1.a - c2.a, c1.b - c2.b);
        return result;
    }

    public String toString() {
        if (this.b == 0) {
            return Integer.toString(a);
        } else if (a == 0) {
            return b + "i";  
        } else if (this.b > 0) {
            return a + "+" + b + "i";
        } else {
            return Integer.toString(a) + b + "i";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Input the real part of first number: ");
        int a1 = scanner.nextInt();
        System.out.print("Input the imaginary of first number: ");
        int b1 = scanner.nextInt();
        Complex c1 = new Complex(a1, b1);

        System.out.print("Input the real part of second number: ");
        int a2 = scanner.nextInt();
        System.out.print("Input the imaginary of second number: ");
        int b2 = scanner.nextInt();
        Complex c2 = new Complex(a2, b2);

        Complex sumResult = Complex.sum(c1, c2);
        Complex differenceResult = Complex.difference(c1, c2);

        System.out.println("Sum: " + sumResult.toString());
        System.out.println("Difference: " + differenceResult.toString());
    }
}
