#ifndef CHESS_H
#define CHESS_H

#include "gameState.h"
#include "chessPlayer.h"
#include "UI.h"

class chess{
    public:
        gameState* G;
        chessPlayer *Players[2];
        UI* Interface;

        chess();
        bool gameOver();
        void playGame();
};


#endif // CHESS_H
