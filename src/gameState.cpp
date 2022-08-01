#include "..\\include\\gameState.h"

gameState::gameState(){
    playerColor = White;
    firstMoveOfWhiteKing = true;
    firstMoveOfBlackKing = true;
    computePossibleActions();
}

bool gameState::checkThreat(int r, int c, Color kingColor, int PieceCodes){

    int kingSign = (2*kingColor-1);
    if( inRange(r,c) && Board.board[r][c]*kingSign < 0){
        if (Board.board[r][c]*kingSign == PieceCodes) {
            return true;
        }
    }
    return false;
}

bool gameState::kingUnderThreat(Color kingColor){

    // Find the King
    int R = 0 , C = 0; // Position of King
    int kingSign = 2*kingColor - 1;

    for (int r=0; r<8; r++){
        for(int c=0; c<8; c++){
            if (Board.board[r][c]*kingSign == 6){
                R = r;
                C = c;
            }
        }
    }


    // Check if it is Under Threat
    int r=0, c=0;

    // Check if it is Under Threat by Rook or Queen
    for(r = R + 1, c =C;  inRange(r, c) && Board.board[r][c]==0; r++);
    if (checkThreat(r,c,kingColor,-4) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R - 1, c =C;  inRange(r, c) && Board.board[r][c]==0; r--);
    if (checkThreat(r,c,kingColor,-4) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R , c = C+1;  inRange(r, c) && Board.board[r][c]==0; c++);
    if (checkThreat(r,c,kingColor,-4) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R, c = C-1;  inRange(r, c) && Board.board[r][c]==0; c--);
    if (checkThreat(r,c,kingColor,-4) || checkThreat(r,c,kingColor,-5)) return true;

    // Check if it is Under Threat by Bishop or Queen
    for(r = R + 1, c = C + 1;  inRange(r, c) && Board.board[r][c]==0; r++, c++);
    if (checkThreat(r,c,kingColor,-3) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R + 1, c = C - 1;  inRange(r, c) && Board.board[r][c]==0; r++, c--);
    if (checkThreat(r,c,kingColor,-3) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R - 1, c = C + 1;  inRange(r, c) && Board.board[r][c]==0; r--, c++);
    if (checkThreat(r,c,kingColor,-3) || checkThreat(r,c,kingColor,-5)) return true;

    for(r = R - 1, c = C - 1;  inRange(r, c) && Board.board[r][c]==0; r--, c--);
    if (checkThreat(r,c,kingColor,-3) || checkThreat(r,c,kingColor,-5)) return true;

    // Check if it is Under Threat by Knight

    if (checkThreat(R + 2, C + 1, kingColor,-2)) return true;
    if (checkThreat(R + 2, C - 1, kingColor,-2)) return true;

    if (checkThreat(R - 2, C + 1, kingColor,-2)) return true;
    if (checkThreat(R - 2, C -1, kingColor,-2)) return true;

    if (checkThreat(R + 1, C + 2, kingColor,-2)) return true;
    if (checkThreat(R - 1, C + 2, kingColor,-2)) return true;

    if (checkThreat(R + 1, C - 2, kingColor,-2)) return true;
    if (checkThreat(R - 1, C - 2, kingColor,-2)) return true;

    // Check if it is Under Threat by Pawn
    int checkingDirection = Board.whiteMoveDirection;
    if (kingColor == White)
        checkingDirection*=-1;
    if (checkThreat(R - checkingDirection, C + 1, kingColor,-1)) return true;
    if (checkThreat(R - checkingDirection, C - 1, kingColor,-1)) return true;


    // Check if it is Under Threat by King
    if (checkThreat(R - 1 , C - 1, kingColor,-6)) return true;
    if (checkThreat(R - 1 , C    , kingColor,-6)) return true;
    if (checkThreat(R - 1 , C + 1, kingColor,-6)) return true;

    if (checkThreat(R , C + 1, kingColor,-6)) return true;
    if (checkThreat(R , C - 1, kingColor,-6)) return true;

    if (checkThreat(R + 1 , C - 1, kingColor,-6)) return true;
    if (checkThreat(R + 1 , C    , kingColor,-6)) return true;
    if (checkThreat(R + 1 , C + 1, kingColor,-6)) return true;

    return false;
}

