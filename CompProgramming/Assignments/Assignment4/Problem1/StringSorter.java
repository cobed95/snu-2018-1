public class StringSorter {
    public static class StringScale {
        private static int compareTo(String one, String other) {
            int idx = 0;
            while (idx < one.length() && idx < other.length() && one.charAt(idx) == other.charAt(idx)) {
                idx++;
            }
            if (idx < one.length() && idx < other.length()) {
                return one.charAt(idx) - other.charAt(idx);
            } else {
                return one.length() - other.length();
            }
        }

        public static boolean isEqualTo(String one, String other) {
            return compareTo(one, other) == 0;
        }

        public static boolean isGreaterThan(String one, String other) {
            return compareTo(one, other) > 0;
        }

        public static boolean isGreaterThanOrEqualTo(String one, String other) {
            return compareTo(one, other) >= 0;
        }

        public static boolean isLessThan(String one, String other) {
            return compareTo(one, other) < 0;
        }

        public static boolean isLessThanOrEqualTo(String one, String other) {
            return compareTo(one, other) <= 0;
        }
    }
    
    private static void swap(String[] arr, int p, int q) {
        String temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
    }

    public static void selectionSort(String[] arr) {
        for (int i = 0; i < arr.length-1; i++) {
            int min = i;
            for (int j = i+1; j < arr.length; j++) {
                if (StringScale.isLessThan(arr[j], arr[i])) {
                    min = j;
                }
            }
            swap(arr, i, min);
        }
    }

    public static void insertionSort(String[] arr) {
        for (int i = 1; i < arr.length; i++) {
            String key = arr[i];
            int j = i-1;
            while (j >= 0 && StringScale.isLessThan(key, arr[j])) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    public static void bubbleSort(String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length-1; j++) {
                if (StringScale.isGreaterThan(arr[j], arr[j+1])) {
                    swap(arr, j, j+1);
                }
            }
        }
    }

    private static void merge(String[] arr, int p, int q, int r) {
        String[] left = new String[q-p+1];
        String[] right = new String[r-q];
        for (int i = p; i <= q; i++) {
            left[i-p] = arr[i];
        }
        for (int j = q+1; j <= r; j++) {
            right[j-q-1] = arr[j];
        }

        int i = 0; 
        int j = 0;
        for (int k = p; k <= r; k++) {
            if (i < left.length && j < right.length && StringScale.isLessThan(left[i], right[j])) {
                arr[k] = left[i];
                i++;
            } else if (i < left.length && j < right.length && StringScale.isGreaterThanOrEqualTo(left[i], right[j])) {
                arr[k] = right[j];
                j++;
            } else if (i >= left.length && j < right.length) {
                arr[k] = right[j];
                j++;
            } else if (i < left.length && j >= right.length) {
                arr[k] = left[i];
                i++;
            }
        }
    }

    private static void mergeSortAux(String[] arr, int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            mergeSortAux(arr, p, q);
            mergeSortAux(arr, q+1, r);
            merge(arr, p, q, r);
        }
    }

    public static void mergeSort(String[] arr) {
        mergeSortAux(arr, 0, arr.length-1);
    }
}
