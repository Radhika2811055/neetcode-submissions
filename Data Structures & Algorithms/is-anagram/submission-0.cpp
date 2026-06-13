class Solution {
public:
    bool isAnagram(string s, string t) {
        // edge case
        if(s.size() != t.size()) return false;

        map<char, int> mpp;
        for(char ch : s){
            mpp[ch]++;
        }
        for(char ch : t){
            if(mpp[ch] < 1) return false;
            mpp[ch]--;
        }
        for(char ch : s){
            if(mpp[ch] >= 1) return false;
        }
        return true;
    }
};
