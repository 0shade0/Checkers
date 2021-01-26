#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <time.h>

static unsigned int randomcounter=time(0);
const int neuroncount=100;
const int traincount=15;

class Board {
public:
    Board();
    Board(const Board &b);
    Board& operator=(const Board& b);
    ~Board() {}

    int Locations[8][4];

    void DrawBoard();
    int CheckForMoves(int frow, int fcollumn, bool jumped);
    void CheckForMovesAI(int frow, int fcollumn, bool jumped, int player);
    bool MovePiece(int row, int collumn, int frow, int fcollumn);
    void ClearMoves();
    void CopyTo(Board& b);
    void CopyFrom(Board b);
};

class Neuron {
    friend class Game;
    float w1, w2, w3, w4, w5, w6;
    int player;
    float fitness;
    int draws;
    int wins;

public:
    Neuron() {}
    ~Neuron() {}

    float evaluate(Board state);
    void Copy(Neuron& n);
};

static int score=0;
static Neuron Dummy[neuroncount];
static Board States[32];
static int jumpcounter=0;
static int statecounter=0;
void ClearStatesWith(Board b);
void FillNeurons();


class Game {
    Board GameBoard;

    int turncount;
    bool turn;
    bool fin;
    std::string playerNAME;

    void CheckForWin();
    void Clear();

public:
    Game(Board fboard);
    ~Game() {};

    Neuron AI;
    bool MakeMove();
    bool Play(Neuron& p1, Neuron& p2);

    void Train();
    void Test();

    void Start();
};
