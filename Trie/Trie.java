import java.util.Map;
import java.util.HashMap;

public class Main {
    static class TrieNode {
	boolean endOfWord;
        Map<Character, TrieNode> children;
        public TrieNode() {
            children = new HashMap<>();
            endOfWord = false;
        }
    }
    
    //Insert by iteration
    public static void insert(TrieNode root, String word) {
        TrieNode curr = root;
        
        for(char ch: word.toCharArray()) {
            TrieNode node = curr.children.get(ch);
            if(node == null) {
                node = new TrieNode();
                curr.children.put(ch, node);
            }
            curr = node;
        }
        
        curr.endOfWord = true;
    }
    
    //Insert by recursion
    public static void insert(TrieNode root, String word, int index) {
        if(index == word.length()) {
            root.endOfWord = true;
            return;
        }
        
        char ch = word.charAt(index);
        TrieNode node = root.children.get(ch);
        if(node == null) {
            node = new TrieNode();
            root.children.put(ch, node);
        }
        
        insert(node, word, index+1);
    }
    
    //Search by iteration
    public static boolean search(TrieNode root, String word) {
        TrieNode curr = root;
        
        for(char ch: word.toCharArray()) {
            TrieNode node = curr.children.get(ch);
            if(node == null) {
                return false;
            }
            curr = node;
        }
        
        return curr.endOfWord;
    }
    
    //Search by recursion
    public static boolean search(TrieNode root, String word, int index) {
        if(index == word.length()) {
            return root.endOfWord;
        }
        
        char ch = word.charAt(index);
        TrieNode node = root.children.get(ch);
        if(node == null) {
            return false;
        }
        
        return search(node, word, index+1);
    }
	
	public static boolean delete(TrieNode root, String word, int index) {
	    if(index == word.length()) {
	        if(!root.endOfWord) {
	            return false;
	        }
	        root.endOfWord = false;
	        return root.children.size() == 0;
	    }
	    
	    char ch = word.charAt(index);
	    TrieNode node = root.children.get(ch);
	    if(node == null) {
	        return false;
	    }
	    
	    if(delete(node, word, index+1)) {
	        root.children.remove(ch);
	        return (root.children.size() == 0) && !root.endOfWord;
	    }
	    
	    return false;
	}
    
	public static void main(String[] args) {
	    System.out.println("Hello Jubaer Hosain");
	    
	    TrieNode root = new TrieNode();
	    String keys[] = {"Habibur", "Habib", "Sajidur", "Mahbubur", "Khatibun", "Ruhunnahar", "Kushnahar", "Nilima"};
	    for(String word: keys) {
	        insert(root, word);
	    }
	    
	    delete(root, "Habibur", 0);
	    String word = "Habibur";
	    System.out.println(word + " " + search(root, word));
	    word = "Habib";
	    System.out.println(word + " " + search(root, word));
	    word = "Habibur Rahman";
	    System.out.println(word + " " + search(root, word));
	    delete(root, "Nilima", 0);
	    word = "Nilima";
	    System.out.println(word + " " + search(root, word));
	    
	    //delete(root, "Nilima", 0);
	}
}
