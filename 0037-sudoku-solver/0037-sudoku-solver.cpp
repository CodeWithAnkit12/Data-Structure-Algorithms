class Solution {
public:
    bool valid(int row, int col, char d, vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            if(board[r][col]==d) return false;
        }
        for(int c=0;c<9;c++){
            if(board[row][c]==d) return false;
        }
        int start_r=row/3 *3;
        int start_c=col/3 *3;
        for(int i=start_r;i<start_r+3;i++){
            for(int j=start_c;j<start_c+3;j++){
                if(board[i][j]==d){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    continue;
                }
                for(char d='1';d<='9';d++){
                    if(valid(i,j,d,board)){
                        board[i][j]=d;
                        if(solve(board)){
                            return true;
                        }else{
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};