#include "..\\include\\humanPlayer.h"
#include <iostream>

using namespace std;

humanPlayer::humanPlayer(string playerName, Color playerColor):chessPlayer(playerName,playerColor){

}

void humanPlayer::decideMove(gameState* state, action* Move, int maxDepth){
    cout<<endl<<"Please Enter a Move: from (row, col) to (row, col)"<<endl;
    cin>>(*Move).fromRow>>(*Move).fromCol>>(*Move).toRow>>(*Move).toCol;
}
