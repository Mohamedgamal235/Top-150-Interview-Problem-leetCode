public class Solution {
    public bool IsIsomorphic(string s, string t) {
        Dictionary<char , char> dic1 = new Dictionary<char,char>();
        Dictionary<char , char> dic2 = new Dictionary<char,char>();

        for (int i = 0 ; i < s.Length ; i++){
            if (dic1.ContainsKey(s[i]) && dic1[s[i]] != t[i])
                return false ; 

            if (dic2.ContainsKey(t[i]) && dic2[t[i]] != s[i])
                return false ; 

            dic1[s[i]] = t[i] ;
            dic2[t[i]] = s[i] ; 
        }

        return true ; 
    }
}