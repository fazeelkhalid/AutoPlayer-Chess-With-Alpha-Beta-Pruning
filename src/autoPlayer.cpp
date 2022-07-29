#include "..\\include\\autoPlayer.h"
#include<iostream>
#include "..\\include\\ENUM.h"
#include<cstdlib>
using namespace std;

autoPlayer::autoPlayer(Color playerColor):chessPlayer("Auto Player Name", playerColor){


}

void autoPlayer::decideMove(gameState* state, action* Move, int maxDepth ){

    int TotalMoves = state->Actions.getActionCount(); //= state->computePossibleActions();
    cout<<endl<<"Total Possible Moves "<<TotalMoves;
    if(TotalMoves == 0){
        Move->fromRow = Move->fromCol= Move->toRow = Move->toCol = 0;
        return;
    }

    int RandomlySelectedMove = rand()%TotalMoves;

    state->Actions.getAction(RandomlySelectedMove,Move);

    return;
}
