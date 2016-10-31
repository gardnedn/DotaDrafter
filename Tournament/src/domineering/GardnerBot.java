package domineering;
import game.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.*;
import java.io.Serializable;

import domineering.GardnerBot.ScoredDomineeringMove;

public class GardnerBot extends GamePlayer implements Serializable {
	public static final long serialVersionUID = 42L;
	public HashMap<DomineeringState, ScoredDomineeringMove> hash= new HashMap<DomineeringState, ScoredDomineeringMove>();
	protected ScoredDomineeringMove [] mvStack;
	public int MAX_DEPTH=50;
	public int depthLimit;
	public final int MAX_SCORE=10000;
	
	
	
	protected class ScoredDomineeringMove extends DomineeringMove implements Serializable{
		public double score;
		
		public ScoredDomineeringMove(DomineeringMove m, double s){
			super(m);
			score =s;
		}
		public ScoredDomineeringMove(int r1, int c1, int r2, int c2, double s){
			row1 = r1;
			col1 = c1;
			row2 = r2;
			col2 = c2;
			score=s;
		}
		public void set(int r1, int c1, int r2, int c2, double s){
			row1 = r1;
			col1 = c1;
			row2 = r2;
			col2 = c2;
			score=s;
		}
		public Object clone()
	    { return new ScoredDomineeringMove(row1, col1, row2, col2, score); }
	}
	
	
	public GardnerBot(String n, int d) 
	{
		super(n, "Domineering");
		depthLimit=d;
		//hash.clear();
		//serialize();
		//printHash();
		
		
	
	}
	public GardnerBot(){
		super ("Ragnirok: Destroyer of Worlds", "Domineering");
		depthLimit=4;
		
		readHash();
		
	}
	
	//This is for outputting hashMap to file.
	public void serialize(){
		HashMap<DomineeringState, ScoredDomineeringMove> temp= new HashMap <DomineeringState, ScoredDomineeringMove>();
        
		try{
		
		    String basePath = new File("").getAbsolutePath();
		    String path = new File("src/config/hash.ser").getAbsolutePath();
			//FileOutputStream fileOut = new FileOutputStream("../Users/danielgardner/Documents/hash.ser");
			//FileOutputStream fileOut = new FileOutputStream("src/hash.ser");
		    FileOutputStream fileOut = new FileOutputStream(path);
		ObjectOutputStream out = new ObjectOutputStream(fileOut);
		         out.reset(); 
		         
		         Set set = hash.entrySet();
		         // Get an iterator
		         Iterator i = set.iterator();
		         // Display elements
		         while(i.hasNext()) {
		            Map.Entry me = (Map.Entry)i.next();
		            temp.put((DomineeringState)me.getKey(), (ScoredDomineeringMove)me.getValue());
		            //System.out.print("Key : \n"+ me.getKey() + " \n\n\n Value:  \n");
		            
		            //System.out.println("Serializing "+me.getValue() + "\n\n\n");
		            
		       }
		         
		        // out.writeObject(temp);
		         //out.writeObject(hash);
		         
		         out.writeUnshared(temp);
		         out.flush();
		         out.reset();
		         out.close();
		         
		         fileOut.close();
		        // System.out.printf("Serialized data is saved in /Users/danielgardner/Documents/hash \n");
		      }catch(IOException i){
		          i.printStackTrace();
		      }
		
		}
	
	
	//reads in the hash from file.
	public void readHash(){
		
	    hash.clear(); 
		try
	      {
	         //FileInputStream fileIn = new FileInputStream("/Users/danielgardner/Documents/hash.ser");
			
			//FileInputStream fileIn = new FileInputStream("hash.ser");
			String basePath = new File("").getAbsolutePath();
			//probably should have had basepath+"src/config/hash.ser"..
		    String path = new File("src/config/hash.ser").getAbsolutePath();
		    FileInputStream fileIn= new FileInputStream(path);
			ObjectInputStream in = new ObjectInputStream(fileIn);
	         HashMap<DomineeringState, ScoredDomineeringMove> temp= new HashMap <DomineeringState, ScoredDomineeringMove>();
			 
	         
	         temp=(HashMap) in.readObject();
	        
	         Set set = temp.entrySet();
	         // Get an iterator
	         Iterator i = set.iterator();
	         // Display elements
	         while(i.hasNext()) {
	            Map.Entry me = (Map.Entry)i.next();
	            hash.put((DomineeringState)me.getKey(), (ScoredDomineeringMove)me.getValue());
	            
	       }
	         
	         in.close();
	         fileIn.close();
	      }catch(IOException i)
	      {
	         i.printStackTrace();
	         return;
	      }catch(ClassNotFoundException c)
	      {
	         System.out.println("class not found");
	         c.printStackTrace();
	         return;
	      }
	}
	
	
	
	
	
	
	/**

	 * Performs alpha beta pruning. 
	 * @param brd 
	 * @param currDepth 
	 * @param alpha 
	 * @param beta 

	 */
	private void alphaBeta(DomineeringState brd, int currDepth, double alpha, double beta){

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
	}
	public void init(){
		mvStack=new ScoredDomineeringMove[MAX_DEPTH];
		for (int i=0; i<MAX_DEPTH; i++){
			mvStack[i]= new ScoredDomineeringMove(0,0,0,0,0);
		}
		//hash.clear();
		//serialize();
		//count=0;
		readHash();
		//System.out.println("readhash");
		
	}

