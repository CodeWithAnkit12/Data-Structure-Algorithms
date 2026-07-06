class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int index=0;
        while(i<n){
            char curr_char=chars[i];
            int cnt=0;
            while(i<n && chars[i]==curr_char){
                cnt++;
                i++;
            }
            chars[index]=curr_char;
            index++;
            string s=to_string(cnt);
            if(cnt>1){
                for(auto &ch:s){
                    chars[index]=ch;
                    index++;
                }
            }           
        }
        return index;
    }
};