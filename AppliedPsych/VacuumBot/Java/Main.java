import java.util.*;
import java.io.*;

public class Main {
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

    public static void setArrIdx(ArrayList<ArrayList<Point>> rawMaze) {
        for (int i = 0; i < rawMaze.size(); i++) {
            for (int j = 0; j < rawMaze.get(i).size(); j++) {
                int[] arrIdx = new int[2];
                arrIdx[0] = i;
                arrIdx[1] = j;
                rawMaze.get(i).get(j).setArrIdx(arrIdx);
            }
        }
    }
    
    public static int[] getCoordFromIdx(int[] idx, int sizeY) {
        int[] coord = new int[2];
        coord[0] = idx[1];
        coord[1] = sizeY-idx[0]-1;
        return coord;
    }

    public static void setCoord(ArrayList<ArrayList<Point>> rawMaze) {
        for (int i = 0; i < rawMaze.size(); i++) {
            for (int j = 0; j < rawMaze.get(i).size(); j++) {
                rawMaze.get(i).get(j).setCoord(getCoordFromIdx(rawMaze.get(i).get(j).getArrIdx(), rawMaze.size()));
            }
        }
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

    public static void main(String[] args) throws FileNotFoundException {
        String fileName = args[0]; 
        Scanner scanner = new Scanner(fileName);
        
        ArrayList<ArrayList<Point>> rawMaze = buildMaze(scanner);
        setArrIdx(rawMaze); 
        setCoord(rawMaze);
        
        Maze maze = new Maze(rawMaze);
        
        int[] startIdx = getStart(maze);
        Bot bot = new Bot(maze.getPoint(startIdx[0], startIdx[1]));
    }
}
