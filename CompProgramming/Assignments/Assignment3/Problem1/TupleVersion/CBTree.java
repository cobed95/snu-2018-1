public class CBTree {
    public CBNode root;

    public CBTree(String st, String con) {
        Tuple<CBNode, String, String> tuple = new Tuple<>(root, st, con);
        this.root = build(tuple).first(); 
    }

    public Tuple<CBNode, String, String> build(Tuple<CBNode, String, String> tuple) {
        CBNode root = tuple.first();
        String st = tuple.second();
        String con = tuple.third();
        
        if (root == null) {
            root = new CBNode();
        }
        if (st.charAt(0) == '0') {
            root.label = st.charAt(0);
            st = st.substring(1);
            root.character = con.charAt(0);
            con = con.substring(1);

            Tuple<CBNode, String, String> leftTuple = new Tuple<>(root.left, st, con);
            root.left = build(leftTuple).first();
            st = build(leftTuple).second();
            con = build(leftTuple).third();
            Tuple<CBNode, String, String> rightTuple = new Tuple<>(root.right, st, con);
            root.right = build(rightTuple).first();
            st = build(rightTuple).second();
            con = build(leftTuple).third();
        } else if (st.charAt(1) == '1') {
            root.label = st.charAt(0);
            st = st.substring(1);
        }
        tuple.setFirst(root);
        tuple.setSecond(st);
        tuple.setThird(con);

        return tuple;
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