void gameState::setPlayer(Color player){
    playerColor = player;
}

Color gameState::getPlayer(){
    return playerColor;
}

int gameState::loadGameFromFile(std::string fileName){
    // return Board.initBoardFromFile(fileName);
    return 0;
}

bool gameState::inRange(int r, int c) {
    if (0 > r || r > 7 || 0 > c || c > 7)
        return false;
    return true;
}

bool gameState::pieceCanMove(int R, int C, int r, int c, Color playerColor){

    int pieceCode  = Board.board[r][c];
    Board.board[r][c] = Board.board[R][C];
    Board.board[R][C] = 0;

    bool KUT = kingUnderThreat(playerColor);

    Board.board[R][C] = Board.board[r][c];
    Board.board[r][c] = pieceCode;

    if(KUT)
        return false;
    return true;
}

void gameState::computePieceMoves(int R, int C, int dr, int dc, int maxMoves){
    int r = R + dr, c = C + dc ;
    int MoveCounter = 0;
    action Move;

    for( r = R + dr, c = C + dc; MoveCounter < maxMoves && inRange(r,c) && Board.board[r][c] == 0; r+=dr, c+=dc, MoveCounter++ ){
        Move.fromRow = R; Move.fromCol = C;
        Move.toRow = r; Move.toCol = c;

        if (pieceCanMove(R,C,r,c,playerColor))
            Actions.addAction(Move);
    }

    if( MoveCounter < maxMoves && inRange(r,c) && Board.board[r][c] * Board.board[R][C] < 0){
        if( (Board.board[R][C] != 1 && Board.board[R][C] != -1 )|| dc !=0){
            Move.fromRow = R; Move.fromCol = C;
            Move.toRow = r; Move.toCol = c;
            if (pieceCanMove(R,C,r,c,playerColor))
                Actions.addAction(Move);
        }
    }
}

void gameState::computePieceActions(int R, int C){
    int pieceCode = Board.board[R][C];
    switch(pieceCode){
        case 4:
        case -4:
            computePieceMoves(R, C, 1, 0, 7);
            computePieceMoves(R, C,-1, 0, 7);
            computePieceMoves(R, C, 0, 1, 7);
            computePieceMoves(R, C, 0,-1, 7);
        break;

        case 2:
        case -2:
            computePieceMoves(R, C,  2,  1, 1);
            computePieceMoves(R, C,  2, -1, 1);
            computePieceMoves(R, C, -2,  1, 1);
            computePieceMoves(R, C, -2, -1, 1);
            computePieceMoves(R, C,  1,  2, 1);
            computePieceMoves(R, C, -1,  2, 1);
            computePieceMoves(R, C,  1, -2, 1);
            computePieceMoves(R, C, -1, -2, 1);

        break;

        case 3:
        case -3:
            computePieceMoves(R, C,  1,  1, 7);
            computePieceMoves(R, C,  1, -1, 7);
            computePieceMoves(R, C, -1,  1, 7);
            computePieceMoves(R, C, -1, -1, 7);
        break;
        case 5:
        case -5:
            computePieceMoves(R, C,  1,  1, 7);
            computePieceMoves(R, C,  1, -1, 7);
            computePieceMoves(R, C, -1,  1, 7);
            computePieceMoves(R, C, -1, -1, 7);

            computePieceMoves(R, C,  1,  0, 7);
            computePieceMoves(R, C, -1,  0, 7);
            computePieceMoves(R, C,  0,  1, 7);
            computePieceMoves(R, C,  0, -1, 7);

        break;
        case 6:
        case -6:
            // Regular Moves of King
            for (int dx = -1; dx < 2; dx++){
                for(int dy = -1; dy < 2; dy++){
                    if(dx != 0 || dy !=0){
                        if(Board.board[R][C]*Board.board[R+dx][C+dy] <= 0){
                            int tmpPiece = Board.board[R+dx][C+dy];
                            Board.board[R+dx][C+dy] = Board.board[R][C];
                            Board.board[R][C] = 0;
                            bool impossPossible = kingUnderThreat(playerColor);

                            Board.board[R][C] = Board.board[R+dx][C+dy];
                            Board.board[R+dx][C+dy] = tmpPiece;

                            if(!impossPossible)
                                computePieceMoves(R, C,  dx,  dy, 1);
                        }
                    }
                }
            }

        break;
        case 1:
        case -1:
            // Regular Pawn Moves
            int pawnDirection = Board.whiteMoveDirection;
            if(Board.board[R][C] < 0)
                pawnDirection*=-1;

            computePieceMoves(R, C,  pawnDirection,  0, 1);

            // First Double Move
            if (Board.board[R][C] > 0 && Board.whiteHome == 0 && R == 1)
                computePieceMoves(R, C,  pawnDirection + 1,  0, 1);
            else if (Board.board[R][C] > 0 && Board.whiteHome == 7 && R == 6)
                computePieceMoves(R, C,  pawnDirection - 1,  0, 1);
            else if (Board.board[R][C] <  0 && Board.whiteHome == 0 && R == 6)
                computePieceMoves(R, C,  pawnDirection - 1 ,  0, 1);
            else if (Board.board[R][C] <  0 && Board.whiteHome == 7 && R == 1)
                computePieceMoves(R, C,  pawnDirection + 1,  0, 1);

            // Side Pice Capture Move
            if(inRange(R + pawnDirection, C + 1))
                if (Board.board[R][C]* Board.board[R + pawnDirection][C + 1] < 0)
                    computePieceMoves(R, C,  pawnDirection, 1, 1);

            if(inRange(R + pawnDirection, C - 1))
                if (Board.board[R][C]* Board.board[R + pawnDirection][C -1] < 0)
                    computePieceMoves(R, C,  pawnDirection, -1, 1);
        break;
    }
}

