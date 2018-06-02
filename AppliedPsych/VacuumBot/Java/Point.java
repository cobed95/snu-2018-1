import java.util.*;

public class Point {
    private int x;
    private int y;
    private int[] arrIdx;
    private int isWall;
    private double value;
    private double reward;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(int isWall) {
        this.isWall = isWall;
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point(int[] arrIdx) {
        this.arrIdx = arrIdx;
    }

    public int getX() {
        return this.x;
    }

    public int getY() {
        return this.y;
    }

    public int[] getArrIdx() {
        return this.arrIdx;
    }

    public void setCoord(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setArrIdx(int i, int j) {
        int[] newArrIdx = new int[2];
        newArrIdx[0] = i;
        newArrIdx[1] = j;
        this.arrIdx = newArrIdx;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public void setReward(double reward) {
        this.reward = reward;
    }

    public boolean isWall() {
        if (isWall == 0) {
            return false;
        } else {
            return true;
        }
    }

    public boolean equals(Object o) {
        if (o instanceof Point) {
            Point other = (Point) o;
            return (this.x == other.x) && (this.y == other.y);
        } else {
            return false;
        }
    }

    public int hashCode() {
        return Objects.hash(this.x, this.y);
    }

    public String coordToString() {
        return "(" + this.x + "," + this.y + ")";
    }

    public String valueToString() {
        return String.valueOf(this.value);
    }
}
