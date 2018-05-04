import java.io.*;
import java.util.*;

class ArrayStorageInFile {
    public static void main(String[] args) throws FileNotFoundException {
        int[] array = new int[20];
        for (int i = 0; i < 20; i++) {
            array[i] = 5 * (i+1);
        }
        
        PrintStream output1 = new PrintStream(new File("out1.txt"));
        for (int i = 0; i < 20; i++) {
            output1.println(array[i]);
        }

        PrintStream output2 = new PrintStream(new File("out2.txt"));
        output2.println(Arrays.toString(array));
    }
}
