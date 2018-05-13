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
    public LLString() {
        this.head = null;
    }

    public LLString(LLStringNode node) {
        this.head = node;
    }

	public LLString(String str) {
        this.head = new LLStringNode(str.charAt(0));
        int idx = 1; 
        LLStringNode node = head;
        while (idx < str.length()) {
            node.next = new LLStringNode(str.charAt(idx));
            node = node.next;
            idx++;
        }
	}
    
    public static LLString copyOf(LLString llstring) {
        LLString newLLString = new LLString();
        newLLString.head = llstring.head;
        return newLLString;
    }

    public void add(LLStringNode newNode) {
        if (this.head == null) {
            this.head = newNode;
        } else {
            LLStringNode node = this.head;
            while (node.next != null) {
                node = node.next;
            }
            node.next = newNode;
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
            return this.length() - str.length();
        } else {
            return node.label - str.charAt(i);
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
            return this.length() - llstring.length();
        } else {
            return myNode.label - otherNode.label;
        }
    } 

    public LLString toLowercase() {
        LLString newLLString = LLString.copyOf(this);
        LLStringNode node = newLLString.head;
        while (node != null) {
            if (node.label >= 65 && node.label <= 90) {
                node.label = (char) (node.label+32);
            }
        }
        return newLLString;
    }

    public int compareToIgnoreCase(String str) {
        LLString newLLString = this.toLowercase();
        String newString = new String();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= 65 && str.charAt(i) <= 90) {
                newString += (char) (str.charAt(i)+32);
            } else {
                newString += str.charAt(i);
            }
        }
        return newLLString.compareTo(newString);
    }

    public int compareToIgnoreCase(LLString llstring) {
        LLString myNewLLString = this.toLowercase();
        LLString otherNewLLString = llstring.toLowercase();
        return myNewLLString.compareTo(otherNewLLString);
    }

    public LLString concat(String str) {
        LLString newOtherLLString = new LLString(str); 
        return this.concat(newOtherLLString);
    }
    
    public LLString concat(LLString llstring) {
        LLString newLLString = LLString.copyOf(this);
        if (newLLString.head == null) {
            newLLString.head = llstring.head;
        } else {
            LLStringNode node = newLLString.head;
            while (node.next != null) {
                node = node.next;
            }
            node.next = llstring.head;
        }
        return newLLString;
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
        return fromIndex + this.substring(fromIndex).indexOf(str);
    }

    public int length() {
        int count = 0;
        LLStringNode node = this.head;
        while (node != null) {
            node = node.next;
            count++;
        }
        return count;
    }

    public LLString replace(char oldChar, char newChar) {
        LLString newLLString = LLString.copyOf(this);
        LLStringNode node = newLLString.head;
        while (node != null) {
            if (node.label == oldChar) {
                node.label = newChar;
            }
            node = node.next;
        }
        return newLLString;
    }

    public LLString substring(int beginIndex) {
        LLStringNode node = this.head;
        for (int i = 0; i < beginIndex; i++) {
            node = node.next;
        }
        LLString newLLString = new LLString(node);
        return newLLString;
    }

    public LLString substring(int beginIndex, int endIndex) {
        LLString newLLString = this.substring(beginIndex);
        LLStringNode node = newLLString.head;
        for (int i = 0; i < endIndex - beginIndex - 1; i++) {
            node = node.next;
        }
        node.next = null;
        return newLLString;
    }

    public String toString() {
        String newString = new String();
        LLStringNode node = this.head;
        while (node != null) {
            newString += node.label;
            node = node.next;
        }
        return newString;
    }

}
