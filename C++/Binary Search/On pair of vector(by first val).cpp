struct compare { 
    bool operator()(const pii& value, const int& key) { 
        return (value.first < key); 
    } 
    bool operator()(const int& key, const pii& value) { 
        return (key < value.first); 
    } 
}; 
