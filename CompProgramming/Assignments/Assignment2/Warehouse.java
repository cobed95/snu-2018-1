import java.util.*;
import java.io.*;

class Warehouse {
    public static class Parts {
        public int partId;
        public String partType;
        public String name;
        public int price;
        public int stockQuantity;
        public int txQuantity;
        public String txType;

        public static void exchangeData(Parts input, Parts stock) {
            input.partId = stock.partId;
            if (input.txType.equals("I")) {
                stock.changePrice(input.price);
                stock.stockQuantity += input.txQuantity;
            } else if (input.txType.equals("S")) {
                input.price = stock.price;
                stock.stockQuantity -= input.txQuantity;
            } else if (input.txType.equals("E")) {
                input.price = stock.price;
                if (input.txQuantity > stock.stockQuantity) {
                    System.out.println("The part partially exchanged.");
                }
            }
        }
        
        public Parts(int dataType, String line) {
            if (dataType == 2) {
                partId = 0;
                partType = "";
                name = "";
                price = 0;
                stockQuantity = 0;
                txQuantity = 0;
                txType = "";
            }
            String[] candidates = line.split(",");
            if (dataType == 0) {
                txType = candidates[0];
                if (txType.equals("I")) {
                    partType = candidates[1];
                    name = candidates[2];
                    price = Integer.parseInt(candidates[3]);
                    txQuantity = Integer.parseInt(candidates[4]);
                } else {
                    partType = candidates[1];
                    name = candidates[2];
                    txQuantity = Integer.parseInt(candidates[3]);
                }
            } else if (dataType == 1) {
                partId = Integer.parseInt(candidates[0]);
                partType = candidates[1];
                name = candidates[2];
                price = Integer.parseInt(candidates[3]);
                stockQuantity = Integer.parseInt(candidates[4]);
            }
        }

        public void changePrice(int newPrice) {
            if (newPrice > price) {
                System.out.println("The part became expensive.");
            } else if (newPrice < price) {
                System.out.println("The part became cheap.");
            }
            price = newPrice;
        }

        public boolean equals(Object o) {
            if (o instanceof Parts) {
                Parts newPart = (Parts) o;
                return name.equals(newPart.name) && partType.equals(newPart.partType);
            } else {
                return false;
            }
        }

        public int hashCode() {
            return Objects.hash(name, partType);
        }

        public boolean isInArray(Parts[] partsArr) {
            int idx = 0; 
            while (idx < partsArr.length && partsArr[idx] != null) {
                if (this.equals(partsArr[idx])) {
                    return true;
                }
                idx++;
            }
            return false;
        }

        public int getIdx(Parts[] partsArr) {
            int idx = 0; 
            while (idx < partsArr.length) {
                if (this.equals(partsArr[idx])) {
                    return idx;
                }
                idx++;
            }
            return -1;
        }
        
        public String toString(int outputType) {
            if (outputType == 0) {
                return Integer.toString(partId) + "," + partType + "," + name + "," + Integer.toString(price) + "," + Integer.toString(stockQuantity); 
            } else if (outputType == 1) {
                return "," + txType + "," + Integer.toString(partId) + "," + Integer.toString(price) + "," + Integer.toString(txQuantity) + "," + Integer.toString(price * txQuantity);
            } else {
                return null;
            }
        }
    }

