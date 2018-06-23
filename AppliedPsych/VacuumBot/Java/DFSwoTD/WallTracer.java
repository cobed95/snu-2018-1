import java.util.*;

public class WallTracer {
    private Point prev;
    private ArrayList<Point> wallList;
    
    public WallTracer(Point curr) {
        this.prev = curr;
    }

    public void update(int direction, Point curr) {
        if (this.prev.equals(curr)) {
            updateWallList(direction, curr);
        }
        this.prev = curr;
    }

    private void updateWallList(int direction, Point curr) {
        Point wall = getWall(direction, curr);
        this.wallList.add(wall);
    }

    private Point getWall(int direction, Point curr) {
        Point wall;
        int[] arrIdx = new int[2];
        if (direction == 0) {
            arrIdx[0] = curr.getArrIdx()[0];
            arrIdx[1] = curr.getArrIdx()[1] + 1;
            wall = new Point(arrIdx);
        } else if (direction == 1) {
            arrIdx[0] = curr.getArrIdx()[0];
            arrIdx[1] = curr.getArrIdx()[1] - 1;
            wall = new Point(arrIdx);
        } else if (direction == 2) {
            arrIdx[0] = curr.getArrIdx()[0] + 1;
            arrIdx[1] = curr.getArrIdx()[1];
            wall = new Point(arrIdx);
        } else if (direction == 3) {
            arrIdx[0] = curr.getArrIdx()[0] - 1;
            arrIdx[1] = curr.getArrIdx()[1];
            wall = new Point(arrIdx);
        } else {
            wall = null;
        }
        return wall;
    }

    public boolean searchWallList(Point point) {
        for (Point p : this.wallList) {
            if (p.equals(point)) {
                return true;
            }
        }
        return false;
    }
}
