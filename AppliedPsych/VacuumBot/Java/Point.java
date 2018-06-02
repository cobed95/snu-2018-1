public class Point {
    private int x;
    private int y;
    private int[] arrIdx;
    private int isWall;

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

    public void setCoord(int[] coord) {
        this.x = coord[0];
        this.y = coord[1];
    }

    public void setArrIdx(int[] arrIdx) {
        this.arrIdx = arrIdx;
    }

    public boolean isWall() {
        if (isWall == 0) {
            return false;
        } else {
            return true;
        }
    }
}
