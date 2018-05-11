/*
 *              F
 *             / \
 *            B   G
 *           /\   /\
 *          A D   H I
 *         /\
 *        C  E
 * Correct: FBACEDGHI
 */

public class BinaryTreeTest {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree("F"); 
        tree.insert("B");
        tree.insert("G");
        tree.insert("A");
        tree.insert("D");
        tree.insert("H");
        tree.insert("I");
        tree.insert("C");
        tree.insert("E");
        tree.preorder();
    }
}
