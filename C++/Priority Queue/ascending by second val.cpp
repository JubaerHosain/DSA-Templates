struct cmp { 
    constexpr bool operator()(pii const& a, pii const& b) 
    const noexcept { 
        return a.second > b.second; 
    } 
};

//pqueue<pii, vector<pii>, cmp> q;
