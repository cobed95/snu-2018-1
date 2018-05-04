import java.util.*;

class Spiral {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dimension = scanner.nextInt();
        int[][] spiral = new int[dimension][dimension];
        
        int i = 0;
        int j = 0;
        int number = 1;
        while (number <= dimension * dimension) {
            if (i >= 0 && i < dimension && j >= 0 && j < dimension) {
                spiral[i][j] = number;
                number++;
            }
            if (i == dimension) i--;
            if (j == dimension) j--;
        }

        for (int[] row : spiral) {
            for (int element : row) {
                System.out.print(element + "/t");
            } System.out.println();
        }
    }
}

/*
 *  1   2   3   4
 *  12  13  14  5
 *  11  16  15  6
 *  10  9   8   7
 */