	private double evalBoard(DomineeringState brd) {
		int verticalUninterruptable = 0;
		int horizontalUninterruptable = 0;

		//converts chars to booleans
		boolean[][] board= new boolean[brd.board.length][brd.board.length];
		for(int i=0; i< brd.board.length; i++){
			for (int j=0; j< brd.board.length; j++){
				if(brd.board[i][j]=='W' || brd.board[i][j]=='B')
					board[i][j]=true;
				else{
					board[i][j]=false;
				}
			}
			
		}
		
		
		
		
			for (int col = 0; col < 8; col++) {
				for (int row = 0; row < 7; row++) {
		//VERTICLES Uninterruptable moves
				//both are empty
				if ((row<7)&&(col<8) && (!board[row][col] && !board[row + 1][col])) {
					//left and right are either taken or out of bounds
					if ((col == 0 || board[row][col - 1]) && (col == 7 || board[row][col+1])) {
						//(r2 == 0 || board[r2 - 1][c2]) && (r2 == 7 || board[r2 + 1][c2])
						
						//left and right either taken or out of bounds for seconds square
						if ((col == 0 || board[row + 1][col - 1]) && (col == 7 || board[row + 1][col + 1])) {
							
							row++; //avoids counting the same square twice
							verticalUninterruptable++;
							
						}
					}
				}
				
				
			}
		}
		//HORIZONTAL Uninterruptables
		for (int r2 = 0; r2 < 8; r2++) {
			for (int c2 = 0; c2 < 7; c2++) {
				//both are empty
				//&& (r2<7)
				
				if ((r2<8)&&(c2<7) &&(!board[r2][c2] && !board[r2][c2 + 1])) {
					//above and below the first one cannot be taken or are out of bounds
					if ((r2 == 0 || board[r2 - 1][c2]) && (r2 == 7 || board[r2 + 1][c2])) {
						//above and below second
						if ((r2 == 0 || board[r2 - 1][c2 + 1]) && (r2 == 7 || board[r2 + 1][c2 + 1])) {
							c2++;
							horizontalUninterruptable++;
						}
					}
				}
			}
			}	


			int verticalPos = 0;
			int horizontalPos = 0;
			//Check possible horizontal moves
			for (int r3 = 0; r3 < 7; r3++) {
				for (int c3 = 0; c3 < 7; c3++) {
					if (!board[r3][c3] && !board[r3][c3 + 1]) {
						c3++; //avoids counting the same square twice
						horizontalPos++;
						}
					}
				}
			//Check possible vertical moves
			for (int c4 = 0; c4 < 8; c4++) {
				for (int r4 = 0; r4 < 7; r4++) {
					if(c4<8 && r4<7){
					if (!board[r4][c4] && !board[r4+1][c4]) {
						r4++; //avoids counting the same square twice
						verticalPos++;
						}
						}
					}
				}

         //we STRONGLY chose uninterruptable moves, but if we can't make a change then we base it off how many moves left
			// this is so at the transition when there are no more uninterruptable moves to be made,
			//then we just cut off as many moves as we can.
		 return (100*horizontalUninterruptable+horizontalPos) - (100*verticalUninterruptable+verticalPos);

	}
			

	private boolean terminalValue(DomineeringState brd,ScoredDomineeringMove mv) {
		
		GameState.Status status = brd.getStatus();
		
		boolean isTerminal =true;
		if (status==GameState.Status.HOME_WIN){
			mv.set(0,0,0,0,MAX_SCORE);
		}
		else if (status==GameState.Status.AWAY_WIN){
			mv.set(0,0,0,0, - MAX_SCORE);
		}
		else{
			isTerminal =false;
		}
		return isTerminal;
	}

	
	
	
	@Override
	public GameMove getMove(GameState state, String lastMv) {
		
		//printHash();
		
		DomineeringState domState=(DomineeringState) state.clone();
		DomineeringState temp=(DomineeringState) state.clone();
		
		
		          //if board configuration is in our hash we take the value (move) from hash
				if (hash.containsKey((DomineeringState)state)){
					
					if(!((hash.get((DomineeringState)state).col1==0)&& (hash.get((DomineeringState)state).col2==0) && (hash.get((DomineeringState)state).row1==0) && (hash.get((DomineeringState)state).row2==0))){
						return hash.get(temp);
					}
					else {
						//checking to make sure not 0000 (a terminal state)
						//this is done mostly as a precaution
						//because if you exit the game before its done
						//then our game reports that position as a "win"
						//even though you just quit.
						//therefore if it were to get in that position it would assume you would quit again
						//and thus move to 0000 thus throwing the game
						alphaBeta(domState, 0, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);
						return mvStack[0];
					}

		}
		
		
		//don't have in hash, just preform alpha beta. 
				//during prep we would also add to hash.
			
		else{
			
			
		
		
		//alphaBeta((DomineeringState)state, 0, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);
			alphaBeta(domState, 0, Double.NEGATIVE_INFINITY, Double.POSITIVE_INFINITY);
		
		
			
		ScoredDomineeringMove sdm=(ScoredDomineeringMove) mvStack[0].clone();
		
		//used for prep to add to playbook if never have seen game state.
		//hash.put(temp,sdm);
	    //serialize();
	    
		
		
		return mvStack[0];
		}
		
		
	}

	
//used for testing purposes
void printHash(){
	System.out.println("START OF HASH\n\n");
	Set set = hash.entrySet();
    // Get an iterator
    Iterator i = set.iterator();
    // Display elements
    while(i.hasNext()) {
       Map.Entry me = (Map.Entry)i.next();
       System.out.print("Key : \n"+ me.getKey() + " \n Value:  \n");
       System.out.println(me.getValue() + "\n\n");
       
  }

	System.out.println("END OF HASH\n\n\n");
}
	
	
public static void main(String [] args)
{
	GamePlayer p = new GardnerBot("Ragnirok Destroyer of Worlds", 6);
	
	p.compete(args, 1);
	
}
}


