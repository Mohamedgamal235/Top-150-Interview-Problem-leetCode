class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char , string> mp ;
            unordered_map<string , bool> valid ;
    
            vector<string> str;
            stringstream ss(s);
            string word;
    
            while (ss >> word) {
                str.push_back(word);
            }
            
            if (pattern.size() != str.size())
                return false ;
    
            for (int i = 0 ; i < pattern.size() ; i++) {
                if (mp.find(pattern[i]) == mp.end() && valid.find(str[i]) == valid.end()) {
                    mp[pattern[i]] = str[i] ;
                    valid[str[i]] = true ;
                }
                else {
                    if (mp.find(pattern[i]) == mp.end())
                        return false ;
                    if (mp[pattern[i]] != str[i])
                        return false ;
                }
            }
    
            return true;
        }
    };