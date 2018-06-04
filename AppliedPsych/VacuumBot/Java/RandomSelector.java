import java.util.*;

public class RandomSelector {
    private ArrayList<Integer> probDistribution;

    public RandomSelector(int[] objects, double[] probability) {
        if (objects.length != probability.length) {
            System.out.print(objects.length);
            System.out.print(",");
            System.out.println(probability.length);
        }
        this.probDistribution = new ArrayList<Integer>();
        int[] freq = probToFreq(probability);
        for (int i = 0; i < freq.length; i++) {
            addToProbDistribution(objects[i], freq[i]);
        }
    }

    private double getSum(double[] arr) {
        double sum = 0;
        for (int i = 0 ; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    private int[] probToFreq(double[] probability) {
        int[] freq = new int[probability.length];
        for (int i = 0; i < probability.length; i++) {
            if (probability[i] == 1.0) {
                freq[i] = 100;
            } else {
                freq[i] = (int) ((probability[i] * 100) % 100);
            }
        }
        return freq;
    }

    private void addToProbDistribution(int object, int freq) {
        for (int i = 0; i < freq; i++) {
            this.probDistribution.add(object);
        }
    }

    public int select() {
        Random rand = new Random();
        int idx = rand.nextInt(this.probDistribution.size());
        return probDistribution.get(idx);
    }
}
