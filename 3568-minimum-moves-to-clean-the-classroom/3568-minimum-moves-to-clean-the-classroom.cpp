class Solution {
public:
    using VB=vector<bool>;
    using VVB=vector<VB>;
    using VVVB=vector<VVB>;
    using VVVVB=vector<VVVB>;
    struct state {
        int r;
        int c;
        int el;
        int cm;
    };
    vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int me=energy;
        int litterbit[20][20];
        int litter_count=0;
        int sr=0;
        int sc=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                litterbit[r][c]=-1;
                if(classroom[r][c]=='S'){
                    sr=r;
                    sc=c;
                }else if(classroom[r][c]=='L'){
                    litterbit[r][c]=litter_count;
                    litter_count++;
                }
            }
        }
        int allcollected=(1 << litter_count) -1;
        if(allcollected==0){
            return 0;
        }
        VVVVB visited(m,VVVB(n,VVB(me+1,VB(1 << litter_count,false))));
        queue<state> q;
        q.push({sr,sc,me,0});
        visited[sr][sc][me][0]=true;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                state curr=q.front();
                q.pop();
                if(curr.cm==allcollected){
                    return ans;
                }
                if(curr.el==0){
                    continue;
                }
                for(auto &dir:direction){
                    int nr=curr.r+dir[0];
                    int nc=curr.c+dir[1];
                    if(nr<0||nr>=m||nc<0||nc>=n){
                        continue;
                    }
                    char cell=classroom[nr][nc];
                    if(cell=='X') continue;
                    int ne=curr.el-1;
                    int ncm=curr.cm;
                    if(cell=='R'){
                        ne=me;
                    }else if(cell=='L'){
                        ncm|=(1 << litterbit[nr][nc]);
                    }
                    if(!visited[nr][nc][ne][ncm]){
                        visited[nr][nc][ne][ncm]=true;
                        q.push({nr,nc,ne,ncm});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};