#include "a1.h"
#include <iostream>

const int getDist(int to, int from){ //gets distance from current space to input
    int d;

    d = to-from;
    if(d < 0)
        d= d*-1;
    
    return d;
}
const char getPiece(){ //asks user which piece they want to move
    char piece;
    bool pValid = false;
    
    do{//check validity of input
        std::cout << "Select a Piece to Move (K, B, R, Q): ";
        std::cin >> piece;
        piece = tolower(piece);
        if(piece=='k'||piece=='b'||piece=='r'||piece=='q')
            pValid=true;
        if(!pValid)
            std::cout << "\nPiece input invalid. Try again.";
        }while(!pValid);
    return piece;
}
const void printHLine(){ //prints line for board formatting
    for(int i=0; i<BOARD_MAX; i++)
        std:: cout << "----";
    std:: cout << "-" << std::endl;
}
const bool askAgain(){ //asks users if they want to move again
    char ans;
    bool again, valid;

    valid = true;

    do{//check answer validity
        std::cout << "\nDo you want to play again? (Y/N): ";
        std:: cin >> ans;
        ans = tolower(ans);
        switch(ans){
            case 'y':
                again = true;
                valid = true;
                break;
            case 'n':
                again = false;
                valid = true;
                std:: cout << "Thanks for playing!!\n" << std::endl;
                break;
        }
        if(ans!='n' && ans!='y'){
            valid = false;
            std :: cout << "Input invalid. Press Y or N." << std ::endl;
        }
    }while(!valid);
    return again;
}
const bool kCheck(int x, int y){ //checks knight move validity
    return((x==1 && y==2) || (x == 2 && y == 1));
}
const bool bCheck(int x, int y){ //check bishop move validity
    return(x==y && x>0);
}
const bool rCheck(int x, int y){ //checks rook move validity
    return((x==0 && y>0)|| (y==0 && x>0));
}    
const bool qCheck(int x, int y){ //checks queen move validity
    return(bCheck(x,y) || rCheck(x,y));
}  
Board::Board(){ //creates full board
    fillBoard();
}
void Board::fillBoard(){ //fills board array with spaces
    for(int i=0; i<BOARD_MAX; i++){
        for(int j=0; j<BOARD_MAX ; j++)
            space[i][j] = ' ';
    }
}
const char Board::getSpace(int x, int y){ //returns value in a space
    return space[x][y];
}
void Board::fillSpace(int x, int y, char p){ //places value into space
    this -> space[x][y] = p;
}
void Board::emptySpace(int x, int y){ //replaces space value with a space after piece moves
    this ->space[x][y] = ' ';
}
const void Board::printBoard(Board board){ //prints board with contents for user viewing
    for(int i=BOARD_MAX-1;i>=BOARD_MIN; i--){
        printHLine();
        for(int j=BOARD_MIN;j < BOARD_MAX; j++){
            std::cout<< "| " << board.getSpace(j,i) << " ";
        }
        std::cout << "|" << std::endl;
    }
    printHLine();
}
Knight :: Knight(int x, int y){ //sets position
    setPos(x,y);
} 
Knight Knight::Move(Board board, Knight k){ // moves piece
    int x, y, distX, distY;
    bool valid;

    do{ //checks all validity types
        std::cout << "The Knight is at x=" << k.getX() << ". Input x-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "):";
        std::cin >> x;
        std::cout << "The Knight is at y=" << k.getY() << ". Input y-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> y; 

        valid = true;
        distX = getDist(k.getX(), x); //get distnce from current position to input
        distY = getDist(k.getY(), y);

        if(!kCheck(distX, distY)){ //check knight validity
            std::cout << "Input move invalid with this piece type. Try again" << std::endl;
            valid = false;
        }
        if(x < BOARD_MIN || x >= BOARD_MAX || y < BOARD_MIN || y >= BOARD_MAX){ //check board bound validity
            valid = false;
            std::cout << "Input out of bounds try again" << std:: endl;
        }
        if(board.getSpace(x,y)!=' '){ //checks space occupancy
            valid = false;
            std::cout << "Space occupied. Try again" << std::endl;
        }
        if(valid){ //moves piece
            k.setPos(x, y);
        }
    }while(!valid);
    return k;
}
const int Knight::getX(){ //returns x values
    return x;
}
const int Knight::getY(){ //returns y values
    return y;
}
void Knight::setPos(int x, int y){ // sets x and y
    this -> x = x;
    this -> y = y;
}

