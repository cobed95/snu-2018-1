import java.util.*;

public class Tree {
    class TreeNode {
        public int label;
        public TreeNode left;
        public TreeNode right;
    }

    private TreeNode root;

    public TreeNode getRoot() {
        return this.root;
    }

    public Tree(TreeNode root) {
        this.root = root;
    }
}
