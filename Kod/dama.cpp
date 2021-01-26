#include "dama.h"

Board::Board()
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            Locations[i][j]=0;

    for (int i=0; i<4; i++)
    {
        Locations[0][i]++;
        Locations[1][i]++;
        Locations[6][i]--;
        Locations[7][i]--;
    }
}

Board::Board(const Board& b)
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            Locations[i][j]=b.Locations[i][j];
}

Board& Board::operator=(const Board& b)
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            Locations[i][j]=b.Locations[i][j];

    return *this;
}

bool Board::MovePiece(int row, int collumn, int frow, int fcollumn)
{
    if (Locations[frow][fcollumn]!=0)  return false;
    if (row<0 || row>7 || frow<0 || frow>7) return false;
    if (collumn<0 || collumn>4 || fcollumn<0 || fcollumn>4) return false;

    Locations[frow][fcollumn]=Locations[row][collumn];
    Locations[row][collumn]=0;
    return true;
}

int Board::CheckForMoves(int frow, int fcollumn, bool jumped)
{
    int counter=0;
    if (frow<0 || frow>7 || fcollumn<0 || fcollumn>3) return 0;

    if(frow%2==0) // neparni redovi
    {
        if(frow!=0) { if(Locations[frow-1][fcollumn]==0 && !jumped) // gore lijevo
        {
            Locations[frow-1][fcollumn]=2;
            counter++;
        }
        else if(frow>1 && fcollumn>0) if ((Locations[frow-1][fcollumn]==1 || Locations[frow-1][fcollumn]==-1) && Locations[frow-2][fcollumn-1]==0) // skok preko figure
        {
            Locations[frow-2][fcollumn-1]=2;
            counter++;
            counter+=CheckForMoves(frow-2, fcollumn-1, true);
        }}

        if(frow!=0 && fcollumn!=3) { if(Locations[frow-1][fcollumn+1]==0 && !jumped) // gore desno
        {
            Locations[frow-1][fcollumn+1]=2;
            counter++;
        }
        else if(frow>1) if ((Locations[frow-1][fcollumn+1]==1 || Locations[frow-1][fcollumn+1]==-1) && Locations[frow-2][fcollumn+1]==0)
        {
            Locations[frow-2][fcollumn+1]=2;
            counter++;
            counter+=CheckForMoves(frow-2, fcollumn+1, true);
        }}


        if(frow!=7) { if(Locations[frow+1][fcollumn]==0 && !jumped) // dolje lijevo
        {
            Locations[frow+1][fcollumn]=2;
            counter++;
        }
        else if(frow<6 && fcollumn>0) if ((Locations[frow+1][fcollumn]==1 || Locations[frow+1][fcollumn]==-1) && Locations[frow+2][fcollumn-1]==0)
        {
            Locations[frow+2][fcollumn-1]=2;
            counter++;
            counter+=CheckForMoves(frow+2, fcollumn-1, true);
        }}


        if(frow!=7 && fcollumn!=3) { if(Locations[frow+1][fcollumn+1]==0 && !jumped) // dolje desno
        {
            Locations[frow+1][fcollumn+1]=2;
            counter++;
        }
        else if(frow<6) if ((Locations[frow+1][fcollumn+1]==1 || Locations[frow+1][fcollumn+1]==-1) && Locations[frow+2][fcollumn+1]==0)
        {
            Locations[frow+2][fcollumn+1]=2;
            counter++;
            counter+=CheckForMoves(frow+2, fcollumn+1, true);
        }}

    }
    else // parni redovi
    {
        if(frow!=0) { if(Locations[frow-1][fcollumn]==0 && !jumped) // gore desno
        {
            Locations[frow-1][fcollumn]=2;
            counter++;
        }
        else if(frow>1 && fcollumn<3) if ((Locations[frow-1][fcollumn]==1 || Locations[frow-1][fcollumn]==-1) && Locations[frow-2][fcollumn+1]==0)
        {
            Locations[frow-2][fcollumn+1]=2;
            counter++;
            counter+=CheckForMoves(frow-2, fcollumn+1, true);
        }}


        if(frow!=0 && fcollumn!=0) { if(Locations[frow-1][fcollumn-1]==0 && !jumped) // gore lijevo
        {
            Locations[frow-1][fcollumn-1]=2;
            counter++;
        }
        else if(frow>1) if ((Locations[frow-1][fcollumn-1]==1 || Locations[frow-1][fcollumn-1]==-1) && Locations[frow-2][fcollumn-1]==0)
        {
            Locations[frow-2][fcollumn-1]=2;
            counter++;
            counter+=CheckForMoves(frow-2, fcollumn-1, true);
        }}


        if(frow!=7) { if(Locations[frow+1][fcollumn]==0 && !jumped) // dolje desno
        {
            Locations[frow+1][fcollumn]=2;
            counter++;
        }
        else if(frow<6 && fcollumn<3) if ((Locations[frow+1][fcollumn]==1 || Locations[frow+1][fcollumn]==-1) && Locations[frow+2][fcollumn+1]==0)
        {
            Locations[frow+2][fcollumn+1]=2;
            counter++;
            counter+=CheckForMoves(frow+2, fcollumn+1, true);
        }}


        if(frow!=7 && fcollumn!=0) { if(Locations[frow+1][fcollumn-1]==0 && !jumped) // dolje lijevo
        {
            Locations[frow+1][fcollumn-1]=2;
            counter++;
        }
        else if(frow<6) if ((Locations[frow+1][fcollumn-1]==1 || Locations[frow+1][fcollumn-1]==-1) && Locations[frow+2][fcollumn-1]==0)
        {
            Locations[frow+2][fcollumn-1]=2;
            counter++;
            counter+=CheckForMoves(frow+2, fcollumn-1, true);
        }}

    }
    return counter;
}

