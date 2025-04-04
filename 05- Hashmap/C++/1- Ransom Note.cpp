class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char , int> mp;
    
            for (auto c : magazine)
                mp[c]++ ;
    
            for (auto c : ransomNote) {
                if (mp[c])
                    mp[c]-- ;
                else
                    return false ;
            }
            return true ;
        }
    };