import java.util.*;

public class Test {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> test = new ArrayList<ArrayList<Integer>>();
        test.add(new ArrayList<Integer>());
        test.get(0).add(0);
        test.get(0).get(0) = test.get(0).get(0).intValue() + 1;
        System.out.println(test.get(0).get(0));
    }
}
