class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> res(min(numRows,int(s.size())));
        int currRow = 0;
        bool going_down = false;
        
        for(int i=0; i<s.length(); i++)
        {
            res[currRow].push_back(s[i]);
            
            if(currRow == 0 || currRow == (numRows - 1))
                going_down = !going_down;
            if(going_down)
                currRow+=1;
            else
                currRow-=1;
        }
        
        string ret;
        for(int i=0; i<res.size(); i++)
            ret.append(res[i]);
        
        return ret;
    }
};