
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <string>

class chessBoard{
    private:

    public:
        int board[8][8];
        int whiteHome;
        int whiteMoveDirection;

        chessBoard(int whiteHomeParameter = 0);
        int initBoardFromFile(std::string fileName);
};

#endif // CHESSBOARD_H
