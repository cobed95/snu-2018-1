public class LinkedIntList {
    private ListNode front;
    
    public LinkedIntList() {
        front = null;
    }

    public void add(int value) {
        if (front == null) {
            front = new ListNode(value);
        } else {
            ListNode node = front;
            while (node.next != null) {
                node = node.next;
            }
            node.next = new ListNode(value);
        }
    }

    public int get(int index) {
        if (front == null) {
            return -1;
        } else {
            ListNode node = front;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node.data;
        }
    }

    public int remove() {
        ListNode node = front;
        front = front.next;
        return node.data;
    }
}
