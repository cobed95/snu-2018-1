import java.util.*;

public class Bot {
   private Point current;
   private int battery;

   private int sizeX;
   private int sizeY;

   private double[][] valueMap;
   private int[][] rewardMap;

   private int[][] traceMap;
   private ArrayList<Point> traceList;

   private double gamma;
   private double epsilon;

   private ArrayList<Point> coveredArea;

   public WallTracer wallTracer;

   private ArrayList<Point> visited;

   public Bot(Point start, int battery, int sizeX, int sizeY, double gamma, double epsilon) {
       this.current = start;
       this.battery = battery;

       this.sizeX = sizeX;
       this.sizeY = sizeY;

       this.initValueMap();
       this.initRewardMap();

       this.initTraceMap();
       this.traceList = new ArrayList<Point>();
       this.traceList.add(start);

       this.gamma = gamma;
       this.epsilon = epsilon;

       this.coveredArea = new ArrayList<Point>();
       this.coveredArea.add(current);

       this.wallTracer = new WallTracer(start);
   }

   public void reset(Point start, int battery) {
       this.current = start;
       this.battery = battery;
       initTraceMap();
       this.traceList = new ArrayList<Point>();
       this.traceList.add(start);
       this.coveredArea = new ArrayList<Point>();
       this.coveredArea.add(current);
   }

   public void initTraceMap() {
       this.traceMap = new int[this.sizeX][];
       for (int i = 0; i < this.sizeX; i++) {
           int[] line = new int[this.sizeY];
           traceMap[i] = line;
           for (int j = 0; j < this.sizeY; j++) {
               traceMap[i][j] = 0;
           }
       }
       this.traceMap[this.current.getArrIdx()[0]][this.current.getArrIdx()[1]] = 1;
   }
   public void initValueMap() {
       this.valueMap = new double[this.sizeX][];
       for (int i = 0; i < this.sizeX; i++) {
           double[] line = new double[this.sizeY];
           this.valueMap[i] = line;
           for (int j = 0; j < this.sizeY; j++) {
               this.valueMap[i][j] = 0;
           }
       }
   }

   public void initRewardMap() {
       this.rewardMap = new int[this.sizeX][];
       for (int i = 0; i < this.sizeX; i++) {
           int[] line = new int[this.sizeY];
           this.rewardMap[i] = line;
           for (int j = 0; j < this.sizeY; j++) {
               this.rewardMap[i][j] = -1;
           }
       }
   }

   private Integer getTraceMapPoint(int i, int j) {
       return this.traceMap[i][j];
   }

   public Point getCurrent() {
       return this.current;
   }

   public int getBattery() {
       return this.battery;
   }

   public double[][] getValueMap() {
       return this.valueMap;
   }

   public int[][] getRewardMap() {
       return this.rewardMap;
   }

   public int[][] getTraceMap() {
       return this.traceMap;
   }

   public ArrayList<Point> getTraceList() {
       return this.traceList;
   }

   public String mapToString(char option) {
       String result = "";
       for (int i = 0; i < this.sizeX; i++) {
           result += "[";
           for (int j = 0; j < this.sizeY; j++) {
               if (option == 'v') {
                   result += this.valueMap[i][j];
               } else if (option == 't') {
                   result += this.traceMap[i][j];
               }
               result += ", ";
           }
           result += "]\n";
       }
       return result;
   }

   public String listToString() {
       String result = "[";
       for (Point p : this.traceList) {
           result += p.toString();
           result += ", "; }
       result += "]";
       return result;
   }

   public int getCoveredAreaSize() {
       return this.coveredArea.size();
   }

   public void dfs(int validArea) {
       if (!taskFinished(validArea)) {
           ArrayList<Point> toVisit = getList();
           mergesort(toVisit, 0, toVisit.size());
           for (Point p : toVisit) {
               if (this.wallTracer.searchWallList(p) || this.visited(p)) {
                   continue;
               }
               Point prev = this.current;
               this.move(p); 
               this.dfs(validArea); 
               this.move(prev);
           }
       }
   }

   private void mergesort(ArrayList<Point> toVisit, int p, int r) {
       if (p < r) {
           int q = (p + r) / 2;
           mergesort(toVisit, p, q);
           mergesort(toVisit, q + 1, r);
           merge(toVisit, p, q, r);
       }
   }

   private void merge(ArrayList<Point> toVisit, int p, int q, int r) {
       ArrayList<Point> left = new ArrayList<Point>();
       ArrayList<Point> right = new ArrayList<Point>();
       for (int i = p; i <= q; i++) {
           left.add(toVisit.get(i));
       }
       for (int j = q + 1; j < r; j++) {
           right.add(toVisit.get(j));
       }

       int i = 0;
       int j = 0;
       for (int k = p; k < r; k++) {
           if (i < left.size() && j < right.size() && leftIsLarger(left.get(i), right.get(j))) {
               toVisit.set(k, left.get(i));
               i++;
           } else if (i < left.size() && j < right.size() && !leftIsLarger(left.get(i), right.get(j))) {
               toVisit.set(k, right.get(j));
               j++;
           } else if (i >= left.size() && j < right.size()) {
               toVisit.set(k, right.get(j));
               j++;
           } else if (i < left.size() && j >= right.size()) {
               toVisit.set(k, left.get(i));
               i++;
           }
       }
   }

   private boolean leftIsLarger(Point a, Point b) {
       if (this.valueMap[a.getArrIdx()[0]][a.getArrIdx()[1]] > this.valueMap[b.getArrIdx()[0]][b.getArrIdx()[1]]) {
           return true;
       } else {
           return false;
       }
   }

   private boolean visited(Point p) {
       for (Point v : this.traceList) {
           if (p.equals(v)) {
               return true;
           }
       }
       return false;
   }

