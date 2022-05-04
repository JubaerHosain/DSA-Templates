import java.util.Scanner;


public class NewClass{
    static Scanner scan = new Scanner(System.in);
    
	static class Node{
		int data;
		int height;
		Node left, right;
		
		public Node(int data){
			this.data = data;
			height = 1;
			left = null;
			right = null;
		}
	}
	
	static int height(Node node){
		if(node == null){
			return 0;
		}
		
		return node.height;
	}
	
	static int getBalacne(Node node){
		if(node == null){
			return 0;
		}
		
		return height(node.left) - height(node.right);
	}
	
	static Node rightRotation(Node top){
		Node root = top .left;
		Node temp = root.right;
		
		//perform rotation
		root.right = top;
		top.left = temp;
		
		top.height = 1 + Math.max(height(top.left), height(top.right));
		root.height = 1 + Math.max(height(root.left), height(root.right));
		
		return root;
	}
	
	static Node leftRotation(Node top){
		Node root = top.right;
		Node temp = root.left;
		
		//perform rotation
		root.left = top;
		top.right = temp;
		
		top.height = 1 + Math.max(height(top.left), height(top.right));
		root.height = 1 + Math.max(height(root.left), height(root.right));
		
		return root;
	}
        
        static void inOrder(Node node) { 
            if (node != null) { 
                inOrder(node.left); 
                System.out.print(node.data + " "); 
                inOrder(node.right); 
            } 
        } 
	
	static Node insertNode(Node root, int data){
		if(root == null){
			return new Node(data);
		}
		
		if(data < root.data){
			root.left = insertNode(root.left, data);
		}
		else if(data > root.data){
			root.right = insertNode(root.right, data);
		}
		else{
			//Duplicate value not allowed
			return root;
		}
		
		root.height = 1 + Math.max(height(root.left), height(root.right));
		
		int balanceFactor = getBalacne(root);
		
		//LL case                       
		if(balanceFactor > 1 && data < root.left.data){
			return rightRotation(root);
		}
		
		//RR case
		if(balanceFactor < -1 && data > root.right.data){
			return leftRotation(root);
		}
		
		//LR case
		if(balanceFactor > 1 && data > root.left.data){
			root.left = leftRotation(root.left);
			return rightRotation(root);
		}
		
		//RL case
		if(balanceFactor < -1 && data < root.right.data){
			root.right = rightRotation(root.right);
			return leftRotation(root);
		}
		
		return root;
	}
        
        public static void main(String args[]){
            Node root = new Node(63);
            
            for(int i = 1; i < 8; i += 1){
                int input = scan.nextInt();
                root = insertNode(root, input);
            }
            
            inOrder(root);
        }
}
