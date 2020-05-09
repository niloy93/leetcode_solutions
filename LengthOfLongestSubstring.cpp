class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, ptr = 0, max_len=0, curr_len = 0;
        map<char,int> hash;
        int len = s.length();
        
        while(ptr < len)
        {
            hash[s[ptr]]++;
            if(hash[s[ptr]] > 1)
            {
                while(start < ptr && hash[s[ptr]] > 1){
                    hash[s[start++]]--;
                    curr_len--;
                }
                curr_len++;
            }
            else
                curr_len++;
            
            if(curr_len > max_len)
                max_len = curr_len;
            ptr++;
               
        }
        
        return max_len;
    }
};