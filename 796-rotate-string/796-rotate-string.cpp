class Solution {
public:
    bool rotateString(string s, string t) {
        return s.size() == t.size() && (s + s).find(t) != string::npos;
    }
};