#ifndef CHESSPLAYER_H
#define CHESSPLAYER_H

#include<string>
#include "ENUM.h"
#include "gameState.h"
#include "actionList.h"

class chessPlayer{
    public:
        std::string playerName;
        Color playerColor;
        chessPlayer(std::string playerName = "", Color playerColor=White){
            this->playerName = playerName;
            this->playerColor = playerColor;
        }

    virtual void decideMove(gameState* state, action* Move, int maxDepth=-1)=0;
};

#endif // CHESSPLAYER_H