void Board::CopyTo(Board& b)
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            b.Locations[i][j]=Locations[i][j];
    return;
}

void Board::CopyFrom(Board b)
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            Locations[i][j]=b.Locations[i][j];
    return;
}

void Board::CheckForMovesAI(int frow, int fcollumn, bool jumped, int player)
{
    if(jumpcounter>=3) return;
    if(Locations[frow][fcollumn]!=player) return;
    if(!jumped) jumpcounter=0;
    if (frow<0 || frow>7 || fcollumn<0 || fcollumn>3) return;

    if(frow%2==0) // neparni redovi
    {
        if(frow!=0) { if(Locations[frow-1][fcollumn]==0 && !jumped) // gore lijevo
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow-1, fcollumn)) statecounter++;
        }
        else if(frow>1 && fcollumn>0) if ((Locations[frow-1][fcollumn]==1 || Locations[frow-1][fcollumn]==-1) && Locations[frow-2][fcollumn-1]==0) // skok preko figure
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow-2, fcollumn-1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow-2, fcollumn-1, true, player);
            }
        }}

        if(frow!=0 && fcollumn!=3) { if(Locations[frow-1][fcollumn+1]==0 && !jumped) // gore desno
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow-1, fcollumn+1)) statecounter++;
        }
        else if(frow>1) if ((Locations[frow-1][fcollumn+1]==1 || Locations[frow-1][fcollumn+1]==-1) && Locations[frow-2][fcollumn+1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow-2, fcollumn+1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow-2, fcollumn+1, true, player);
            }
        }}


        if(frow!=7) { if(Locations[frow+1][fcollumn]==0 && !jumped) // dolje lijevo
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow+1, fcollumn)) statecounter++;
        }
        else if(frow<6 && fcollumn>0) if ((Locations[frow+1][fcollumn]==1 || Locations[frow+1][fcollumn]==-1) && Locations[frow+2][fcollumn-1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow+2, fcollumn-1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow+2, fcollumn-1, true, player);
            }
        }}


        if(frow!=7 && fcollumn!=3) { if(Locations[frow+1][fcollumn+1]==0 && !jumped) // dolje desno
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow+1, fcollumn+1)) statecounter++;
        }
        else if(frow<6) if ((Locations[frow+1][fcollumn+1]==1 || Locations[frow+1][fcollumn+1]==-1) && Locations[frow+2][fcollumn+1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow+2, fcollumn+1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow+2, fcollumn+1, true, player);
            }
        } else return; }

    }
    else // parni redovi
    {
        if(frow!=0) { if(Locations[frow-1][fcollumn]==0 && !jumped) // gore desno
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow-1, fcollumn)) statecounter++;
        }
        else if(frow>1 && fcollumn<3) if ((Locations[frow-1][fcollumn]==1 || Locations[frow-1][fcollumn]==-1) && Locations[frow-2][fcollumn+1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow-2, fcollumn+1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow-2, fcollumn+1, true, player);
            }
        }}


        if(frow!=0 && fcollumn!=0) { if(Locations[frow-1][fcollumn-1]==0 && !jumped) // gore lijevo
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow-1, fcollumn-1)) statecounter++;
        }
        else if(frow>1) if ((Locations[frow-1][fcollumn-1]==1 || Locations[frow-1][fcollumn-1]==-1) && Locations[frow-2][fcollumn-1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow-2, fcollumn-1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow-2, fcollumn-1, true, player);
            }
        }}


        if(frow!=7) { if(Locations[frow+1][fcollumn]==0 && !jumped) // dolje desno
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow+1, fcollumn)) statecounter++;
        }
        else if(frow<6 && fcollumn<3) if ((Locations[frow+1][fcollumn]==1 || Locations[frow+1][fcollumn]==-1) && Locations[frow+2][fcollumn+1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow+2, fcollumn+1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow+2, fcollumn+1, true, player);
            }
        }}


        if(frow!=7 && fcollumn!=0) { if(Locations[frow+1][fcollumn-1]==0 && !jumped) // dolje lijevo
        {
            ClearMoves();
            CopyTo(States[statecounter]);
            if(States[statecounter].MovePiece(frow, fcollumn, frow+1, fcollumn-1)) statecounter++;
        }
        else if(frow<6) if ((Locations[frow+1][fcollumn-1]==1 || Locations[frow+1][fcollumn-1]==-1) && Locations[frow+2][fcollumn-1]==0)
        {
            CopyTo(States[statecounter]); States[statecounter].ClearMoves();
            if(States[statecounter].MovePiece(frow, fcollumn, frow+2, fcollumn-1))
            {
                States[statecounter].CopyTo(States[15+jumpcounter]);
                States[15+jumpcounter].Locations[frow][fcollumn]=2;
                jumpcounter++; statecounter++;
                States[15+jumpcounter-1].CheckForMovesAI(frow+2, fcollumn-1, true, player);
            }
        } else return; }

    }
    return;
}

