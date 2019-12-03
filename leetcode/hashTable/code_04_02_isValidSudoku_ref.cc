class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //判断同一行
		for(int i=0;i<9;i++){
            int buf[10]={0};
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int t=board[i][j]-'0';
                    buf[t]++;
                }
            }
            for(int k=1;k<10;k++){
                if(buf[k]>=2){
                    return false;
                }
            }
        }
		//判断同一列
        for(int i=0;i<9;i++){
            int buf[10]={0};
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    int t=board[j][i]-'0';
                    buf[t]++;
                }
            }
            for(int k=1;k<10;k++){
                if(buf[k]>=2){
                    return false;
                }
            }
        }
		//三角矩阵
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int buf[10]={0};
                for(int ii=0;ii<3;ii++){
                    for(int jj=0;jj<3;jj++){
                        if(board[i+ii][j+jj]!='.'){
                            int t=board[i+ii][j+jj]-'0';
                            buf[t]++;
                        }
                    }
                }
                for(int i=1;i<10;i++){
                    if(buf[i]>=2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};