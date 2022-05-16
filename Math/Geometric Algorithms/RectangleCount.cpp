// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Find number of rectangles that can be formed from a given set of coordinates
 
// Function to find number of possible rectangles
int countRectangles(vector<pair<int, int> >& ob)
{
    // Creating TreeSet containing elements
    set<pair<int, int> > it;
 
    // Inserting the pairs in the set
    for (int i = 0; i < ob.size(); ++i) {
        it.insert(ob[i]);
    }
 
    int ans = 0;
    for (int i = 0; i < ob.size(); ++i)
    {
        // if assign j = i+1 then, return ans / 2;
        for (int j = 0; j < ob.size(); ++j)
        {
            if (ob[i].first != ob[j].first && ob[i].second != ob[j].second)
            {
                // Searching the pairs in the set (if they are diagonal corners)
                if (it.count({ob[i].first, ob[j].second}) && it.count({ob[j].first, ob[i].second}))
                {
                    // Increase the answer
                    ++ans;
                }
            }
        }
    }
 
    // Return the final answer
    return ans / 4;
}
 
// Driver Code
int main()
{
    int N = 7;
    vector<pair<int, int> > ob(N);
 
    // Inserting the pairs
    ob[0] = { 0, 0 };
    ob[1] = { 1, 0 };
    ob[2] = { 1, 1 };
    ob[3] = { 0, 1 };
    ob[4] = { 2, 0 };
    ob[5] = { 2, 1 };
    ob[6] = { 11, 23 };
 
    cout << countRectangles(ob) << endl;

    cin >> N;
 
    return 0;
}