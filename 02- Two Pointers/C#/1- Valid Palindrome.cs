public class Solution {
    public bool IsPalindrome(string s) {
        StringBuilder str = new StringBuilder();
        foreach (char c in s)
            if (char.IsLetterOrDigit(c))
                str.Append(char.ToLower(c));

        int l = 0 , r = str.Length -1 ;
        while (l < r) {
            if (str[l] != str[r])
                return false ;
            l++;
            r-- ;
        }
        return true ;
    }
}