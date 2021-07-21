#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//this should write after using namespace std
//typedef tree<int, null_type, less<int>,
//rb_tree_tag, tree_order_statistics_node_update> ordered_set;



//for set use less<type> comparator
//for multiset use less_equal<type> instead of less
typedef tree<int, null_type, less<int>,
rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//less_equal for ordered_multiset
 
/*****User defined function*****/
const int N = 3e4+5;
vector<int> a(N);

void solve() {
    ordered_set set;
    set.insert(4);
    set.insert(1);
    set.insert(3);
    set.insert(1);

    //find by order returned an iterator
    //for erasing should used iterator inside erase function
    //for set value also work, but multiset erase by value not work
    //val = *it
    auto it = set.find_by_order(1);
    set.erase(it);
    for(int i: set) print(i);
    cout << "....." << endl;
    it = set.find_by_order(0);
    set.erase(it);
    for(int i: set) print(i);
    ///print(set.order_of_key(4));

} 
