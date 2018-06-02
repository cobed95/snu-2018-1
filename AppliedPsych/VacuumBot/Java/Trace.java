import java.util.*;

public class Trace {
    private ArrayList<ArrayList<Integer>> traceMap;
    private ArrayList<Point> traceList;
    
    public Trace(ArrayList<ArrayList<Integer>> rawMaze) {
        for (int i = 0; i < rawMaze.size(); i++) {
            ArrayList<Integer> line = new ArrayList<Integer>();
            this.traceMap.add(line);
            for (int j = 0; j < rawMaze.get(i).size(); j++) {
                this.traceMap.get(i).add(0);
            }
        } 
    }

    public void addToList(Point point) {
        this.traceList.add(point);
    }

    public void addVisit(int[] arrIdx) {
        this.traceMap.get(arrIdx[0]).get(arrIdx[1]) += 1;
    }

    public void printMap() {
        
    }

    public void printList() {

    }
}
