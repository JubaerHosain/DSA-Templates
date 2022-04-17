class Trie {
   static class TrieNode {
       boolean endOfWord;
        Map<Character, TrieNode> children;
        public TrieNode() {
            children = new HashMap<>();
            endOfWord = false;
        }
    }
    
    /** Initialize your data structure here. */
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
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
  
  
  
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode curr = root;
        
        for(char ch: prefix.toCharArray()) {
            TrieNode node = curr.children.get(ch);
            if(node == null) {
                return false;
            }
            curr = node;
        }
        
        return true;
    }
}