//comments remain consistent because all classes are essentially copies

Bishop :: Bishop(int x, int y){
    setPos(x,y);
}

Bishop Bishop::Move(Board board, Bishop b){
    int x, y, distX, distY;
    bool valid;

    do{
        std::cout << "The Bishop is at x=" << b.getX() << ". Input x-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> x;
        std::cout << "The Bishop is at y=" << b.getY() << ". Input y-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "):" ;
        std::cin >> y; 

        valid = true;
        distX = getDist(b.getX(), x);
        distY = getDist(b.getY(), y);

        if(!bCheck(distX, distY)){
            std::cout << "Input move invalid with this piece type. Try again" << std::endl;
            valid = false;
        }
        if(x < BOARD_MIN || x >= BOARD_MAX || y < BOARD_MIN || y >= BOARD_MAX){
            valid = false;
            std::cout << "Input out of bounds try again" << std:: endl;
        }
        if(board.getSpace(x,y)!=' '){
            valid = false;
            std::cout << "Space occupied. Try again" << std::endl;
        }
        if(valid){
            b.setPos(x, y);
        }
    }while(!valid);
    return b;
}
const int Bishop::getX(){
    return x;
}
const int Bishop::getY(){
    return y;
}
void Bishop::setPos(int x, int y){
    this -> x = x;
    this -> y = y;
}
Rook :: Rook(int x, int y){
    setPos(x,y);
}
Rook Rook::Move(Board board, Rook r){
    int x, y, distX, distY;
    bool valid;

    do{
        std::cout << "The Rook is at x=" << r.getX() << ". Input x-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> x;
        x = static_cast<int> (x); //turns x to int
        std::cout << "The Rook is at y=" << r.getY() << ". Input y-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> y; 
        y = static_cast<int> (y);

        valid = true;
        distX = getDist(r.getX(), x);
        distY = getDist(r.getY(), y);

        if(!rCheck(distX, distY)){
            std::cout << "Input move invalid with this piece type. Try again" << std::endl;
            valid = false;
        }
        if(x < BOARD_MIN || x >= BOARD_MAX || y < BOARD_MIN || y >= BOARD_MAX){
            valid = false;
            std::cout << "Input out of bounds try again" << std:: endl;
        }
        if(board.getSpace(x,y)!=' '){
            valid = false;
            std::cout << "Space occupied. Try again" << std::endl;
        }
        if(valid){
            r.setPos(x, y);
        }
    }while(!valid);
    return r;
}
const int Rook::getX(){
    return x;
}
const int Rook::getY(){
    return y;
}
void Rook::setPos(int x, int y){
    this -> x = x;
    this -> y = y;
}
Queen :: Queen(int x, int y){
    setPos(x,y);
}
Queen Queen::Move(Board board, Queen q){
    int x, y, distX, distY;
    bool valid;

    do{
        std::cout << "The Queen is at x=" << q.getX() << ". Input x-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> x;
        std::cout << "The Queen is at y=" << q.getY() << ". Input y-coordinate it is moving to(" << BOARD_MIN<< ", " << BOARD_MAX-1 << "): ";
        std::cin >> y; 

        valid = true;
        distX = getDist(q.getX(), x);
        distY = getDist(q.getY(), y);

        if(!qCheck(distX, distY)){
            std::cout << "Input move invalid with this piece type. Try again" << std::endl;
            valid = false;
        }
        if(x < BOARD_MIN || x >= BOARD_MAX || y < BOARD_MIN || y >= BOARD_MAX){
            valid = false;
            std::cout << "Input out of bounds try again" << std:: endl;
        }
        if(board.getSpace(x,y)!=' '){
            valid = false;
            std::cout << "Space occupied. Try again" << std::endl;
        }
        if(valid){
            q.setPos(x, y);
        }
    }while(!valid);
    return q;
}
const int Queen::getX(){
    return x;
}
const int Queen::getY(){
    return y;
}
void Queen::setPos(int x, int y){
    this -> x = x;
    this -> y = y;
}