void Board::DrawBoard()
{
    std::cout<<"\n\n";
    for (int i=0; i<4; i++)
    {
        std::cout<< "     " << (char)('a'+i*2) <<"    ";
        for (int j=0; j<4; j++)
        {
            switch(Locations[i*2][j])
            {
                case -2: std::cout<< 'U'; break;
                case -1: std::cout<< 'o'; break;
                case 0: std::cout<< '.'; break;
                case 1: std::cout<< 'x'; break;
                case 2: std::cout<< '!'; break;
                case 3: std::cout<< 'V'; break;
            };
            std::cout<<"   ";
        }
        std::cout<< std::endl << "     "  << (char)('a'+i*2+1) << "  ";
        for (int j=0; j<4; j++)
        {
            switch(Locations[i*2+1][j])
            {
                case -2: std::cout<< 'U'; break;
                case -1: std::cout<< 'o'; break;
                case 0: std::cout<< '.'; break;
                case 1: std::cout<< 'x'; break;
                case 2: std::cout<< '!'; break;
                case 3: std::cout<< 'V'; break;
            };
            std::cout<< "   ";
        }
        std::cout<< std::endl;
    }
    std::cout<< "\n\n";
    return;
}

void Board::ClearMoves()
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
        {
            if (Locations[i][j]==2) Locations[i][j]=0;
            if (Locations[i][j]==3) Locations[i][j]=1;
            if (Locations[i][j]==-2) Locations[i][j]=-1;
        }
    return;
}

