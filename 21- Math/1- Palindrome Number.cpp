class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
                return false ;
    
            string str ;
            while (x != 0) {
                str.push_back((x%10) + '0') ;
                x /= 10 ;
            }
    
            for (int i = 0 ; i < str.size() / 2 ; i++)
                if (str[i] != str[str.size() - 1 - i])
                    return false;
    
            return true ;
        }
    };