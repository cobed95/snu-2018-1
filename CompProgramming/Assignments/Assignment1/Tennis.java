import java.util.*;

class Tennis {
    public static void match(int m, int g, Scanner scanner) {
        int[] setsWon = new int[2];
        setsWon[0] = 0; 
        setsWon[1] = 0;
        String finishedSet = "Current: ";
        while (g == 0 && setsWon[0] != 3 && setsWon[1] != 3) {
            int atSet = setsWon[0] + setsWon[1] + 1;
            int[] setScore = set(atSet, m, 5, finishedSet, scanner);
            if (setScore[0] > setScore[1]) {
                setsWon[0] += 1;
            } else if (setScore[1] > setScore[0]) {
                setsWon[1] += 1;
            }
            
            if (setScore[2] == 0 && setScore[3] == 0) {
                finishedSet = finishedSet + setScore[0] + "-" + setScore[1] + " ";
            } else {
                finishedSet = finishedSet + setScore[0] + "-" + setScore[1] + "(" + setScore[2] + "-" + setScore[3] + ")" + " ";
            }
        }
        
        while (g == 1 && setsWon[0] != 2 && setsWon[1] != 2) {
            int atSet = setsWon[0] + setsWon[1] + 1;
            int[] setScore = set(atSet, m, 3, finishedSet, scanner);
            if (setScore[0] > setScore[1]) {
                setsWon[0] += 1;
            } else if (setScore[1] > setScore[0]) {
                setsWon[1] += 1;
            }
            
            if (setScore[2] == 0 && setScore[3] == 0) {
                finishedSet = finishedSet + setScore[0] + "-" + setScore[1] + " ";
            } else {
                finishedSet = finishedSet + setScore[0] + "-" + setScore[1] + "(" + setScore[2] + "-" + setScore[3] + ")" + " ";
            }
        } System.out.println(finishedSet);
        System.out.println("Game Finished!");
    }

    public static int[] set(int atSet, int m, int maxSet, String finishedSet, Scanner scanner) {
        int[] setScore = new int[4];
        setScore[0] = 0;
        setScore[1] = 0;
        while (!setFinished(setScore)) {
            if (setScore[0] == 6 && setScore[1] == 6) {
                if (!(m == 0 && atSet == maxSet)) {
                    int[] tiebreakScore = tiebreak(finishedSet, setScore, scanner);
                    setScore[2] = tiebreakScore[0];
                    setScore[3] = tiebreakScore[1];
                    if (tiebreakScore[0] > tiebreakScore[1]) {
                        setScore[0] += 1;
                    } else if (tiebreakScore[1] > tiebreakScore[0]) {
                        setScore[1] += 1;
                    } break;
                } else {
                    setScore[game(finishedSet, setScore, scanner)] += 1;
                }
            } else { 
                setScore[game(finishedSet, setScore, scanner)] += 1;
            }
        } return setScore;
    }

    public static boolean setFinished(int[] setScore) {
        if (setScore[0] >= 6 && setScore[0] >= setScore[1]+2) {
            return true;
        } else if (setScore[1] >= 6 && setScore[1] >= setScore[0]+2) {
            return true;
        } else {
            return false;
        }
    }
    
    public static int[] tiebreak(String finishedSet, int[] setScore, Scanner scanner) {
        int[] tiebreakScore = new int[2];
        tiebreakScore[0] = 0;
        tiebreakScore[1] = 0;   

        while (!tiebreakFinished(tiebreakScore)) {
            System.out.print(finishedSet);
            System.out.print(setScore[0] + "-" + setScore[1]);
            if (tiebreakScore[0] == 0 && tiebreakScore[1] == 0) {
                System.out.println();
            } else {
                System.out.println("(" + tiebreakScore[0] + "-" + tiebreakScore[1] + ")");
            }
            System.out.print("Type the winner (L: Left/R: Right): ");
            String tiebreakWinner = scanner.next();
            if (tiebreakWinner.equals("L")) {
                tiebreakScore[0] += 1;
            } else if (tiebreakWinner.equals("R")) {
                tiebreakScore[1] += 1;
            }
        } return tiebreakScore; 
    }

