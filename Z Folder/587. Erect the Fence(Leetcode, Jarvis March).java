class Solution {
    class Point {
        int x, y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public boolean equals(Point point) {
            return point.x == x && point.y == y;
        }
    }
    
    int orientation(Point a, Point b, Point c) {
        //val = 0, collinear
        //val > 0, clockwise
        //val < 0, anti-clockwise
        return (b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x);
    }
    
    int distance(Point a, Point b) {
        //distance between a and b
        return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    }
    
    ArrayList<Point> outerTrees(ArrayList<Point> points) {
        if(points.size() < 3)
            return new ArrayList<Point>();
        
        Set<Point> result = new HashSet<>();
        Point start, current, nextTarget;
        
        start = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            if(start.x > points.get(i).x) 
                start = points.get(i);
        }
        
        current = start;
        while(true) {
            nextTarget = points.get(0);
            result.add(current);
            
            for(int i = 1; i < points.size(); i++) {
                if(current.equals(points.get(i)))
                    continue;
                
                int val = orientation(current, points.get(i), nextTarget);
                if(current.equals(nextTarget) || val > 0 ||              //why checking current == nextTarget
                  (val == 0 && distance(current, points.get(i)) > distance(current, nextTarget))) {
                    nextTarget = points.get(i);
                }
            }
            
            //Handling colinear points
            for(int i = 0; i < points.size(); i++) {
                if(current.equals(points.get(i)))
                    continue;
                int val = orientation(current, points.get(i), nextTarget);
                if(val == 0) 
                    result.add(points.get(i));
            }
            
            if(nextTarget.equals(start))
                break;
            
            current = nextTarget;
        }
        
        return new ArrayList<>(result);
    }

    
    public int[][] outerTrees(int[][] trees) {
        ArrayList<Point> points = new ArrayList<Point>();
        
        for(int i = 0; i < trees.length; i++) {
            points.add(new Point(trees[i][0], trees[i][1]));
        }
        
        ArrayList<Point> result = outerTrees(points);
        
        if(result.size() == 0)
            return trees;
        
        trees = new int[result.size()][2];
        for(int i = 0; i < result.size(); i++) {
            trees[i][0] = result.get(i).x;
            trees[i][1] = result.get(i).y;
        }
        
        return trees;
    }
}


//==============================================================================================================================================================
class Solution {
    class Point {
        int x, y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public boolean equals(Point point) {
            return point.x == x && point.y == y;
        }
    }
    
    int orientation(Point a, Point b, Point c) {
        //val = 0, collinear
        //val > 0, clockwise
        //val < 0, anti-clockwise
        return (b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x);
    }
    
    int distance(Point a, Point b) {
        //distance between a and b
        return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    }
    
    ArrayList<Point> outerTrees(ArrayList<Point> points) {
        if(points.size() < 3)
            return new ArrayList<Point>();
        
        //for handling duplicate used set
        Set<Point> result = new HashSet<>();
        ArrayList<Point> colinear = new ArrayList<>();
        Point start, current, nextTarget;
        
        start = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            if(start.x > points.get(i).x) 
                start = points.get(i);
        }
        
        current = start;
        while(true) {
            nextTarget = points.get(0);
            result.add(current);
            
            for(int i = 1; i < points.size(); i++) {
                if(current.equals(points.get(i)))
                    continue;
                
                int val = orientation(current, points.get(i), nextTarget);
                if(val > 0) {
                    nextTarget = points.get(i);
                    colinear = new ArrayList<>();
                }
                else if(val == 0 && distance(current, points.get(i)) > distance(current, nextTarget)) {
                    colinear.add(nextTarget);
                    nextTarget = points.get(i);
                }
                else if(val == 0) {
                    colinear.add(points.get(i));
                }
            }
            
            for(int i = 0; i < colinear.size(); i++) {
                result.add(colinear.get(i));
            }
            
            colinear = new ArrayList<>();
            
            if(nextTarget.equals(start))
                break;
            
            current = nextTarget;
        }
        
        return new ArrayList<>(result);
    }

    
    public int[][] outerTrees(int[][] trees) {
        ArrayList<Point> points = new ArrayList<Point>();
        
        for(int i = 0; i < trees.length; i++) {
            points.add(new Point(trees[i][0], trees[i][1]));
        }
        
        ArrayList<Point> result = outerTrees(points);
        
        if(result.size() == 0)
            return trees;
        
        trees = new int[result.size()][2];
        for(int i = 0; i < result.size(); i++) {
            trees[i][0] = result.get(i).x;
            trees[i][1] = result.get(i).y;
        }
        
        return trees;
    }
}