Game::Game(Board fboard) : GameBoard(fboard)
{
    turn=true; fin=false; turncount=0;

    std::fstream fs;
    fs.open ("neuron.txt");
    if (fs.is_open())
    {
        fs >> AI.w1 >> AI.w2 >> AI.w3 >> AI.w4 >> AI.w5 >> AI.w6;
        fs.close();
    }
    else
    {
        AI.w1=1.0; AI.w2=1.0; AI.w3=1.0; AI.w4=1.0; AI.w5=1.0; AI.w6=1.0;
        std::cout << "Error opening file\n";
    }
}

void Game::CheckForWin()
{
    if(   GameBoard.Locations[0][0]==-1
       && GameBoard.Locations[0][1]==-1
       && GameBoard.Locations[0][2]==-1
       && GameBoard.Locations[0][3]==-1
       && GameBoard.Locations[1][0]==-1
       && GameBoard.Locations[1][1]==-1
       && GameBoard.Locations[1][2]==-1
       && GameBoard.Locations[1][3]==-1) fin = true;

    if(   GameBoard.Locations[6][0]==1
       && GameBoard.Locations[6][1]==1
       && GameBoard.Locations[6][2]==1
       && GameBoard.Locations[6][3]==1
       && GameBoard.Locations[7][0]==1
       && GameBoard.Locations[7][1]==1
       && GameBoard.Locations[7][2]==1
       && GameBoard.Locations[7][3]==1) fin = true;

    return;
}

void Game::Clear()
{
    for (int i=0; i<8; i++)
        for (int j=0; j<4; j++)
            GameBoard.Locations[i][j]=0;

    for (int i=0; i<4; i++)
    {
        GameBoard.Locations[0][i]++;
        GameBoard.Locations[1][i]++;
        GameBoard.Locations[6][i]--;
        GameBoard.Locations[7][i]--;
    }

    turn=true; fin=false; turncount=0;
    return;
}

void Neuron::Copy(Neuron& n)
{
    n.w1=w1; n.w2=w2; n.w3=w3; n.w4=w4; n.w5=w5; n.w6=w6;
}

void Game::Train()
{
    AI.Copy(Dummy[0]);
    Dummy[0].fitness=0;
    for (int i=1; i<traincount; i++)
    {
        srand(randomcounter++);
        float r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;

        /*r-=0.5;
        AI.Copy(Dummy[i]);
        switch(position) {
            case 1: Dummy[i].w1*=(1+r); break;
            case 2: Dummy[i].w2*=(1+r); break;
            case 3: Dummy[i].w3*=(1+r); break;
            case 4: Dummy[i].w4*=(1+r); break;
            case 5: Dummy[i].w5*=(1+r); break;
            case 6: Dummy[i].w6*=(1+r); break;
        }*/
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w1=r;
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w2=r;
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w3=r;
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w4=r;
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w5=r;
        r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w6=r;

        Dummy[i].fitness=0;
    }

    for (int i=0; i<traincount; i++)
        for (int j=0; j<traincount; j++)
            {
                if(j==i) j++; if(j==traincount) break;
                while(!Play(Dummy[i], Dummy[j]));
            }

    float temp=0; int index;
    for (int i=0; i<traincount; i++)
        if(Dummy[i].fitness>temp)
        {
            temp=Dummy[i].fitness;
            index=i;
        }
    if((float)Dummy[0].fitness/(float)Dummy[index].fitness < 0.85)
        Dummy[index].Copy(AI);
    else index=0;

    std::cout<<"\n";
    std::cout<<"     w1   w2   w3   w4   w5   w6    win(%)\n";
    for (int i=0; i<traincount; i++)
    {
        if(i==1) std::cout<<"=========================================\n";
        std::cout<< std::setprecision (2) << std::fixed;
        if(i<10) std::cout<<" ";
        std::cout<< i <<": " << Dummy[i].w1 << " " << Dummy[i].w2 << " " << Dummy[i].w3 << " " << Dummy[i].w4 << " " << Dummy[i].w5 << " " << Dummy[i].w6 <<" ";
        std::cout<< "| "<< (float)Dummy[i].fitness*100/(float)(traincount*2-2);
        if(i==index) std::cout<<" *\n"; else std::cout<<"\n";
    }
    std::cout<<"\n";

    std::fstream fs;
    fs.open ("neuron.txt");
    if (fs.is_open())
    {
        fs << AI.w1 << " " << AI.w2 << " " << AI.w3 << " " << AI.w4 << " " << AI.w5 << " " << AI.w6 << " ";
        fs.close();
    }
    else
    {
        std::cout << "Error opening file\n";
    }
}

