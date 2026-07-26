class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1=series1.size();
        int n2=series2.size();
        int i=0,j=0;
        vector<vector<int>> vec;
        while(i<n1 || j<n2){
            int t;
            if(i==n1){
                t=series2[j][0];
            }else if(j==n2){
                t=series1[i][0];
            }else{
                t=min(series1[i][0],series2[j][0]);
            }
            int x1=0;
            if(i<n1){
                x1=series1[i][1];
            }
            int x2=0;
            if(j<n2){
                x2=series2[j][1];
            }
            vec.push_back({t,x1+x2});
            if(i<n1 && series1[i][0]==t) {
                i++;
            }
            if(j<n2 && series2[j][0]==t) {
                j++;
            }
        }
        return vec;
    }
};