   private ArrayList<Point> getList() {
       int[] directions = {0, 1, 2, 3}; 
       ArrayList<Point> toVisit = new ArrayList<Point>();
       for (int direction : directions) {
           Point p = getPoint(direction);
           if (p.getArrIdx()[0] >= this.sizeX 
                   || p.getArrIdx()[1] >= this.sizeY 
                   || p.getArrIdx()[0] < 0
                   || p.getArrIdx()[1] < 0
                   || this.wallTracer.searchWallList(p)) {
               continue;
           }
           toVisit.add(getPoint(direction));
       }
       return toVisit;
   }

   private Point getPoint(int direction) {
       Point point;
       int[] arrIdx = new int[2];
       if (direction == 0) {
           arrIdx[0] = this.current.getArrIdx()[0];
           arrIdx[1] = this.current.getArrIdx()[1] + 1;
           point = new Point(arrIdx);
       } else if (direction == 1) {
           arrIdx[0] = this.current.getArrIdx()[0];
           arrIdx[1] = this.current.getArrIdx()[1] - 1;
           point = new Point(arrIdx);
       } else if (direction == 2) {
           arrIdx[0] = this.current.getArrIdx()[0] + 1;
           arrIdx[1] = this.current.getArrIdx()[1];
           point = new Point(arrIdx);
       } else if (direction == 3) {
           arrIdx[0] = this.current.getArrIdx()[0] - 1;
           arrIdx[1] = this.current.getArrIdx()[1];
           point = new Point(arrIdx);
       } else {
           point = null;
       }
       return point;
   }

   /*
   public int epsilonGreedy(Maze maze) {
       int[] directions = {0, 1, 2, 3};
       double[] probability = getProbability(maze);

       RandomSelector rs = new RandomSelector(directions, probability);
       int direction = rs.select();
       return direction;
   }
   */

   /*
   private double[] getProbability(Maze maze) {
       double[] probability = new double[4];

       double[] valueArr = new double[4];
       double eastValue = this.getValue(maze, this.getEastIdx());
       double westValue = this.getValue(maze, this.getWestIdx());
       double southValue = this.getValue(maze, this.getSouthIdx());
       double northValue = this.getValue(maze, this.getNorthIdx());
       valueArr[0] = eastValue;
       valueArr[1] = westValue;
       valueArr[2] = southValue;
       valueArr[3] = northValue;

       double maxValue = getMax(valueArr);
       int n = numWhereEquals(valueArr, maxValue);
       int m = 4-n;
       for (int i = 0; i < valueArr.length; i++) {
           if (valueArr[i] == maxValue) {
               probability[i] = (1-this.epsilon)/n;
           } else {
               probability[i] = epsilon/m;
           }
       }
       return probability;
   }
   */

   /*
   private double getMax(double[] arr) {
       double max = arr[0];
       for (int i = 1; i < arr.length; i++) {
           if (arr[i] > max) {
               max = arr[i];
           }
       }
       return max;
   }
   */

   /*
   private int numWhereEquals(double[] arr, double val) {
       int cnt = 0;
       for (int i = 0; i < arr.length; i++) {
           if (arr[i] == val) {
               cnt++;
           }
       }
       return cnt;
   }
   */

   private int[] getEastIdx() {
       int[] east = this.current.getArrIdx();
       east[1]++;
       return east;
   }

   private int[] getWestIdx() {
       int[] west = this.current.getArrIdx();
       west[1]--;
       return west;
   }

   private int[] getSouthIdx() {
       int[] south = this.current.getArrIdx();
       south[0]++;
       return south;
   }

   private int[] getNorthIdx() {
       int[] north = this.current.getArrIdx();
       north[0]--;
       return north;
   }

   private double getValue(Maze maze, int[] arrIdx) {
       if (arrIdx[0] <= 0 || arrIdx[0] >= sizeX || arrIdx[1] <= 0 || arrIdx[1] >= sizeY || maze.getPoint(arrIdx[0], arrIdx[1]).isWall()) {
           return -999999;
       }
       return this.valueMap[arrIdx[0]][arrIdx[1]];
   }

   public void move(Point next) {
       this.current = next;
       this.battery--;
       this.traceList.add(this.current);
       this.traceMap[current.getArrIdx()[0]][current.getArrIdx()[1]]++;
       this.updateValue();
       this.updateCoveredArea();
   }

   public void traceWall(Point next) {
        this.current = next;
        this.battery--;
   }

   private void updateValue() {
       this.epsilon *= 0.9;
       int[] currentIdx = this.current.getArrIdx();
       int[] previousIdx = this.traceList.get(traceList.size()-2).getArrIdx();
       double G = rewardMap[previousIdx[0]][previousIdx[1]] + (this.gamma * valueMap[currentIdx[0]][currentIdx[1]]);
       this.valueMap[previousIdx[0]][previousIdx[1]] += (1.0/traceMap[previousIdx[0]][previousIdx[1]]) * (G - valueMap[previousIdx[0]][previousIdx[1]]);
   }

   private void updateCoveredArea() {
       if (!isInList(this.coveredArea, this.current)) {
           this.coveredArea.add(this.current);
       }
   }

   private boolean isInList(ArrayList<Point> list, Point point) {
       for (Point p : list) {
           if (p.equals(point)) {
               return true;
           }
       }
       return false;
   }

   public boolean taskFinished(int validArea) {
       ArrayList<Point> validTrace = new ArrayList<Point>();
       for (Point p : this.traceList) {
           if (!isInList(validTrace, p)) {
               validTrace.add(p);
           }
       }
       if (validTrace.size() == validArea) {
           return true;
       } else {
           return false;
       }
   }
}


