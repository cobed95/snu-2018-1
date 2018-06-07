import java.util.*;

public class Maze {
    private ArrayList<ArrayList<Point>> maze;
    private int sizeX;
    private int sizeY;
    private int area;
    private int validArea;
    
    public Maze(ArrayList<ArrayList<Point>> maze) {
        this.maze = maze;
        this.sizeX = maze.size();
        this.sizeY = maze.get(0).size();
        this.area = sizeX * sizeY;
        this.setValidArea();
    }

    private void setValidArea() {
        int validArea = 0;
        for (ArrayList<Point> line : this.maze) {
            for (Point point : line) {
                if (point.isWall()) {
                    continue;
                }
                validArea++;
            }
        }
        this.validArea = validArea;
    }

    public int getValidArea() {
        return this.validArea;
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
    
    public static int[] getCoordFromIdx(int[] idx, int sizeX) {
        int[] coord = new int[2];
        coord[0] = idx[1];
        coord[1] = sizeX-idx[0]-1;
        return coord;
    }
    
    public void setCoord() {
        for (ArrayList<Point> line : this.maze) {
            for (Point point : line) {
                int[] newCoord = getCoordFromIdx(point.getArrIdx(), this.sizeX);
                point.setCoord(newCoord[0], newCoord[1]);
            }
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
    
    public Point getEastOf(Point point) {
        int i = point.getArrIdx()[0];
        int j = point.getArrIdx()[1];
        if (j+1 < this.sizeY && !getPoint(i, j+1).isWall()) {
            return maze.get(point.getArrIdx()[0]).get(point.getArrIdx()[1]+1);
        } else {
            return point;
        }
    }

    public Point getWestOf(Point point) {
        int i = point.getArrIdx()[0];
        int j = point.getArrIdx()[1];
        if (j-1 >= 0 && !getPoint(i, j-1).isWall()) {
            return maze.get(point.getArrIdx()[0]).get(point.getArrIdx()[1]-1);
        } else {
            return point;
        }
    }

    public Point getSouthOf(Point point) {
        int i = point.getArrIdx()[0];
        int j = point.getArrIdx()[1];
        if (i+1 < maze.size() && !getPoint(i+1, j).isWall()) {
            return maze.get(point.getArrIdx()[0]+1).get(point.getArrIdx()[1]);
        } else {
            return point;
        }
    }

    public Point getNorthOf(Point point) {
        int i = point.getArrIdx()[0];
        int j = point.getArrIdx()[1];
        if (i-1 >= 0 && !getPoint(i-1, j).isWall()) {
            return maze.get(point.getArrIdx()[0]-1).get(point.getArrIdx()[1]);
        } else {
            return point;
        }
    }

    public String toString() {
        String result = "";
        for (ArrayList<Point> list : this.maze) {
            result += listToString(list);
            result += "\n";
        }
        return result;
    }

    public String listToString(ArrayList<Point> list) {
        String result = "[";
        for (Point p : list) {
            result += p.toString();
            result += ", ";
        }
        result += "]";
        return result;
    }
}
