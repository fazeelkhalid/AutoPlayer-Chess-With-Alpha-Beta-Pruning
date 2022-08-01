#include "..\\include\\chessBoard.h"
/*
chessBoard::chessBoard(int whiteHomeParameter){
    for(int i=0;i<=7;i++)
    {
        for(int j=0;j<=7;j++)
        {
            board[i][j]=0;
        }
    }

    whiteMoveDirection = 1;
    whiteHome = 0;
    int blackHome = 7  - whiteHome;

    board[6][6]=-6;
    board[0][7]= 4;
    board[5][0]= 4;
    board[6][4]= 1;
    board[7][0]= 6;
    board[5][4]= 5;
    board[5][3]= 3;
}
*/
chessBoard::chessBoard(int whiteHomeParameter){
//chessBoard1(int whiteHomeParameter){
    for(int r=0; r<8; r++)
        for(int c=0; c<8; c++)
            board[r][c] = 0;
    whiteMoveDirection = 1;
    whiteHome = 0;

    if(whiteHomeParameter == 7){
        whiteHome = whiteHomeParameter;
        this->whiteMoveDirection = -1;
    }

    //White
    board[whiteHome][0]=board[whiteHome][7]= 4;
    board[whiteHome][1]=board[whiteHome][6]= 2;
    board[whiteHome][2]=board[whiteHome][5]= 3;
    board[whiteHome][3]= 5;
    board[whiteHome][4]= 6;

    for(int i = 0; i<8; i++)
        board[whiteHome + whiteMoveDirection][i] = 1;

    // Black

    int blackHome = 7  - whiteHome;

    for(int i = 0; i<8; i++){
        board[blackHome][i] = -board[whiteHome][i];
        board[blackHome - whiteMoveDirection][i] = -board[whiteHome + whiteMoveDirection][i];
    }

}

int chessBoard::initBoardFromFile(std::string fileName){

    return 0;
}