void Game::Test()
{

    AI.fitness=0; int draws=0; int wins=0; float temp=AI.fitness;
    for (int i=0; i<neuroncount; i++)
    {
        srand(randomcounter++);
        float r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;

        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w1=r;
        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w2=r;
        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w3=r;
        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w4=r;
        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w5=r;
        r = static_cast<float> (rand())/ static_cast<float> (RAND_MAX); r*=2;
        Dummy[i].w6=r;

        Dummy[i].fitness=0;

        if (i<=neuroncount/2) while(!Play(AI, Dummy[i]));
        else while(!Play(Dummy[i], AI));
        if (AI.fitness!=temp && AI.fitness!=temp+1) draws++;
        else if(AI.fitness==temp+1) wins++;
        temp=AI.fitness;
    }
    AI.draws=draws;
    AI.wins=wins;
}

bool Game::Play(Neuron& p1, Neuron& p2)
{
    p1.player=-1; p2.player=1;
    CheckForWin();
    if(fin)
    {
        //std::cout <<"\nGame Over!";
        if(turn)
        {
            //std::cout<< "p2 (x) won on turn "<< turncount <<"\n";
            p2.fitness++;
        }
        else
        {
            //std::cout<< "p1 (o) won on turn "<< turncount <<"\n";
            p1.fitness++;
        }
        //std::cout<< "\n";
        //GameBoard.DrawBoard();
        //std::cout<< p1.w1 << " " << p1.w2 << " " << p1.w3 << " " << p1.w4 << " " << p1.w5 << " " << p1.w6 << "  vs  ";
        //std::cout<< p2.w1 << " " << p2.w2 << " " << p2.w3 << " " << p2.w4 << " " << p2.w5 << " " << p2.w6 << "\n";
        Clear();
        return true;
    }
    if(turncount==100)
    {
        //std::cout <<"Game Over! 200 turns have passed.\n";
        //std::cout<< "\n";
        p1.evaluate(GameBoard); float temp=score;
        p2.evaluate(GameBoard);
        if (temp>score) p1.fitness++;
        if (temp<score) p2.fitness++;
        if (temp==score) { p1.fitness+=0.5; p2.fitness+=0.5; }
        //GameBoard.DrawBoard();
        //std::cout<< p1.w1 << " " << p1.w2 << " " << p1.w3 << " " << p1.w4 << " " << p1.w5 << " " << p1.w6 << "  vs  ";
        //std::cout<< p2.w1 << " " << p2.w2 << " " << p2.w3 << " " << p2.w4 << " " << p2.w5 << " " << p2.w6 << "\n";
        Clear();
        return true;
    }

    if(turn)
    {
        GameBoard.ClearMoves();
        Board bestboard;
        float bestvalue=-1000000;
        for (int i=0; i<8; i++)
            for (int j=0; j<4; j++)
                {
                    statecounter=0; jumpcounter=0;
                    ClearStatesWith(GameBoard);
                    GameBoard.CheckForMovesAI(i, j, false, p1.player);
                    for (int i=0; i<statecounter; i++)
                        {
                            p1.player=-1;
                            float temp=p1.evaluate(States[i]);
                            if(temp>bestvalue)
                            {
                                bestvalue=temp;
                                bestboard.CopyFrom(States[i]);
                            }
                        }
                }
        GameBoard.CopyFrom(bestboard);
    }
    else
    {
        GameBoard.ClearMoves();
        Board bestboard;
        float bestvalue=-1000000;
        for (int i=0; i<8; i++)
            for (int j=0; j<4; j++)
                {
                    statecounter=0; jumpcounter=0;
                    ClearStatesWith(GameBoard);
                    GameBoard.CheckForMovesAI(i, j, false, p2.player);
                    for (int i=0; i<statecounter; i++)
                        {
                            p2.player=1;
                            float temp=p2.evaluate(States[i]);
                            if(temp>bestvalue)
                            {
                                bestvalue=temp;
                                bestboard.CopyFrom(States[i]);
                            }
                        }
                }
        GameBoard.CopyFrom(bestboard);
    }

    turncount++;
    turn=!turn;
    return false;
}

