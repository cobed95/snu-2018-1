public class StringSorterTest {
    public static class Tester {
        String[] arr;

        public Tester(String[] arr) {
            this.arr = arr;
        } 
       
        public void printArray(String[] arr) {
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + "\t");
            } 
            System.out.println();
        }

        public void testSelectionSort(String[] arr) {
            System.out.println("-------------------------------");
            System.out.println("Testing for selectionSort...");
            System.out.println();
            System.out.println("Printing original array...");
            printArray(arr);
            System.out.println();
            
            StringSorter.selectionSort(arr);
            System.out.println("Printing sorted array...");
            printArray(arr);
            System.out.println();

            System.out.println("Testing for selectionSort finished.");
            System.out.println("-------------------------------");
            System.out.println();
        }

        public void testInsertionSort(String[] arr) {
            System.out.println("-------------------------------");
            System.out.println("Testing for insertionSort...");
            System.out.println();
            System.out.println("Printing original array...");
            printArray(arr);
            System.out.println();
            
            StringSorter.insertionSort(arr);
            System.out.println("Printing sorted array...");
            printArray(arr);
            System.out.println();

            System.out.println("Testing for insertionSort finished.");            
            System.out.println("-------------------------------");
            System.out.println();
        }

        public void testBubbleSort(String[] arr) {
            System.out.println("-------------------------------");
            System.out.println("Testing for bubbleSort...");
            System.out.println();
            System.out.println("Printing original array...");
            printArray(arr);
            System.out.println();
            
            StringSorter.bubbleSort(arr);
            System.out.println("Printing sorted array...");
            printArray(arr);
            System.out.println();

            System.out.println("Testing for bubbleSort finished.");
            System.out.println("-------------------------------");
            System.out.println();
        }

        public void testMergeSort(String[] arr) {
            System.out.println("-------------------------------");
            System.out.println("Testing for mergeSort...");
            System.out.println();
            System.out.println("Printing original array...");
            printArray(arr);
            System.out.println();
            
            StringSorter.mergeSort(arr);
            System.out.println("Printing sorted array...");
            printArray(arr);
            System.out.println();

            System.out.println("Testing for mergeSort finished.");
            System.out.println("-------------------------------");
            System.out.println();
        }
        
        private String[] copy(String[] arr) {
            String[] newArr = new String[arr.length];
            for (int i = 0; i < arr.length; i++) {
                newArr[i] = arr[i];
            }
            return newArr;
        }    
 
        public void test() {
            String[] arrS = copy(arr);
            String[] arrI = copy(arr);
            String[] arrB = copy(arr);
            String[] arrM = copy(arr);

            testSelectionSort(arrS);
            testInsertionSort(arrI);
            testBubbleSort(arrB);
            testMergeSort(arrM);
        }
    }

    public static void main(String[] args) {
        String[] arr = {"hello", "garbage", "world", "java"}; 
        Tester tester = new Tester(arr);
        tester.test();
    }
}
