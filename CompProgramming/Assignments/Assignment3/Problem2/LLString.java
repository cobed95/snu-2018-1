public class LLString {
    public class LLStringNode {
        public char label;
        public LLStringNode next;
        
        public LLStringNode(char label) {
            this.label = label;
        }

        public LLStringNode(char label, LLStringNode next) {
            this.label = label;
            this.next = next;
        } 
    }

    private LLStringNode head;

	/* Constructor. */
	public LLString(String str) {
        this.head.label = str.charAt(0);
        int idx = 1; 
        LLStringNode node = head;
        while (idx < str.length()) {
            node.next = new LLStringNode(str.charAt(idx));
            node = node.next;
            idx++;
        }
	}

	public char charAt(int index) {
        LLStringNode node = head;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        return node.label;
	}

    public int compareTo(String str) {
        LLStringNode node = this.head;
        int i = 0; 
        while (node != null && i < str.length() && node.label == str.charAt(i)) {
            node = node.next;
            i++;
        }
        if (node == null && i == str.length()) {
            return 0;
        } else if (node != null && i == str.length()) {
            return this.length() - str.length();
        } else if (node == null && i != str.length()) {
            return str.length() - this.length();
        } else {
            if (node.label > str.charAt(i)) {
                return node.label - str.charAt(i);
            } else {
                return str.charAt(i) - node.label;
            }
        }
    }

    public int compareTo(LLString llstring) {
        LLStringNode myNode = this.head;
        LLStringNode otherNode = llstring.head;
        while (myNode != null && otherNode != null && myNode.label == otherNode.label) {
            myNode = myNode.next;
            otherNode = otherNode.next;
        }
        if (myNode == null && otherNode == null) {
            return 0;
        } else if (myNode != null && otherNode == null) {
            return this.length() - llstring.length();
        } else if (myNode == null && otherNode != null) {
            return llstring.length() - this.length();
        } else {
            if (myNode.label > otherNode.label) {
                return myNode.label - otherNode.label;
            } else {
                return otherNode.label - myNode.label;
            }
        }
    }

    public int compareToIgnoreCase(String str) {

    }

    public int compareToIgnoreCase(LLString llstring) {

    }

    public LLString concat(String str) {

    }
    
    public LLString concat(LLString llstring) {

    }

    public int indexOf(String str) {
        int nodeIdx = 0;
        LLStringNode node = this.head;
        while (nodeIdx < this.length() - str.length()) {
            if (node.label == str.charAt(0)) {
                int i = 1;
                node = node.next;
                while (i < str.length() && node.label == str.charAt(0)) {
                    i += 1;
                    node = node.next;
                }
                if (i == str.length()) {
                    return nodeIdx;
                } else {
                    nodeIdx = i;
                    node = node.next;
                }
            } else {
                nodeIdx += 1;
                node = node.next;
            }
        }
        return -1;
    }

    public int indexOf(String str, int fromIndex) {

    }

    public int length() {

    }

    LLString replace(char oldChar, char newChar) {

    }

    LLString substring(int beginIndex) {

    }

    LLString substring(int beginIndex, int endIndex) {

    }

    public String toString() {
        String newString = new String();
        LLStringNode node = this.head;
        while (node != null) {
            newString += node.label;
        }
        return newString;
    }

}
