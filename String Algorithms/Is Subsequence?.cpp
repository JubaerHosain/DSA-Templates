void solve() {
    string s, t;
    cin >> s >> t;

    int i = 0, j = 0;
    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) i++, j++;
        else j++;
    }

    if(i < s.size()) print("NO");
    else print("YES");
}
