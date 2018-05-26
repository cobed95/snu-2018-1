import java.util.*;
import java.io.*;

public class Maze {
    private final int SIZE;
    public int[][] maze;

    private class Point {
        public int label;
        public int x;
        public int y;
        public Point prev;

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
        
        public boolean isPath(Point point) {
            return point.x >= 0
                && point.x < SIZE 
                && point.y >= 0
                && point.y < SIZE
                && maze[point.x][point.y] == 1 
                && !point.equals(this.prev);
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

        public String toString() {
            return Integer.toString(this.label);
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

    public boolean pathExists(Point point) {
        return point.isPath(point.getRight())
            || point.isPath(point.getLeft())
            || point.isPath(point.getLower())
            || point.isPath(point.getUpper());
    }

    public Point move(Point point) {
        Random rand = new Random();
        Point dest = point;
        while (dest.equals(point)) {
            int direction = rand.nextInt(4);
            if (direction == 0 && point.isPath(point.getRight())) {
                dest = point.getRight();
            } else if (direction == 1 && point.isPath(point.getLeft())) {
                dest = point.getLeft();
            } else if (direction == 2 && point.isPath(point.getLower())) {
                dest = point.getLower();
            } else if (direction == 3 && point.isPath(point.getUpper())) {
                dest = point.getUpper();
            }
        }
        dest.prev = point;
        return dest;
    }

    public String getPath() {
        String path = "";

        Point current = new Point(SIZE*(SIZE-1)+1); 
        Point end = new Point(SIZE);

        while (!current.equals(end)) {
            if (!this.pathExists(current)) {
                current = new Point(SIZE*(SIZE-1)+1);
                path = "";
            }
            path += current.toString();
            path += "-";
            current = this.move(current); 
        }
        path += end.toString();
        
        return path;
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

        String path = maze.getPath();
        
        PrintStream out = new PrintStream(new File(args[1]));
        out.println(path);
    }
}
