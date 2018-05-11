public class BinaryTree {
    private TreeNode root;
    private boolean lastLeft = false;
    
    public BinaryTree(TreeNode root) {
        this.root = root;
    }

    public BinaryTree(String label) {
        if (this.root == null) {
            this.root = new TreeNode();
        }
        this.root.label = label;
    } 

    public void insert(String label) {
        insert(this.root, label);
    }

    private void insert(TreeNode root, String label) {
        if (root == null) {
            root = new TreeNode();
            root.label = label;
        } else if (root.left == null) {
            root.left = new TreeNode();
            root.left.label = label;
        } else if (root.right == null) {
            root.right = new TreeNode();
            root.right.label = label;
        } else {
            if (!lastLeft) {
                insert(root.left, label);
            } else {
                insert(root.right, label);
            }
            lastLeft = !lastLeft;
        }
    }

    public void preorder() {
        preorder(this.root);
    }

    private void preorder(TreeNode root) {
        if (root != null) {
            System.out.println(root.label);
            preorder(root.left);
            preorder(root.right);
        }
    }
}
