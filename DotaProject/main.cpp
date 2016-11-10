//
//  main.cpp
//  DotaProject
//
//  Created by Daniel Gardner on 5/19/16.
//  Copyright (c) 2016 Daniel Gardner. All rights reserved.
//

#include <iostream>
#include "Hero.h"
#include "HeroPool.h"
#include <vector>
int main(int argc, const char * argv[]) {
    
    
    //testing. works
    HeroPool hp = HeroPool();
    std::vector<Hero> vec = hp.getPool();
    Hero h;
    if(!vec.empty()) {
        h = vec.back();
        vec.pop_back();
    }
    //
    return 0;
}


/*alpha beta pruning 
 
 
 boolean toMaximize = (brd.getWho() == GameState.Who.HOME);
 boolean toMinimize = !toMaximize;
 
 boolean isTerminal = terminalValue(brd, mvStack[currDepth]);
 
 DomineeringMove m=new DomineeringMove(0,0,0,0);
 
 if (isTerminal){
 ;
 }
 else if(currDepth==depthLimit){
 mvStack[currDepth].set(0,0,0,0, evalBoard(brd)); //in his code he defaulted to col 0... what is the equivalent here...
 }
 else{
 ScoredDomineeringMove tempMv=new ScoredDomineeringMove(m,0);
 double bestScore= (brd.getWho() == GameState.Who.HOME ? Double.NEGATIVE_INFINITY: Double.POSITIVE_INFINITY);
 
 ScoredDomineeringMove bestMove= mvStack[currDepth];
 ScoredDomineeringMove nextMove= mvStack[currDepth+1];
 bestMove.set(0,0,0,0, bestScore);
 GameState.Who currTurn = brd.getWho();
 
 //cols be a brd ([][])??
 int[][] aBoard = new int[DomineeringState.COLS][DomineeringState.COLS];
 DomineeringState board = (DomineeringState)brd;
 ArrayList<DomineeringMove> list = new ArrayList<DomineeringMove>();
 DomineeringMove mv = new DomineeringMove();
 
 int dr, dc;
 if (brd.who == GameState.Who.HOME) {
 dr = 0;
 dc = 1;
 } else {
 dr = 1;
 dc = 0;
 }
 //System.out.println("before loops");
 for (int r=0; r<DomineeringState.ROWS; r++) {
 for (int c=0; c<DomineeringState.COLS; c++) {
 //	System.out.println("in loops");
 mv.row1 = r;
 mv.col1 = c;
 mv.row2 = r+dr; mv.col2 = c+dc;
 if (board.moveOK(mv)) {
 //	System.out.println("valid move: ");
 //System.out.println("r1: " + r + " col1: "+ c+ " r2: "+ (r+dr) + " col2: " + (c+dc));
 //list.add((DomineeringMove)mv.clone());
 
 brd.makeMove(mv);
 //must adjust alpha and beta.
 alphaBeta(brd, currDepth+1, alpha, beta);
 
 //undo move
 brd.toString();
 brd.numMoves--;
 brd.board[r][c]=DomineeringState.emptySym;
 brd.board[r+dr][c+dc]=DomineeringState.emptySym;
 brd.status= GameState.Status.GAME_ON;
 brd.who= currTurn;
 
 
 //pruning part
 if (toMaximize && nextMove.score > bestMove.score){
 //bestMove.set(c, nextMove.score);
 
 bestMove.set(mv.row1, mv.col1, mv.row2, mv.col2, nextMove.score );
 } else if (!toMaximize && nextMove.score < bestMove.score){
 //bestMove.set(c, nextMove.score);
 bestMove.set(mv.row1, mv.col1, mv.row2, mv.col2, nextMove.score );
 }
 
 if (toMinimize){
 beta=Math.min(bestMove.score,  beta);
 if(bestMove.score <= alpha || bestMove.score == - MAX_SCORE){
 return;
 }
 } else {
 alpha=Math.max(bestMove.score,  alpha);
 if(bestMove.score>=beta|| bestMove.score==MAX_SCORE)
 return;
 }
 }
 }
 }
 }
	
 
 
 
 */






