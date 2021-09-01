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
    
    public int[][] outerTrees(int[][] trees) {
        //convert array to list
        List<Point> points = new ArrayList<>();
        for(int i = 0; i < trees.length; i++) 
            points.add(new Point(trees[i][0], trees[i][1]));
        
        //find leftmost and then bottom most point
        Point first = points.get(0);
        for(int i = 1; i < points.size(); i++) {
            Point temp = points.get(i);
            if(temp.x < first.x || (temp.x == first.x && temp.y < first.y)) 
                first = temp;
        }
        
        
        List<Point> newPoints = new ArrayList<>();
        for(int i = 0; i < points.size(); i++) {
            if(!first.equals(points.get(i)))
                newPoints.add(points.get(i));
        }
        
        //start need to be final
        final Point start = new Point(first.x, first.y);
        Collections.sort(newPoints, new Comparator<Point>() {
            @Override
            public int compare(Point point1, Point point2) {
                if(orientation(start, point1, point2) < 0)
                    return -1;
                else if(orientation(start, point1, point2) > 0)
                    return 1;
                else 
                    return (distance(start, point1) <= distance(start, point2)) ? -1 : 1;
            }
        });
        
        Stack<Point> stack = new Stack<>();
        stack.push(start);
        stack.push(newPoints.get(0));
        for(int i = 1; i < newPoints.size(); i++) {
            Point temp = stack.pop();
            
            while(stack.size() > 0 && orientation(newPoints.get(i), temp, stack.peek()) < 0) 
                temp = stack.pop();
            
            stack.push(temp);
            stack.push(newPoints.get(i));
        }
        
        int size = stack.size();
        trees = new int[size][2];
        for(int i = 0; i < size; i++) {
            Point point = stack.pop();
            trees[i][0] = point.x;
            trees[i][1] = point.y;
        }
        
        return trees;
    }
}

