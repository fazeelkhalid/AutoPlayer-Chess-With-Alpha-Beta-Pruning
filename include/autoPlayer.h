#ifndef KEYBOARDMUJAHID_H
#define KEYBOARDMUJAHID_H
#include"chessPlayer.h"
#include<vector>
#include<iostream>
using namespace std;


class autoPlayer:public chessPlayer
{
	int countMoves;
public:
	autoPlayer(Color playerColor) :chessPlayer("Keyboard Mujahid",playerColor)
	{
		countMoves = 0;
		srand(time(NULL));
	}

	int midEvaluation(gameState g) {
		int score = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (g.Board.board[i][j] == 4 || g.Board.board[i][j] == -4) {// code rock
					score += 5;
				}
				else if (g.Board.board[i][j] == 2 || g.Board.board[i][j] == -2) {// code knight
					score += 3;
				}
				else if (g.Board.board[i][j] == 3 || g.Board.board[i][j] == -3) {// code bishup
					score += 3;
				}
				else if (g.Board.board[i][j] == 5 || g.Board.board[i][j] == -5) {// code queen
					score += 9;
				}
				else if (g.Board.board[i][j] == 6 || g.Board.board[i][j] == -6) {// code king
					score += 100;
				}
				else if (g.Board.board[i][j] == 1 || g.Board.board[i][j] == -1) {// code pawn
					score += 1;
				}
				
			}
		return score;
	}

	int startEvaluation(gameState g) {
		int score = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{

				score += g.Board.board[i][j] * 3;
			}
		return score;
	}

	int advanceEvaluation(gameState g) {
		int score = midEvaluation(g);
		if (g.getPlayer() != playerColor) {
			if (g.kingUnderThreat(g.getPlayer())) { // if just king underThread
				score += 8;
			}
			if (g.Actions.getActionCount() == 0 && g.kingUnderThreat(g.getPlayer())) { // if king underThread and no moves are left
				score += 100;
			}
		}
		return score;
	}

	int generateScore(gameState g)
	{
		int score;
		if (countMoves < 3) {
			score = startEvaluation(g);
		}
		else if (countMoves < 7) {
			score = midEvaluation(g);
		}
		else {
			score = advanceEvaluation(g);
		}
		

		if (g.getPlayer() == White)
		{
			return score;
		}
		else
		{
			return (score * -1);
		}
	}

	int minMaxPruning(gameState g,int depth,int alpha,int beta,bool playerType,int& actionNumber, int returnDepth)
	{
		if (depth == 1 || g.Actions.getActionCount() == 0)
		{
			return generateScore(g);
		}
		if (playerType)
		{
			/*int bestValue = INT_MIN;*/
			for (int i = g.Actions.getActionCount() - 1; i >= 0; i--)
			{
				action act;
				g.Actions.getAction(i, &act);
				gameState g1 = g;
				g1.applyMove(act);
				int val = minMaxPruning(g1, depth - 1, alpha, beta, false,actionNumber, returnDepth);
				if (depth== returnDepth && alpha < val)
				{
					actionNumber = i;
				}
				alpha = max(alpha, val);
				
				if (beta <= alpha)
					break;
			}
			return alpha;
		}
		else
		{
			for (int i = g.Actions.getActionCount() - 1; i >= 0; i--)
			{
				action act;
				g.Actions.getAction(i, &act);
				gameState g1 = g;
				
				g1.applyMove(act);
				int val = minMaxPruning(g1, depth - 1, alpha, beta, true,actionNumber, returnDepth);
				beta = min(beta, val);
				if (beta <= alpha)
					break;
			}
			return beta;
		}
	}

	void decideMove(gameState* state, action* Move, int maxDepth = -1)
	{
		countMoves++;
		if (countMoves == 1) { // as we want to start with always new opening if we start with directly minmax we can't get this feature
			if (state->Actions.getActionCount() == 0) {
				Move->fromRow = Move->fromCol = Move->toRow = Move->toCol = 0;
				return;
			}
			

			state->Actions.getAction(rand() % state->Actions.getActionCount(), Move);
			return;
		}
		else {
			int actNo;
			int depth = 6;
			minMaxPruning(*state, depth, INT_MIN, INT_MAX, true, actNo, depth);
			state->Actions.getAction(actNo, Move);
		}
	}
};

#endif