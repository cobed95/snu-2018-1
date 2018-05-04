import java.util.*;

class DiagTable {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();

        int[][] table = new int[size][];
        for (int i = 0; i < size; i++) {
            int[] row = new int[size];
            table[i] = row;
        }

        int content = 1;
        int diagIdx = 0;
        int ptr;
        while (diagIdx < (size*2) - 1) {
            int cmpVal;
            if (diagIdx < size) {
                ptr = 0;
                cmpVal = diagIdx;
                
            } else {
                ptr = diagIdx - (size-1);
                cmpVal = size - ptr;
            }
            while (ptr <= cmpVal) {
                table[ptr][diagIdx-ptr] = content;
                ptr++;
                content++;
            }
            diagIdx++;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(table[i][j] + "\t");
            }
            System.out.println();
        }
    }
}
