class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), max_len=1;
        if(len == 1)
            return s;
        string res = s.substr(0,1);
        vector<vector<int>> mat(len, vector<int>(len,0));
        
        for(int i=0;i <len; i++)
            mat[i][i] = 1;
        
        for(int i=1; i<len; i++)
        {
            for(int j=0; j<len-i; j++)
            {
                int x=j;
                int y=i+j;
                
                if(s[x] == s[y] && ((y-x+1 == 2) || mat[x+1][y-1] > 0)){
                    mat[x][y] = 2 + mat[x+1][y-1];
                    int curr_len = y-x+1;
                    if(curr_len > max_len){
                        max_len = curr_len;
                        res = s.substr(x,y-x+1);
                    }
                }
                else
                    mat[x][y] = 0;
            }
        }
        
        return res;
    }
};