import java.util.*;
import java.io.*;

public class Maze {
    private final int SIZE;
    public int[][] maze;

    private class Point {
        public int label;
        public int x;
        public int y;

        public Point(int label) {
            this.label = label;
            this.x = (label-1) / SIZE;
            this.y = (label-1) % SIZE;
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
            this.label = (SIZE*x) + y + 1;
        }

        public Point getUpper() {
            return new Point(x-1, y);
        }

        public Point getLower() {
            return new Point(x+1, y);
        }

        public Point getLeft() {
            return new Point(x, y-1);
        }

        public Point getRight() {
            return new Point(x, y+1);
        }

        public boolean equals(Object o) {
            if (o instanceof Point) {
                Point other = (Point) o;
                return (this.x == other.x && this.y == other.y && this.label == other.label);
            } else {
                return false;
            }
        }

        public int hashCode() {
            return Objects.hash(label, x, y);
        }
    }

    private class Runner {
        public Point current;
        public Point[] path;
        public int pathTail;

        public Runner() {
            this.current = new Point((SIZE*SIZE) - (SIZE-1));
            this.path = new Point[SIZE*SIZE];
            this.pathTail = 0;
        }

        public void updatePath() {
            this.path[this.pathTail] = current;
            this.pathTail++;
        }

        public int[] getPossibleSteps() {
            int[] possibleSteps = new int[4];
            int idx = 0;
            if (isRoad(this.current.getRight()) && !this.current.getRight().equals(this.path[pathTail])) {
                possibleSteps[idx] = 0;
                idx++;
            } else if (isRoad(this.current.getLeft()) && !this.current.getLeft().equals(this.path[pathTail])) {
                possibleSteps[idx] = 1;
                idx++;
            } else if (isRoad(this.current.getLower()) && !this.current.getLower().equals(this.path[pathTail])) {
                possibleSteps[idx] = 2;
                idx++;
            } else if (isRoad(this.current.getUpper()) && !this.current.getUpper().equals(this.path[pathTail])) {
                possibleSteps[idx] = 3;
                idx++;
            }
            
            int[] result = new int[idx];
            for (int i = 0; i < idx; i++) {
                result[i] = possibleSteps[i];
            }
            
            return result;
        

        public boolean isAtDeadEnd() {
            return true;
        }

        public int getDirection() {
            Random rand = new Random();
            return rand.nextInt(4);
        }

        public void move() {
            int east = 0;
            int west = 1;
            int south = 2;
            int north = 3;
            
            int[] possibleSteps = getPossibleSteps();
            if (possibleSteps.length == 0) {
                this.current = new Point(SIZE-1, 0);
                this.path = new Point[SIZE*SIZE];
                this.pathTail = 0;
            } else {

            }
        }
    }

    public Maze(int lineCount, Scanner mazeScanner) {
        this.SIZE = lineCount;
        this.maze = new int[SIZE][];
        for (int i = 0; i < SIZE; i++) {
            int[] line = new int[SIZE];
            this.maze[i] = line;
        }
        
        int rowIdx = 0;
        while (rowIdx < SIZE && mazeScanner.hasNextLine()) {
            String line = mazeScanner.nextLine();
            Scanner lineScanner = new Scanner(line);
            int columnIdx = 0;
            while (columnIdx < SIZE && lineScanner.hasNext()) {
                this.maze[rowIdx][columnIdx] = lineScanner.nextInt();
                columnIdx++;
            }
            rowIdx++;
        }
    }

    public boolean isRoad(Point point) {
        return point.x < SIZE && point.y < SIZE && this.maze[point.x][point.y] == 1;
    }

    public static int countLines(Scanner lineCounter) {
        int count = 0;
        while (lineCounter.hasNextLine()) {
            count++;
            String aux = lineCounter.nextLine();
        }
        return count;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner lineCounter = new Scanner(new File(args[0]));
        int lineCount = countLines(lineCounter);
        
        Scanner mazeScanner = new Scanner(new File(args[0]));
        Maze maze = new Maze(lineCount, mazeScanner);
    }
}