    public static Parts[][] processOrder(Parts[] inputArr, Parts[] stockArr) {
        Parts[] validTx = new Parts[inputArr.length];
        int validTxIdx = 0;
        
        Parts[] newStockItems = new Parts[inputArr.length];
        int newStockIdx = 0;
        int newPartId = stockArr.length+1;
        
        int idx = 0; 
        while (idx < inputArr.length) {
            if (inputArr[idx].txType.equals("I")) {
                Parts stockData = new Parts(2, "");
                if (inputArr[idx].isInArray(stockArr)) {
                    stockData = stockArr[inputArr[idx].getIdx(stockArr)];
                    Parts.exchangeData(inputArr[idx], stockData);    
                    validTx[validTxIdx] = inputArr[idx];
                    validTxIdx++;
                } else if (inputArr[idx].isInArray(newStockItems)) {
                    stockData = stockArr[inputArr[idx].getIdx(newStockItems)];
                    Parts.exchangeData(inputArr[idx], stockData);    
                    validTx[validTxIdx] = inputArr[idx];
                    validTxIdx++;
                } else {
                    inputArr[idx].partId = newPartId; 
                    newPartId++;
                    inputArr[idx].stockQuantity = inputArr[idx].txQuantity;
                    newStockItems[newStockIdx] = inputArr[idx];
                    newStockIdx++;
                    validTx[validTxIdx] = inputArr[idx];
                    validTxIdx++;
                }
            } else {
                Parts stockData = new Parts(2, "");
                if (!inputArr[idx].isInArray(stockArr) && !inputArr[idx].isInArray(newStockItems)) {
                    break;
                } else if (inputArr[idx].isInArray(stockArr)) {
                    stockData = stockArr[inputArr[idx].getIdx(stockArr)];     
                } else if (inputArr[idx].isInArray(newStockItems)) {
                    stockData = newStockItems[inputArr[idx].getIdx(newStockItems)];
                }
                if (inputArr[idx].txType.equals("S") && inputArr[idx].txQuantity > stockData.stockQuantity) break;
                Parts.exchangeData(inputArr[idx], stockData);
                validTx[validTxIdx] = inputArr[idx];
                validTxIdx++;
            }
            idx++; 
        }

        Parts[] resizedValidTx = new Parts[validTxIdx];
        for (int i = 0; i < resizedValidTx.length; i++) {
            resizedValidTx[i] = validTx[i];
        }
        
        Parts[] updatedStock = new Parts[stockArr.length + newStockIdx];
        for (int i = 0; i < updatedStock.length; i++) {
            if (i < stockArr.length) {
                updatedStock[i] = stockArr[i];
            } else {
                updatedStock[i] = newStockItems[i-stockArr.length];
            }
        }

        Parts[][] result = new Parts[2][]; 
        result[0] = updatedStock;
        result[1] = resizedValidTx;
        return result;
    }

    public static String getStockOutput(Parts[] stockArr) {
        String stockOutput = "";
        stockOutput += stockArr[0].toString(0);
        int idx = 1;
        while (idx < stockArr.length) {
            String newLine = stockArr[idx].toString(0);
            stockOutput += "\n";
            stockOutput += newLine;
            idx++;
        }

        return stockOutput;
    }

    public static String getTxOutput(Parts[] validTx, Scanner tx) throws FileNotFoundException {
        String txOutput = "";
        int txId = 1;
        while (tx.hasNextLine()) {
                txOutput += tx.nextLine();
                txOutput += "\n";
                txId++;
        }
        
        int idx = 0;
        while (idx < validTx.length-1) {
            txOutput += Integer.toString(txId) + validTx[idx].toString(1);
            txOutput += "\n";
            txId++;
            idx++;
        }
        txOutput += Integer.toString(txId) + validTx[validTx.length-1].toString(1);

        return txOutput;
    }

    public static int countLines(Scanner file) {
        int count = 0;
        while (file.hasNextLine()) {
            file.nextLine();
            count++;
        }
        return count;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("input.txt"));
        Scanner stock = new Scanner(new File("stock.txt"));
        Scanner tx = new Scanner(new File("tx.txt"));

        int inputLineCount = countLines(input);
        int stockLineCount = countLines(stock);

        input = new Scanner(new File("input.txt"));
        stock = new Scanner(new File("stock.txt"));
        
        Parts[] inputArr = new Parts[inputLineCount];
        int idx = 0;
        while (input.hasNextLine()) {
            String newInput = input.nextLine();
            Parts newPart = new Parts(0, newInput);
            inputArr[idx] = newPart;
            idx++;
        }
        
        Parts[] stockArr = new Parts[stockLineCount];
        idx = 0;
        while (stock.hasNextLine()) {
            String newStock = stock.nextLine();
            Parts newPart = new Parts(1, newStock); 
            stockArr[idx] = newPart;
            idx++;
        }

        Parts[][] result = processOrder(inputArr, stockArr);
        String stockOutput = getStockOutput(result[0]);
        String txOutput = getTxOutput(result[1], tx);

        PrintStream stockPrint = new PrintStream(new File("stock.txt"));
        stockPrint.println(stockOutput);
        PrintStream txPrint = new PrintStream(new File("tx.txt"));
        txPrint.println(txOutput);
    }
}
