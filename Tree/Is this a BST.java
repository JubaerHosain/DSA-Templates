public class Solution { 
    static class Node { 
	int data; 
	Node left, right; 
        
  public Node(){
  }

	public Node(int item) { 
	    data = item; 
            left = right = null; 
	} 
    } 
    
    static boolean isBST(Node root) { 
	return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE); 
    } 


    static boolean isBST(Node node, int min, int max) 
    { 
	if (node == null) 
            return true; 

	if (node.data < min || node.data > max) 
            return false; 

        //Duplicate value allowed
	return (isBST(node.left, min, node.data) && isBST(node.right, node.data, max)); 
    } 

    public static void main(String args[]) 
    { 
        Node root = new Node(4);
	root.left = new Node(3); 
	root.left.left = new Node(2); 
	root.left.left.right = new Node(3); 
	root.right = new Node(5); 
        root.right.right = new Node(6);

	if (isBST(root)) 
            System.out.println("IS BST"); 
	else
            System.out.println("Not a BST"); 
    } 
} 
