public class Test {
    public static void main(String[] args) {
        LinkedIntList list = new LinkedIntList();
        System.out.println("Testing add() method...");
        for (int i = 0; i < 10; i++) {
            list.add(i);
        }
        
        System.out.println("Testing get() method...");
        for (int i = 0; i < 10; i++) {
            System.out.print(list.get(i));
        } 
        System.out.println();

        System.out.println("Testing remove() method...");
        for (int i = 0; i < 10; i++) {
            System.out.println("Removed: " + list.remove());
            System.out.println("New front: " + list.get(0));
        }
    }
}
