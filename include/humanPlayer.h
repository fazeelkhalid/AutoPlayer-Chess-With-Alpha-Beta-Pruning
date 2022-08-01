#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include<string>
#include"ENUM.h"
#include "chessPlayer.h"

class humanPlayer : public chessPlayer {
    public:
        humanPlayer(std::string playerName="DEFAULT NAME", Color playerColor=White);
        void decideMove(gameState* state, action* Move, int maxDepth = -1);
};


#endif // HUMANPLAYER_H
