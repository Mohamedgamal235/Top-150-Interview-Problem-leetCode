class Solution {
    public:
        int lengthOfLastWord(string s) {
            reverse(s.begin() , s.end());
    
            // "   fly me   to   the moon  "
            string str = "" ;
            bool space = false ;
            for (int i = 0 ; i < s.size() ; i++) {
                if (s[i] != ' ') {
                    for (int j = i ; j < s.size() ; j++) {
                        if (s[j] == ' '){
                            space = true ;
                            break;
                        }
                        str += s[j] ;
                        if (j + 1 == s.size())
                            space = true ; 
                    }
                }
                if (space)
                    break;
            }
            return str.size() ;
        }
    };