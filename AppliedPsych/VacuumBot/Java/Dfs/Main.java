import java.util.*;
import java.io.*;

public class Main {
   public static ArrayList<ArrayList<Point>> buildMaze(Scanner scanner) {
       ArrayList<ArrayList<Point>> maze = new ArrayList<ArrayList<Point>>();
       int idx = 0;
       while (scanner.hasNextLine()) {
           maze.add(new ArrayList<Point>());
           String line = scanner.nextLine();
           System.out.println(line);
           Scanner lineScanner = new Scanner(line);
           while (lineScanner.hasNext()) {
               maze.get(idx).add(new Point(lineScanner.nextInt()));
           }
           idx++;
       }
       return maze;
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

   public static Point getNext(Maze maze, Point current, int direction) {
       if (direction == 0) {
           return maze.getEastOf(current);
       } else if (direction == 1) {
           return maze.getWestOf(current);
       } else if (direction == 2) {
           return maze.getSouthOf(current);
       } else if (direction == 3) {
           return maze.getNorthOf(current);
       } else {
           return null;
       }
   }

   public static void traceWall(Maze maze, Bot bot) {
       int direction = 0;
       while (bot.getBattery() > 0) {
           Point next = getNext(maze, bot.getCurrent(), bot.wallTracer.getDirection());
           bot.traceWall(next);
           bot.wallTracer.update(bot.getCurrent());
       }
   }

   public static void learn(Maze maze, Bot bot, int episode, PrintStream log, PrintStream result) {
       int[] startIdx = bot.getCurrent().getArrIdx();
       traceWall(maze, bot);

       int battery = maze.getValidArea() * 2;
       bot.reset(maze.getPoint(startIdx[0], startIdx[1]), battery);
       for (int i = 0; i < episode; i++) {
           bot.dfs(maze.getValidArea());

           printLog(maze, bot, i, log);
           printResult(maze, bot, i, result);

           bot.reset(maze.getPoint(startIdx[0], startIdx[1]), battery);
       }
   }

   public static void printLog(Maze maze, Bot bot, int episode, PrintStream out) {
       out.println("-----------------------------------------------");
       out.println("############## Episode " + episode + " ##############");
       out.println();
       out.println("Maze");
       out.println(maze.toString());
       out.println();
       out.println("Value Map:");
       out.println(bot.mapToString('v'));
       out.println();
       out.println("Trace Map:");
       out.println(bot.mapToString('t'));
       out.println();
       out.println("Trace in list format");
       out.println(bot.listToString());
       out.println();
       out.println("############## Episode finished ##############");
       out.println("-----------------------------------------------");
       out.println();
       out.println();
   }

   public static void printResult(Maze maze, Bot bot, int episode, PrintStream out) {
       out.println("-----------------------------------------------");
       out.println("############## Episode " + episode + " ##############");
       out.println();
       out.println("Covered Area Size:");
       out.println(bot.getCoveredAreaSize());
       out.println();
       out.println("Total Valid Area:");
       out.println(maze.getValidArea());
       out.println();
       out.println("Percentaged covered");
       out.println(((double) bot.getCoveredAreaSize()/maze.getValidArea()) * 100 + "%");
       out.println();
       out.println("############## Episode finished ##############");
       out.println("-----------------------------------------------");
       out.println();
       out.println();
   }

   public static void main(String[] args) throws FileNotFoundException {
       String input = args[0];
       Scanner scanner = new Scanner(new File(input));

       ArrayList<ArrayList<Point>> rawMaze = buildMaze(scanner);
       Maze maze = new Maze(rawMaze);
       maze.setArrIdx();
       maze.setCoord();

       int[] startIdx = getStart(maze);
       int battery = maze.getValidArea()*10;
       double gamma = 0.9;
       double epsilon = 0.5;
       Bot bot = new Bot(maze.getPoint(startIdx[0], startIdx[1]), battery, maze.getSizeX(), maze.getSizeY(), gamma, epsilon);

       PrintStream log = new PrintStream("log.txt");
       PrintStream result = new PrintStream("result.txt");
       learn(maze, bot, 100, log, result);
   }
}


