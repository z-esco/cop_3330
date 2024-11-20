const int BOARD_MAX = 10;
const int BOARD_MIN = 0;

const int getDist(int to, int from);
const char getPiece();
const bool askAgain();
const void printHLine();
const bool kCheck(int x, int y);
const bool bCheck(int x, int y);
const bool rCheck(int x, int y);
const bool qCheck(int x,  int y);

class Board
{
    private:
    char space[BOARD_MAX][BOARD_MAX];
    void fillBoard();

    public:
    Board();
    const char getSpace(int x, int y);
    void fillSpace(int x, int y, char p);
    void emptySpace(int x, int y);
    const void printBoard(Board board);
};
class Knight
{
    private:
    int x;
    int y;
    void setPos(int x, int y);

    public:
    Knight(int x, int y);
    Knight Move(Board board, Knight k);
    const int getX();
    const int getY();
};

class Bishop
{
    private:
    int x;
    int y;
    void setPos(int x, int y);

    public:
    Bishop(int x, int y);
    Bishop Move(Board board, Bishop k);
    const int getX();
    const int getY();
};
class Rook
{
    private:
    int x;
    int y;
    void setPos(int x, int y);

    public:
    Rook(int x, int y);
    Rook Move(Board board, Rook k);
    const int getX();
    const int getY();
};
class Queen
{
    private:
    int x;
    int y;
    void setPos(int x, int y);

    public:
    Queen(int x, int y);
    Queen Move(Board board, Queen k);
    const int getX();
    const int getY();
};
