public class CBTree { 
    public class TreeBuilder {
        public String st;
        public String con;
        public int stIdx;
        public int conIdx;

        public TreeBuilder(String st, String con) {
            this.st = st;
            this.con = con;
            stIdx = 0;
            conIdx = 0;
        }
        
        public CBNode build(CBNode root) {
            if (root == null) {
                root = new CBNode();
            }
            if (st.charAt(stIdx) == '0') {
                root.label = st.charAt(stIdx);
                stIdx++;
                root.character = con.charAt(conIdx);
                conIdx++;

                root.left = build(root.left);
                root.right = build(root.right);
            } else if (st.charAt(stIdx) == '1') {
                root.label = st.charAt(stIdx);
                stIdx++;
            }
            return root;
        }
    }

	public CBNode root;

    public CBTree(String st, String con) { 
        TreeBuilder treebuilder = new TreeBuilder(st, con);
        root = treebuilder.build(root);
    } 
    
    public CBNode getRoot() {
		return root;
	}
    
    public String postOrderTraversal() {
        return postOrderTraversal(root, "");
    }

    private String postOrderTraversal(CBNode root, String prev) {
        if (root != null && root.label != '1') {
            prev = postOrderTraversal(root.left, prev);
            prev = postOrderTraversal(root.right, prev);       
            prev += root.character;
        }
        return prev; 
    }

    public String inOrderTraversal() {
        return inOrderTraversal(root, "");
    }

    private String inOrderTraversal(CBNode root, String prev) {
        if (root != null && root.label != '1') {
            prev = inOrderTraversal(root.left, prev);
            prev += root.character;
            prev = inOrderTraversal(root.right, prev);
        }
        return prev;
    }

    public String postOrderStructure() {
        return postOrderStructure(root, "");
    } 

    private String postOrderStructure(CBNode root, String prev) {
        if (root != null) {
            prev = postOrderStructure(root.left, prev);
            prev = postOrderStructure(root.right, prev);
            prev += root.label;
        }
        return prev;
    }

    public String inOrderStructure() {
        return inOrderStructure(root, "");
    }

    private String inOrderStructure(CBNode root, String prev) {
        if (root != null) {
            prev = inOrderStructure(root.left, prev);
            prev += root.label;
            prev = inOrderStructure(root.right, prev);
        }
        return prev;
    }
}
