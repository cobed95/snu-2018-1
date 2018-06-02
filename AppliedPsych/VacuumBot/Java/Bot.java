import java.util.*;

public class Bot {
    private Point current;
    private int battery;
    private ArrayList<ArrayList<Integer>> traceMap;
    private ArrayList<Point> traceList;
    
    public Bot(Point start, int battery, int sizeX, int sizeY) {
        this.current = start;
        this.battery = battery;
        setTraceMap(sizeX, sizeY);
        this.traceMap.get(start.getArrIdx()[0]).get(start.getArrIdx()[1]) += 1;
        this.traceList.add(start);
    }

    public void setTraceMap(int sizeX, int sizeY) {
        this.traceMap = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < sizeX; i++) {
            ArrayList<Integer> line = new ArrayList<Integer>();
            this.traceMap.add(line);
            for (int j = 0; j < sizeY; j++) {
                this.traceMap.get(i).add(0);
            }
        }
    }

    public Point getCurrent() {
        return this.current;
    }

    public void move(Point next) {
        this.current = next;
        this.battery--;
    }
}
