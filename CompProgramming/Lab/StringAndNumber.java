import java.util.*;

class StringAndNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.next();
        for (int i = 0; i < inputString.length(); i++) {
            System.out.print(inputString.charAt(i));
            System.out.print(i+1);
        } System.out.println();
    }
}