void ClearStatesWith(Board b)
{
    for (int i=0; i<32; i++) States[i].CopyFrom(b);
    return;
}

bool Game::MakeMove()
{
    std::string oppNAME="Chad";
    CheckForWin();
    if(fin)
    {
        std::cout <<"\nGame Over!";
        if(turn) std::cout<< "\nChad won on turn "<< turncount;
        else std::cout<< "\n" << playerNAME << " won on turn"<< turncount;
        std::cout<< "\n\n";
        return true;
        Clear();
    }
    if(turncount==150)
    {
        std::cout <<"\nGame Over! 150 turns have passed.";
        std::cout<< "\n\n";
        Clear();
        return true;
    }

    char row, row1; int collumn, collumn1;
    if(turn)
    {
        if(turncount==0)
        {
            std::cout<<"Write your NAME here: ";
            std::cin>> playerNAME;
            if(playerNAME=="x") return true;
            std::cout<<"Hi " << playerNAME << ", the game is about to start. Good luck!\n";
        }

        GameBoard.ClearMoves();
        GameBoard.DrawBoard();
        turncount++;
        std::cout<<"\n" << playerNAME << " VS " << oppNAME << "  turn: " << turncount <<"\nYour turn! Pick a circle. ";

        int check=0;
        while(1 && !check)
        {
            std::cin>> row;     if (row=='x') { Clear(); return true; }
            std::cin>> collumn;


            if (row<'a' || row>'h' || collumn<1 || collumn>4)std::cout<< "Wrong input! "; else
            if (GameBoard.Locations[(int)(row-'a')][collumn-1]!=-1) std::cout<< "That's not a circle! ";
            else
            {
                GameBoard.Locations[(int)(row-'a')][collumn-1]--;
                int counter=GameBoard.CheckForMoves((int)(row-'a'), collumn-1, false);
                if(counter!=0)
                {
                    GameBoard.DrawBoard();
                    std::cout<< "\nYou picked " << row << collumn << "\nPick an exclamation point (!) to make your move. ";
                    while(1)
                    {
                        row1='a'-1;
                        collumn1=1;
                        std::cin>> row1; if (row1=='x') { Clear(); return true; }
                        std::cin>> collumn1;

                        if (row1<'a' || row1>'h' || collumn1<1 || collumn1>4) std::cout<< "Wrong input! "; else
                        if (GameBoard.Locations[(int)(row1-'a')][collumn1-1]!=2) std::cout<< "That's not an exclamation point! ";
                        else
                        {
                            GameBoard.Locations[(int)(row-'a')][collumn-1]=0;
                            GameBoard.Locations[(int)(row1-'a')][collumn1-1]=-1;
                            GameBoard.ClearMoves();
                            check++;
                            break;
                        }
                    }
                }
                else
                {
                    GameBoard.ClearMoves();
                    std::cout<< "That circle cannot move this turn, pick another one. ";
                }
            }
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

    }
    if(!turn)
    {
        GameBoard.ClearMoves();
        Board bestboard;
        float bestvalue=-1000000;
        for (int i=0; i<8; i++)
            for (int j=0; j<4; j++)
                if (GameBoard.Locations[i][j]==1)
                {
                    statecounter=0; jumpcounter=0;
                    ClearStatesWith(GameBoard);
                    GameBoard.CheckForMovesAI(i, j, false, 1);
                    for (int i=0; i<statecounter; i++)
                    {
                        AI.player=1;
                        float temp=AI.evaluate(States[i]);
                        if(temp>bestvalue)
                        {
                            bestvalue=temp;
                            bestboard.CopyFrom(States[i]);
                        }
                    }

                }

            GameBoard.CopyFrom(bestboard);
            for (int i=0; i<3; i++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout<<".";
            }
    }
    turn=!turn;
    return false;
}

float Neuron::evaluate(Board state)
{
    float x1=0; // kumulativna udaljenost od vlastitog prvog reda
    float x2=0; // kumulativna udaljenost od protivnikovog prvog reda
    float x3=0; // broj vlastitih figura koje mogu napraviti skok
    float x4=0; // broj protivnikovih figura koje mogu napraviti skok
    float x5=0; // broj vlastitih figura na krajnjoj poziciji
    float x6=0; // broj protivnikovih figura na krajnjoj poziciji

    for (int frow=0; frow<8; frow++)
        for (int fcollumn=0; fcollumn<4; fcollumn++)
            {
                if (state.Locations[frow][fcollumn]==player)
                {
                    if (player==1) x1+=frow;
                    else x1+=7-frow;

                    if (frow%2==0)
                    {
                        if(frow>1 && fcollumn>0) if ((state.Locations[frow-1][fcollumn]==1 || state.Locations[frow-1][fcollumn]==-1) && state.Locations[frow-2][fcollumn-1]==0) x3++;
                        if(frow>1) if ((state.Locations[frow-1][fcollumn+1]==1 || state.Locations[frow-1][fcollumn+1]==-1) && state.Locations[frow-2][fcollumn+1]==0) x3++;
                        if(frow<6 && fcollumn>0) if ((state.Locations[frow+1][fcollumn]==1 || state.Locations[frow+1][fcollumn]==-1) && state.Locations[frow+2][fcollumn-1]==0) x3++;
                        if(frow<6) if ((state.Locations[frow+1][fcollumn+1]==1 || state.Locations[frow+1][fcollumn+1]==-1) && state.Locations[frow+2][fcollumn+1]==0) x3++;
                    }
                    else
                    {
                        if(frow>1 && fcollumn<3) if ((state.Locations[frow-1][fcollumn]==1 || state.Locations[frow-1][fcollumn]==-1) && state.Locations[frow-2][fcollumn+1]==0) x3++;
                        if(frow>1) if ((state.Locations[frow-1][fcollumn-1]==1 || state.Locations[frow-1][fcollumn-1]==-1) && state.Locations[frow-2][fcollumn-1]==0) x3++;
                        if(frow<6 && fcollumn<3) if ((state.Locations[frow+1][fcollumn]==1 || state.Locations[frow+1][fcollumn]==-1) && state.Locations[frow+2][fcollumn+1]==0) x3++;
                        if(frow<6) if ((state.Locations[frow+1][fcollumn-1]==1 || state.Locations[frow+1][fcollumn-1]==-1) && state.Locations[frow+2][fcollumn-1]==0) x3++;
                    }

                    if (player==1 && frow==7) x5++;
                    if (player==1 && frow==6
                     && state.Locations[7][0]==player
                     && state.Locations[7][1]==player
                     && state.Locations[7][2]==player
                     && state.Locations[7][3]==player) x5++;

                    if (player==-1 && frow==0) x5++;
                    if (player==-1 && frow==1
                     && state.Locations[0][0]==player
                     && state.Locations[0][1]==player
                     && state.Locations[0][2]==player
                     && state.Locations[0][3]==player) x5++;

                }
                if (state.Locations[frow][fcollumn]==-player)
                {
                    if (-player==1) x2+=frow;
                    else x2+=7-frow;

                    if (frow%2==0)
                    {
                        if(frow>1 && fcollumn>0) if ((state.Locations[frow-1][fcollumn]==1 || state.Locations[frow-1][fcollumn]==-1) && state.Locations[frow-2][fcollumn-1]==0) x4++;
                        if(frow>1) if ((state.Locations[frow-1][fcollumn+1]==1 || state.Locations[frow-1][fcollumn+1]==-1) && state.Locations[frow-2][fcollumn+1]==0) x4++;
                        if(frow<6 && fcollumn>0) if ((state.Locations[frow+1][fcollumn]==1 || state.Locations[frow+1][fcollumn]==-1) && state.Locations[frow+2][fcollumn-1]==0) x4++;
                        if(frow<6) if ((state.Locations[frow+1][fcollumn+1]==1 || state.Locations[frow+1][fcollumn+1]==-1) && state.Locations[frow+2][fcollumn+1]==0) x4++;
                    }
                    else
                    {
                        if(frow>1 && fcollumn<3) if ((state.Locations[frow-1][fcollumn]==1 || state.Locations[frow-1][fcollumn]==-1) && state.Locations[frow-2][fcollumn+1]==0) x4++;
                        if(frow>1) if ((state.Locations[frow-1][fcollumn-1]==1 || state.Locations[frow-1][fcollumn-1]==-1) && state.Locations[frow-2][fcollumn-1]==0) x4++;
                        if(frow<6 && fcollumn<3) if ((state.Locations[frow+1][fcollumn]==1 || state.Locations[frow+1][fcollumn]==-1) && state.Locations[frow+2][fcollumn+1]==0) x4++;
                        if(frow<6) if ((state.Locations[frow+1][fcollumn-1]==1 || state.Locations[frow+1][fcollumn-1]==-1) && state.Locations[frow+2][fcollumn-1]==0) x4++;
                    }

                    if (-player==1 && frow==7) x6++;
                    if (-player==1 && frow==6
                     && state.Locations[7][0]==-player
                     && state.Locations[7][1]==-player
                     && state.Locations[7][2]==-player
                     && state.Locations[7][3]==-player) x6++;

                    if (-player==-1 && frow==0) x6++;
                    if (-player==-1 && frow==1
                     && state.Locations[0][0]==-player
                     && state.Locations[0][1]==-player
                     && state.Locations[0][2]==-player
                     && state.Locations[0][3]==-player) x6++;
                }
            }
    score=x1;
    return (x1*w1-x2*w2+x3*w3-x4*w4+x5*w5-x6*w6);
}

void Game::Start()
{
    char c='a';
    while(c!='x')
    {
        std::cout<<"\n  write r to train\n  write t to test\n  write x to exit\n  write p to play\n                               ";
        std::cin>>c;
        if(c=='t')
        {
            std::cout<<"\nhow many times? ";
            int i; std::cin>> i;
            if(i>50) i=50;
            std::cout<<"  Win   Lose   Draw\n";
            for (int j=0; j<i; j++)
            {
                Test();

                if(AI.wins<100) std::cout<<" "; if(AI.wins<10) std::cout<<" ";
                std::cout<<"  "<<AI.wins<<"    ";
                if(neuroncount-AI.wins-AI.draws<100) std::cout<<" "; if(neuroncount-AI.wins-AI.draws<10) std::cout<<" ";
                std::cout<<neuroncount-AI.wins-AI.draws<<"    ";
                if(AI.draws<100) std::cout<<" "; if(AI.draws<10) std::cout<<" ";
                std::cout<<AI.draws<<"   "<<AI.fitness<<"\n";
            }
        }
        if(c=='r')
        {
            std::cout<<"\nhow many times? ";
            int i; std::cin>> i;
            if(i>10) i=10;
            for (int j=0; j<i; j++) Train();
        }
        if(c=='p') while(!MakeMove());
    }
}