int gameState::computePossibleActions(){
    Actions.resetActions();
    int playerSign  = playerColor*2 - 1;

    for (int r=0; r<8; r++){
        for(int c=0; c<8; c++){
            if(Board.board[r][c]*playerSign > 0){
                computePieceActions(r, c);
            }
        }
    }
    return 0;
}

void gameState::promotePawn(int pawnCode, action& Move){

    if( ( (pawnCode == 1) && (Move.toRow == 7 - Board.whiteHome) ) || ( (pawnCode == -1) && (Move.toRow == Board.whiteHome) ) ){

        Board.board[Move.toRow][Move.toCol] = 5*pawnCode;
        changePlayer();
        computePossibleActions();
        if (kingUnderThreat(playerColor) || Actions.getActionCount() > 0){
            changePlayer(); return;
        }

        Board.board[Move.toRow][Move.toCol] = 4*pawnCode;
        computePossibleActions();
        if (kingUnderThreat(playerColor) || Actions.getActionCount() > 0){
            changePlayer(); return;
        }

        Board.board[Move.toRow][Move.toCol] = 3*pawnCode;
        computePossibleActions();
        if (kingUnderThreat(playerColor) || Actions.getActionCount() > 0){
            changePlayer(); return;
        }

        Board.board[Move.toRow][Move.toCol] = 2*pawnCode;
        computePossibleActions();
        if (kingUnderThreat(playerColor) || Actions.getActionCount() > 0){
            changePlayer(); return;
        }

        Board.board[Move.toRow][Move.toCol] = pawnCode;
        changePlayer();  return;
    }
}

int gameState::applyMove(action Move){
    if( Actions.validAction(Move)){
        Board.board[Move.toRow][Move.toCol] = Board.board[Move.fromRow][Move.fromCol];
        Board.board[Move.fromRow][Move.fromCol] = 0;

        if( (Board.board[Move.toRow][Move.toCol] == 1) || (Board.board[Move.toRow][Move.toCol] == -1) )
            promotePawn(Board.board[Move.toRow][Move.toCol],Move);

        changePlayer();
        computePossibleActions();
        return 0;
    }
    return -1;
}
