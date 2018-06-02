import java.util.*;
import java.io.*;

public class Main {
    public final double GAMMA = 0.9;
    public final double EPSILON = 0.5;
    public final int EPISODE = 50;

    public static ArrayList<ArrayList<Point>> buildMaze(Scanner scanner) {
        ArrayList<ArrayList<Point>> maze = new ArrayList<ArrayList<Point>>();
        while (scanner.hasNextLine()) {
            maze.add(new ArrayList<Point>());
            int idx = 0;
            String line = scanner.nextLine();
            Scanner lineScanner = new Scanner(line);
            while (lineScanner.hasNext()) {
                maze.get(idx).add(new Point(lineScanner.nextInt()));
                idx++;
            }
        }
        return maze;
    }

    public static int[] getStart(Maze maze) {
        int[] start = new int[2];

        Random rand = new Random();
        int i = rand.nextInt(maze.getSizeX());
        int j = rand.nextInt(maze.getSizeY());
        while (maze.getPoint(i, j).isWall()) {
            i = rand.nextInt(maze.getSizeX());
            j = rand.nextInt(maze.getSizeY());
        }

        start[0] = i;
        start[1] = j;

        return start;
    }

    public static void monteCarlo(Maze maze, Bot bot, Trace trace) {
                
    }

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = args[0]; 
        Scanner scanner = new Scanner(fileName);
        
        ArrayList<ArrayList<Point>> rawMaze = buildMaze(scanner);
        Maze maze = new Maze(rawMaze);
        maze.setArrIdx();
        maze.setCoord();
        
        int[] startIdx = getStart(maze);
        Bot bot = new Bot(maze.getPoint(startIdx[0], startIdx[1]), maze.getArea());

    }
}
