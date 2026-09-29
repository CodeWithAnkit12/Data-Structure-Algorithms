class Solution {
public:
    int t[101][101][201];
    int m,n;
    bool solve(int i, int j, int oc, vector<vector<char>>& grid){
        oc+= (grid[i][j]=='(') ? 1 : -1;
        if(oc<0) return false;
        if(oc>m+n-i-j-2) return false;
        if(t[i][j][oc]!=-1) return t[i][j][oc];
        if(i==m-1 && j==n-1){
            if(oc==0) return t[i][j][oc]=true;
            else{
                return t[i][j][oc]=false;
            }
        }
        bool ok=false;
        if(i+1<m) ok=solve(i+1,j,oc,grid);
        if(!ok && j+1<n) ok=solve(i, j+1, oc, grid);
        return t[i][j][oc]=ok;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if((m+n-1)%2==1) return false;
        if(grid[0][0]==')' || grid[m-1][n-1]=='('){
            return false;
        }
        memset(t, -1, sizeof(t));
        return solve(0,0,0,grid);
    }
};