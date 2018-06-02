import java.util.*;

public class Maze {
    private ArrayList<ArrayList<Point>> maze;
    private int sizeX;
    private int sizeY;
    
    public Maze(ArrayList<ArrayList<Point>> maze) {
        this.maze = maze;
        this.sizeX = maze.size();
        this.sizeY = maze.get(0).size();
    }

    public Point getPoint(int i, int j) {
        return maze.get(i).get(j);
    }

    public Point getEastOf(Point point) {
        if (point.getArrIdx()[1]+1 < maze.get(point.getArrIdx()[0]).size()) {
            return maze.get(point.getArrIdx()[0]).get(point.getArrIdx()[1]+1);
        } else {
            return point;
        }
    }

    public Point getWestOf(Point point) {
        if (point.getArrIdx()[1]-1 >= 0) {
            return maze.get(point.getArrIdx()[0]).get(point.getArrIdx()[1]-1);
        } else {
            return point;
        }
    }

    public Point getSouthOf(Point point) {
        if (point.getArrIdx()[0]+1 < maze.size()) {
            return maze.get(point.getArrIdx()[0]+1).get(point.getArrIdx()[1]);
        } else {
            return point;
        }
    }

    public Point getNorthOf(Point point) {
        if (point.getArrIdx()[0]-1 >= 0) {
            return maze.get(point.getArrIdx()[0]-1).get(point.getArrIdx()[1]);
        } else {
            return point;
        }
    }

    public int getSizeX() {
        return this.sizeX;
    }

    public int getSizeY() {
        return this.sizeY;
    }
}