    public static boolean tiebreakFinished(int[] tiebreakScore) {
        if (tiebreakScore[0] >= 7 && tiebreakScore[0] >= tiebreakScore[1]+2) {
            return true;
        } else if (tiebreakScore[1] >= 7 && tiebreakScore[1] >= tiebreakScore[0]+2) {
            return true;
        } else {
            return false;
        }
    }

    public static int game(String finishedSet, int[] setScore, Scanner scanner) {
        int[] gameScore = new int[2];
        gameScore[0] = 0;
        gameScore[1] = 0;

        while (gameScore[0] != 50 && gameScore[1] != 50) {
            if (gameScore[0] == 0 && gameScore[1] == 0) {
                System.out.print(finishedSet);
                System.out.print(setScore[0] + "-" + setScore[1]);
                System.out.println();
            } else {
                System.out.print(finishedSet);
                System.out.print(setScore[0] + "-" + setScore[1]);
                System.out.println("(" + gameScore[0] + "-" + gameScore[1] + ")");
            }
            System.out.print("Type the winner (L: Left/R: Right): ");
            String gameWinner = scanner.next();
            int i = -1; 
            int j = -1;
            if (gameWinner.equals("L")) {
                i = 0;
                j = 1;
            } else if (gameWinner.equals("R")) {
                i = 1;
                j = 0;
            }
            
            if (gameScore[i] < 30) {
                gameScore[i] += 15;
            } else if (gameScore[i] == 30) {
                gameScore[i] += 10;
            } else if (gameScore[i] == 40) {
                if (gameScore[j] == 40) {
                    if (i == 0) {
                        System.out.print(finishedSet);
                        System.out.print(setScore[0] + "-" + setScore[1]);
                        System.out.println("(40A-40)");
                        System.out.print("Type the winner (L: Left/R: Right): ");
                        gameWinner = scanner.next();
                        if (gameWinner.equals("L")) {
                            return 0;
                        } else if (gameWinner.equals("R")) {
                            continue;  
                        }
                    } else {
                        System.out.print(finishedSet);
                        System.out.print(setScore[0] + "-" + setScore[1]);
                        System.out.println("(40-40A)");
                        System.out.print("Type the winner (L: Left/R: Right): ");
                        gameWinner = scanner.next();
                        if (gameWinner.equals("L")) {
                            continue;
                        } else if (gameWinner.equals("R")) {
                            return 1;
                        }
                    }
                } else {
                    gameScore[i] += 10;
                }
            }
        } if (gameScore[0] == 50) return 0;
        else if (gameScore[1] == 50) return 1;
        else return -1;
    }

    
    public static void ausOpen(String gender, Scanner scanner) {
        if (gender.equals("M")) {
            System.out.println("Australian Open/Male chosen.");
            match(0, 0, scanner);
        } else if (gender.equals("F")) {
            System.out.println("Australian Open/Female chosen.");
            match(0, 1, scanner);
        }
    }
    
    public static void usOpen(String gender, Scanner scanner) {
        if (gender.equals("M")) {
            System.out.println("US Open/Male chosen."); 
            match(1, 0, scanner);
        } else if (gender.equals("F")) {
            System.out.println("US Open/Female chosen.");
            match(1, 1, scanner);
        }
    }

    public static void getMatchAndGender() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Type the match (A: Australian Open/U: US Open): ");
        String match = scanner.next();
        System.out.print("Type the gender (F: Female/M: Male): ");
        String gender = scanner.next();
        if (match.equals("A")) ausOpen(gender, scanner);
        else if (match.equals("U")) usOpen(gender, scanner);
    }
    
    public static void main(String[] args) {
        getMatchAndGender();
    }
}
