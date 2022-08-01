#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "chessBoard.h"
#include <string>
#include "ENUM.h"
#include "actionList.h"

class gameState{
    private:
        Color playerColor;
        bool firstMoveOfWhiteKing;
        bool firstMoveOfBlackKing;

        // Some Helper Functions
        bool inRange(int r, int c);
        bool checkThreat(int r, int c, Color kingColor, int PieceCodes);
        bool pieceCanMove(int R, int C, int r, int c, Color playerColor);
        void promotePawn(int pawnCode, action& Move);
        void computePieceMoves(int R, int C, int dr, int dc, int maxMoves);
        void computePieceActions(int R, int C);
        void changePlayer(){
            if (playerColor == White)
                playerColor = Black;
            else
                playerColor =  White;
        }
        int computePossibleActions();
    public:

        actionList Actions;
        chessBoard Board;

        gameState();
        int loadGameFromFile(std::string fileName);

        void setPlayer(Color player = White);
        Color getPlayer();

        int applyMove(action Move);
        bool kingUnderThreat(Color kingColor);

};

#endif // GAMESTATE_H
