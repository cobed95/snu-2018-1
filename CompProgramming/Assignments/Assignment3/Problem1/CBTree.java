public class CBTree {
	public CBNode root;

    public CBTree(String st, String con) { 
        this.root = preorderAdd(this.root, st, con);
    }

    private CBNode preorderAdd(CBNode root, String st, String con) {
        if (st.length() > 0) {
            if (root == null) {
                root = new CBNode();
            }
            if (st.charAt(0) == '0') {
                root.label = st.charAt(0);
                root.character = con.charAt(0);
                
                root.left = preorderAdd(root.left, st, con)
            }
        }
    }
    
    public CBNode getRoot() {
		return root;
	}

    public Integer getLength() {
        return getLength(root, 0);
    }

    private Integer getLength(CBNode root, Integer count) {
        if (root != null) {
            count++;
            getLength(root.left, count);
            getLength(root.right, count);
        }
        return count;
    }
    
    public String postOrderTraversal() {
        return postOrderTraversal(root, "");
    }

    private String postOrderTraversal(CBNode root, String prev) {
        if (root != null && root.label != '1') {
            postOrderTraversal(root.left, prev);
            postOrderTraversal(root.right, prev);       
            prev += root.character;
        }
        return prev; 
    }

    public String inOrderTraversal() {
        return postOrderTraversal(root, "");
    }

    private String inOrderTraversal(CBNode root, String prev) {
        if (root != null && root.label != '1') {
            inOrderTraversal(root.left, prev);
            prev += root.character;
            inOrderTraversal(root.right, prev);
        }
        return prev;
    }

    public String postOrderStructure() {
        return postOrderStructure(root, "");
    } 

    private String postOrderStructure(CBNode root, String prev) {
        if (root != null) {
            postOrderStructure(root.left, prev);
            postOrderStructure(root.right, prev);
            prev += root.label;
        }
        return prev;
    }

    public String inOrderStructure() {
        return inOrderStructure(root, "");
    }

    private String inOrderStructure(CBNode root, String prev) {
        if (root != null) {
            inOrderStructure(root.left, prev);
            prev += root.label;
            inOrderStructure(root.right, prev);
        }
        return prev;
    }
}
