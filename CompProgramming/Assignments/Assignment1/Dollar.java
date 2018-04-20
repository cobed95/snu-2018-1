import java.util.*;

class Dollar {
    public static void partA(int maxLength) {
        System.out.println("(a)");
        
        int[] dollarSignArray = getDollarSignArray(maxLength);
        int idx = 0;
        while (dollarSignArray[idx] <= maxLength) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            }
            for (int i = 0; i < dollarSignArray[idx]; i++) {
                System.out.print('$');
            } System.out.println();
            if (dollarSignArray[idx] == maxLength) break;
            idx++;
        }         
        
        int maxWaistDepth;
        if (maxLength % 2 == 0) {
            maxWaistDepth = (idx+1)/2;
        } else maxWaistDepth = idx/2;
        if (maxWaistDepth == 0) maxWaistDepth = 1;
        
        int waistidx; 
        if (idx == 0) waistidx = 0; 
        else waistidx = idx - maxWaistDepth;

        if (maxLength > 2) idx--;
        while (idx >= waistidx) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            }
            for (int i = 0; i < dollarSignArray[idx]; i++) {
                System.out.print('$');
            } System.out.println();
            if (idx == waistidx) break;
            idx--;
        }
        
        if (maxLength > 2) idx++;
        while (dollarSignArray[idx] < maxLength) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            }
            for (int i = 0; i < dollarSignArray[idx]; i++) {
                System.out.print('$');
            } System.out.println();
            idx++;
        } for (int i = 0; i < maxLength; i++) {
            System.out.print('$');
        } System.out.println();

        idx--;
        while (idx >= 0) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            }
            for (int i = 0; i < dollarSignArray[idx]; i++) {
                System.out.print('$');
            } System.out.println();
            idx--;
        }
    }

    public static void partB(int maxLength) {
        System.out.println("(b)");

        int[] dollarSignArray = getDollarSignArray(maxLength);
        int idx = 0;

        while (dollarSignArray[idx] <= maxLength) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            } 
            if (dollarSignArray[idx] == 1) {
                System.out.println('$');
            } else {
                System.out.print('$'); 
                for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                    System.out.print(' ');
                } System.out.print('$');
                System.out.println();
            } 
            if (dollarSignArray[idx] == maxLength) break;
            idx++;
        }

        int maxWaistDepth; 
        if (maxLength % 2 == 0) {
            maxWaistDepth = (idx+1)/2;
        } else maxWaistDepth = idx/2;
        if (maxWaistDepth == 0) maxWaistDepth = 1;
        
        int incrementAmt = idx + 1;

        int waistidx;
        if (idx == 0) waistidx = 0;
        else waistidx = idx - maxWaistDepth;
        
        if (maxLength > 2) idx--;
        while (idx >= waistidx) {
            if (idx == waistidx) {
                if (maxWaistDepth * 2 == incrementAmt) {
                    for (int space = 1; space < (maxLength - dollarSignArray[idx])/2; space++) {
                        System.out.print(' ');
                    } System.out.print('@');
                    if (dollarSignArray[idx] == 1) System.out.print('$');
                    else {
                        System.out.print('$');
                        for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                            System.out.print(' ');
                        } System.out.print('$');
                    } 
                    System.out.println('@');
                } else {
                    for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                        System.out.print(' ');
                    } 
                    if (dollarSignArray[idx] ==1) System.out.println('$');
                    else {
                        System.out.print('$');
                        for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                            System.out.print(' ');
                        } System.out.println('$');
                    }
                } break;
            } else {
                for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                    System.out.print(' ');
                } System.out.print('$');
                for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                    System.out.print(' ');
                } System.out.println('$');
            } idx--;
        }
        
        if (maxLength > 2) idx++;
        while (dollarSignArray[idx] <= maxLength) {
            if (maxLength <= 2) break;
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            } System.out.print('$');
            for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                System.out.print(' ');
            } System.out.println('$');
            if (dollarSignArray[idx] == maxLength) break;
            idx++;
        } 

        if (maxLength > 2) idx--;
        while (idx >= 0) {
            for (int space = 1; space <= (maxLength - dollarSignArray[idx])/2; space++) {
                System.out.print(' ');
            } 
            if (dollarSignArray[idx] == 1) System.out.println('$');
            else {
                System.out.print('$');
                for (int i = 0; i < dollarSignArray[idx]-2; i++) {
                    System.out.print(' ');
                } System.out.println('$');
            } idx--;
        }
    }

    public static int[] getDollarSignArray(int maxLength) {
        int dollarSign;
        if (maxLength % 2 == 0) {
            dollarSign = 2;
        } else dollarSign = 1;
        int[] dollarSignArray = new int[maxLength]; 
        int idx = 0;
        while (dollarSign <= maxLength) {
            dollarSignArray[idx] = dollarSign;
            if (dollarSign + 2 == maxLength) {
                dollarSign += 2;
            } else dollarSign += 4;
            idx++;
        }
        int i = 0;
        
        return dollarSignArray;
    }

    public static void main(String[] args) {
        System.out.print("Type the maximum length: ");
        Scanner scanner = new Scanner(System.in);
        int maxLength = scanner.nextInt();

        partA(maxLength);
        partB(maxLength);
    }
}
