import java.util.*;

class NumericDigitAdder {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputNumericWord = scanner.next();
        int sum = 0;
        for (int i = 0; i < inputNumericWord.length(); i++) {
            sum += Integer.parseInt(inputNumericWord.substring(i, i+1));
        }
        System.out.println(sum);
    }
}
