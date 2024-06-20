#include "a1.h"
#include <iostream>
int main(){
    const int YSTART = 0;
    const int XSTART_K = 3;
    const int XSTART_B = 4;
    const int XSTART_R = 5;
    const int XSTART_Q = 6;

    char pMove;
    bool moveVal, pValid, again;


    Board board;

    //creates objects for pieces
    Knight k1(XSTART_K,YSTART);
    Bishop b1(XSTART_B,YSTART);
    Rook r1(XSTART_R,YSTART);
    Queen q1(XSTART_Q,YSTART);

 //puts pieces on the board 
    board.fillSpace(k1.getX(),k1.getY(),'K');
    board.fillSpace(b1.getX(),b1.getY(),'B');
    board.fillSpace(r1.getX(),r1.getY(),'R');
    board.fillSpace(q1.getX(),q1.getY(),'Q');

    //displays board
    board.printBoard(board);
    
    do{ //actual running of game until user doesnt want to play again
        switch(getPiece()){//decieds which piece to move based off getPiece function
            case 'k':{
                board.emptySpace(k1.getX(), k1.getY());
                k1=k1.Move(board, k1);
                board.fillSpace(k1.getX(), k1.getY(), 'K');
                break;
            }
            case 'b':{
                board.emptySpace(b1.getX(), b1.getY());
                b1=b1.Move(board, b1);
                board.fillSpace(b1.getX(), b1.getY(), 'B');
                break;
            }
            case 'r':{
                board.emptySpace(r1.getX(), r1.getY());
                r1=r1.Move(board, r1);
                board.fillSpace(r1.getX(), r1.getY(), 'R');
                break;
            }
            case 'q':{
                board.emptySpace(q1.getX(), q1.getY());
                q1=q1.Move(board, q1);
                board.fillSpace(q1.getX(), q1.getY(), 'Q');
                break;
            }
        }
        board.printBoard(board);
        again = askAgain(); //checks to see if user wants to play again
    } while (again);

    return 0;
}