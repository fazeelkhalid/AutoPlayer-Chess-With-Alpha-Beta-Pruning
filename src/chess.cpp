#include "..\\include\\chess.h"
#include "..\\include\\humanPlayer.h"
#include "..\\include\\autoPlayer.h"
#include <iostream>

chess::chess(){
    G = new gameState();
    Players[0] = new humanPlayer("White Player Name", White);
    Players[1] = new humanPlayer("Black Player Name",Black);
    Interface = new UI();
    Interface->state = G;
}


bool chess::gameOver(){
    if(G->Actions.getActionCount() == 0)
        return true;
    return false;
}

void chess::playGame(){

    action Move;
    int player = White;
    while(!gameOver()){
        Interface->updateView(Players[0]->playerName, Players[1]->playerName);
        Players[player]->decideMove(G,&Move);
        if (G->applyMove(Move) > -1){
            player = 1 - player;
        }
        else{
            player = 1 - player; // Even in case of invalid move change the player
        }
    }

    Interface->updateView(Players[0]->playerName, Players[1]->playerName);

    if (G->kingUnderThreat(White))
        std::cout<<"Black Wins";
    else if(G->kingUnderThreat(Black))
        std::cout<<"White Wins";
    else
        std::cout<<"Stale Mate";
}
