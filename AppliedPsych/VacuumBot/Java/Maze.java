import java.util.*;

public class Maze {
    private ArrayList<ArrayList<Point>> maze;
    private int sizeX;
    private int sizeY;
    private int area;
    
    public Maze(ArrayList<ArrayList<Point>> maze) {
        this.maze = maze;
        this.sizeX = maze.size();
        this.sizeY = maze.get(0).size();
        this.area = sizeX * sizeY;
    }

    public Point getPoint(int i, int j) {
        return maze.get(i).get(j);
    }

    public void setArrIdx() {
        for (int i = 0; i < this.sizeX; i++) {
            for (int j = 0; j < this.sizeY; j++) {
                this.getPoint(i, j).setArrIdx(i, j);
            }
        }
    }
    
    public static int[] getCoordFromIdx(int[] idx, int sizeY) {
        int[] coord = new int[2];
        coord[0] = idx[1];
        coord[1] = sizeY-idx[0]-1;
        return coord;
    }
    
    public void setCoord() {
        for (ArrayList<Point> line : this.maze) {
            for (Point point : line) {
                int[] newCoord = getCoordFromIdx(point.getArrIdx(), this.sizeY);
                point.setCoord(newCoord[0], newCoord[1]);
            }
        }
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

    public int getArea() {
        return this.area;
    }
}
