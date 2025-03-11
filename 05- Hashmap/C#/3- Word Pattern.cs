public class Solution {
        public bool WordPattern(string pattern, string s) {
            Dictionary<char , string> mp = new Dictionary<char, string>(); 
            Dictionary<string , bool> valid = new Dictionary<string, bool>();
            string[] str = s.Split(' ');

            char[] pat = pattern.ToCharArray() ; 
            if (str.Length != pattern.Length)
                return false ;

            
            for (int i = 0 ; i < pat.Length ; i++){
                if (!mp.ContainsKey(pat[i]) && !valid.ContainsKey(str[i])){
                    mp[pat[i]] = str[i] ; 
                    valid[str[i]] = true ;
                }
                else {
                    if (!mp.ContainsKey(pat[i]))
                        return false ; 
                    if (mp[pat[i]] != str[i])
                        return false;
                }
            }
            return true ; 
        }
    }