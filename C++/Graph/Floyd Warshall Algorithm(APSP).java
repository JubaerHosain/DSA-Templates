import java.util.Scanner;

public class Graph {
    static Scanner scan = new Scanner(System.in);
    static int inf = Integer.MAX_VALUE;
    
    static int[][] FloydWarshall(int[][] dist){
        
        for(int  k = 0; k < dist.length; k++){ //Trying all inter mediate nodes
            for(int i = 0; i < dist.length; i++){ // Trying all possible stating nodes
                for(int j = 0; j < dist.length; j++){ // Trying all possible ending nodes
                    if(dist[i][k] != inf && dist[k][j] != inf && dist[i][k]+dist[k][j] < dist[i][j]){
                        dist[i][j]  = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        
        return dist;
    }
    
      
    static void printSolution(int dist[][]) 
    { 
        System.out.println("The following matrix shows the shortest "+ 
                         "distances between every pair of vertices"); 
        for (int i=0; i<dist.length; ++i) 
        { 
            for (int j=0; j<dist.length; ++j) 
            { 
                if (dist[i][j] == inf) 
                    System.out.print("inf "); 
                else
                    System.out.print(dist[i][j]+"   "); 
            } 
            System.out.println(); 
        } 
    } 
    
    public static void main(String args[]){
        //int nodes = scan.nextInt();
        //int vertices = scan.nextInt();
        
        int[][] dist = {{0,   5,  inf, 10}, 
                        {inf, 0,   3, inf}, 
                        {inf, inf, 0,   1}, 
                        {inf, inf, inf, 0} 
                        }; 
        //Initialize distances as infinity
        /*
        for(int i = 0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                if(i != j){
                    dist[i][j] = inf;
                }
            }
        }
        
        for(int i = 0; i < vertices; i++){
            int u = scan.nextInt();
            int v = scan.nextInt();
            int w = scan.nextInt();
            u--; v--;
            
            dist[u][v] = w;
        }
        */
        dist = FloydWarshall(dist);
        printSolution(dist);
    }
}
