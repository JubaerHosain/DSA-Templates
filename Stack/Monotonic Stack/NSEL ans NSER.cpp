// NSEL = Next Smaller Element in the Left
// NSER = Next Smaller Element in the Right
// implemented using monotonic stack
// stores indices in increasing order of value on the stack


// in case of Next Greater Element: Stores indices in descending order of value

//  for nexg greater use " <= "
// equal sign means strictly greater or smaller

// Next smaller element in the left
vector<int> NSEL(vector<int> &nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> nsel(n);
    for(int i = 0; i < n; i++) {
        while(!stk.empty() && nums[stk.top()] >= nums[i])
            stk.pop();
        if(stk.size() == 0)
            nsel[i] = -1;
        else 
            nsel[i] = stk.top();
        stk.push(i);
    }
    return nsel;
}

// Next smaller element in the right
vector<int> NSER(vector<int> &nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> nser(n);
    for(int i = n-1; i >= 0; i--) {
        while(!stk.empty() && nums[stk.top()] >= nums[i])
            stk.pop();
        if(stk.size() == 0)
            nser[i] = n;
        else 
            nser[i] = stk.top();
        stk.push(i);
    }
    return nser;
}
    
    


















