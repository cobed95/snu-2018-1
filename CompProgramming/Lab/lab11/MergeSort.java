import java.util.*;

public class MergeSort {
    public static void merge(int[] list, int p, int q, int r) {
        int[] left = new int[q-p+1];
        int[] right = new int[r-q];
        for (int i = p; i <= q; i++) {
            left[i-p] = list[i];
        }
        for (int j = q+1; j <= r; j++) {
            right[j-q-1] = list[j];
        }

        int i = 0;
        int j = 0;
        for (int k = p; k <= r; k++) {
            if (i < left.length && j < right.length && left[i] <= right[j]) {
                list[k] = left[i];
                i++;
            } else if (i < left.length && j < right.length && left[i] > right[j]) {
                list[k] = right[j];
                j++;
            } else if (i < left.length && j >= right.length) {
                list[k] = left[i];
                i++;
            } else if (i >= left.length && j < right.length) {
                list[k] = right[j];
                j++;
            }
        }
    }

    public static void mergesort(int[] list, int p, int r) {
        if (p < r) {
            int q = (p+r)/2;
            mergesort(list, p, q);
            mergesort(list, q+1, r);
            merge(list, p, q, r);
        }
    }

    public static void main(String[] args) {
        int[] list = {6, 1, 4, 3, 5, 7, 9, 2, 8, 0};
        mergesort(list, 0, list.length-1);
        System.out.println(Arrays.toString(list));
    }
}
