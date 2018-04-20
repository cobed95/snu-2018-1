import java.io.*;
import java.util.*;

class Compression {
    public static class Dictionary {
        private int dictLength;
        private String[] words;
        private String[] definitions;
        private int maxWordLen;
        private int maxDefLen;
        
        public Dictionary(Scanner dict, int length) {
            dictLength = length;
            words = new String[dictLength];
            definitions = new String[dictLength]; 
            maxWordLen = 0;
            maxDefLen = 0;
            
            int idx = 0; 
            while (dict.hasNextLine()) {
                String line = dict.nextLine();
                String[] candidates = line.split(",");
                
                String newWord = candidates[0];
                if (newWord.length() > maxWordLen) {
                    maxWordLen = newWord.length();
                }
                
                String newDef = candidates[1];
                if (newDef.length() > maxDefLen) {
                    maxDefLen = newDef.length();    
                }
                
                words[idx] = newWord;
                definitions[idx] = newDef; 
                
                idx++;
            }
        }

        private boolean wordExists(String substr) {
            for (int i = 0; i < dictLength; i++) {
                if (substr.equals(words[i])) {
                    return true;
                }
            }
            return false;
        }

        private boolean defExists(String substr) {
            for (int i = 0; i < dictLength; i++) {
                if (substr.equals(definitions[i])) {
                    return true;
                }
            }
            return false;
        }

        private String findWord(String def) {
            for (int i = 0; i < dictLength; i++) {
                if (def.equals(definitions[i])) {
                    return words[i];
                }
            } 
            return null;
        }

        private String findDef(String word) {
            for (int i = 0; i < dictLength; i++) {
                if (word.equals(words[i])) {
                    return definitions[i];
                }
            }
            return null;
        }

        public String lookUp(char alg, char mode, String obj) {
            String result = "";
            if (alg == 'H' && mode == 'C') {
                for (int i = 0; i < obj.length(); i++) {
                    String substr = obj.substring(i, i+1);
                    if (wordExists(substr)) {
                        result += findDef(substr);
                    }
                }
                return result;
            } else if (alg == 'H' && mode == 'D') {
                int defLen = maxDefLen; 
                int i = 0;
                int j = i + defLen;
                while (i < obj.length() && defLen > 0) {
                    String substr = obj.substring(i, j); 
                    if (defExists(substr)) {
                        result += findWord(substr);
                        i = j;
                        defLen = maxDefLen;
                        j = i + defLen;
                    } else {
                        defLen -= 1;
                        j = i + defLen;
                    }
                }
                return result;
            } else if (alg == 'T' && mode == 'C') {
                int wordLen = maxWordLen;
                int i = 0;
                int j = i + wordLen;
                while (i < obj.length() && wordLen > 0) {
                    String substr = obj.substring(i, j);
                    if (wordExists(substr)) {
                        result += findDef(substr);
                        i = j;
                        wordLen = maxWordLen;
                        j = i + wordLen;
                    } else {
                        wordLen -= 1;
                        j = i + wordLen;
                    }
                }
                return result;
            } else if (alg == 'T' && mode == 'D') {
                int defLen = maxDefLen;
                int i = 0; 
                int j = i + defLen;
                while (i < obj.length() && defLen > 0) {
                    String substr = obj.substring(i, j);
                    if (defExists(substr)) {
                        result += findWord(substr);
                        i = j;
                        defLen = maxDefLen;
                        j = i + defLen;
                    } else {
                        defLen -= 1;
                        j = i + defLen;
                    }
                }
                return result;
            } else {
                return null;
            }
        }
    }

    public static int countLines(Scanner file) {
        int count = 0;
        while (file.hasNextLine()) {
            file.nextLine();
            count++;
        }
        return count;
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner dict = new Scanner(new File("dictionary.txt"));
        int length = countLines(dict);

        dict = new Scanner(new File("dictionary.txt"));
        Dictionary dictionary = new Dictionary(dict, length);
 
        Scanner input = new Scanner(new File("input.txt"));
        String outputTxt = "";
        if (input.hasNextLine()) {
            String line = input.nextLine();
            String[] data = line.split(",");
            char alg = data[0].charAt(0);
            char mode = data[1].charAt(0);
            String obj = data[2];
            outputTxt += dictionary.lookUp(alg, mode, obj);
        }
        while (input.hasNextLine()) {
            String line = input.nextLine();
            String[] data = line.split(",");
            char alg = data[0].charAt(0);
            char mode = data[1].charAt(0);
            String obj = data[2];
            outputTxt += "\n" + dictionary.lookUp(alg, mode, obj);
        }

        PrintStream output = new PrintStream(new File("output.txt"));
        output.println(outputTxt);
    }
}
