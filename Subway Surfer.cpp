#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <ctime>
using namespace std;
// Declare the position of character at start
int positionC = 20;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Show the GAME OVER at end
void gameOver()
{
    system("cls");
    gotoxy(4, 8);
    string gameOver[] = {
        " _________         __       ___          ___  _______         ________                   _______     ________ ",
        "    / ________|       //\\\\      ||\\\\        //|| ||______|       / _______\\  ||          || ||______|   ||_______\\ ",
        "   | |               //  \\\\     || \\\\      // || ||              | |      || ||          || ||          ||       || ",
        "   | |              //    \\\\    ||  \\\\    //  || ||______        | |      || \\\\          // ||______    ||       ||",
        "   | |             //______\\\\   ||   \\\\  //   || ||______|       | |      ||  \\\\        //  ||______|   ||______// ",
        "   | |   ______   //________\\\\  ||    \\\\//    || ||              | |      ||   \\\\      //   ||          ||______/  ",
        "   | |    |   ||  ||        ||  ||            || ||              | |      ||    \\\\    //    ||          ||    \\\\    ",
        "   | |____|   ||  ||        ||  ||            || ||______        | |______||     \\\\  //     ||______    ||     \\\\   ",
        "    \\_____|   ||  ||        ||  ||            || ||______|        \\_______/       \\\\//      ||______|   ||      \\\\"};

    for (int i = 0; i < sizeof(gameOver) / sizeof(gameOver[0]); i++)
    {
        cout << gameOver[i] << endl;
    }
}
// Instructions for playing game
class Information
{
public:
    void call()
    {
        gotoxy(41, 7);
        cout << " _______________________________________" << endl;
        gotoxy(41, 8);
        cout << "|                                       |" << endl;
        gotoxy(41, 9);
        cout << "|        UP      :       UP_KEY         |" << endl;
        gotoxy(41, 10);
        cout << "|        DOWN    :       DOWN_KEY       |" << endl;
        gotoxy(41, 11);
        cout << "|        LEFT    :       LEFT_KEY       |" << endl;
        gotoxy(41, 12);
        cout << "|        RIGHT   :       RIGHT_KEY      |" << endl;
        gotoxy(41, 13);
        cout << "|                                       |" << endl;
        gotoxy(41, 14);
        cout << "|           Enter To Continue           |" << endl;
        gotoxy(41, 15);
        cout << "|_______________________________________|" << endl;
    }
};
// Showing Score with the continuation of game
class Score
{
public:
    int sc;

    score()
    {
        sc = 0;
    }
    void increaseScore()
    {
        sc += 2;
    }

    void displayScore()
    {
        gotoxy(105, 1);
        cout << "Score : " << sc << endl;
    }
};
// Draw the path of the game
class Way
{
public:
    void path()
    {
        int i, j, n = 26;
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= 40 - i; j++)
            {
                cout << " ";
            }
            cout << "   /     ";
            for (j = 0; j <= 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "                       \\" << endl;
        }
    }
};
// Draw the character looks like running with continuous calling drawL & drawR
class Character
{
public:
    void moveRight()
    {
        if (positionC < 40)
            positionC = positionC + 20;
    }
    void moveLeft()
    {
        if (positionC > 0)
            positionC = positionC - 20;
    }
    void drawL()
    {

        gotoxy(positionC, 20);
        cout << "                                     ____             " << endl;
        gotoxy(positionC, 21);
        cout << "                                    /    \\           " << endl;
        gotoxy(positionC, 22);
        cout << "                                   (_...._)           " << endl;
        gotoxy(positionC, 23);
        cout << "                              <>  ___|  |___          " << endl;
        gotoxy(positionC, 24);
        cout << "                                \\/|        |\\        " << endl;
        gotoxy(positionC, 25);
        cout << "                                   \\______/  )       " << endl;
        gotoxy(positionC, 26);
        cout << "                                    |    |   <>       " << endl;
        gotoxy(positionC, 27);
        cout << "                                    |    O          " << endl;
        gotoxy(positionC, 28);
        cout << "                                    O               " << endl;
    }
    void drawR()
    {
        gotoxy(positionC, 20);
        cout << "                                     ____             " << endl;
        gotoxy(positionC, 21);
        cout << "                                    /    \\           " << endl;
        gotoxy(positionC, 22);
        cout << "                                   (_...._)           " << endl;
        gotoxy(positionC, 23);
        cout << "                                  ___|  |___ <>       " << endl;
        gotoxy(positionC, 24);
        cout << "                                 /|        |\\/       " << endl;
        gotoxy(positionC, 25);
        cout << "                                (  \\______/          " << endl;
        gotoxy(positionC, 26);
        cout << "                                <>  |    |            " << endl;
        gotoxy(positionC, 27);
        cout << "                                    O    |            " << endl;
        gotoxy(positionC, 28);
        cout << "                                         O            " << endl;
    }
    // Character moving Up
    void drawU()
    {
        gotoxy(positionC, 15);
        cout << "                                     ____             " << endl;
        gotoxy(positionC, 16);
        cout << "                                    /    \\           " << endl;
        gotoxy(positionC, 17);
        cout << "                                   (_...._)           " << endl;
        gotoxy(positionC, 18);
        cout << "                                <>___|  |___<>        " << endl;
        gotoxy(positionC, 19);
        cout << "                                 \\|        |/        " << endl;
        gotoxy(positionC, 20);
        cout << "                                   \\______/          " << endl;
        gotoxy(positionC, 21);
        cout << "                                    |    |            " << endl;
        gotoxy(positionC, 22);
        cout << "                                    O    O            " << endl;
    }
    // Character moving Down
    void drawD()
    {
        gotoxy(positionC, 23);
        cout << "                                     ____             " << endl;
        gotoxy(positionC, 24);
        cout << "                                   (_...._)           " << endl;
        gotoxy(positionC, 25);
        cout << "                                 <>__|  |__>          " << endl;
        gotoxy(positionC, 26);
        cout << "                                   \\______/          " << endl;
        gotoxy(positionC, 27);
        cout << "                                    |    |            " << endl;
        gotoxy(positionC, 28);
        cout << "                                    O    O            " << endl;
    }
    // Character with Magnet
    void drawM()
    {
        gotoxy(positionC, 20);
        cout << "                                     ____                  " << endl;
        gotoxy(positionC, 21);
        cout << "                                    /    \\                " << endl;
        gotoxy(positionC, 22);
        cout << "                                   (_...._) ||  ||         " << endl;
        gotoxy(positionC, 23);
        cout << "                                  ___|  |___||__||         " << endl;
        gotoxy(positionC, 24);
        cout << "                                 /|        | \\\__/        " << endl;
        gotoxy(positionC, 25);
        cout << "                                (  \\______/               " << endl;
        gotoxy(positionC, 26);
        cout << "                                <>  |    |                 " << endl;
        gotoxy(positionC, 27);
        cout << "                                    |    |                 " << endl;
        gotoxy(positionC, 28);
        cout << "                                    O    O                 " << endl;
    }
};
// Pickup items movement from left,mid and right way from up to downward
class Items
{
public:
    int positionL, positionM, positionR, y;
    Items(int xs, int ys)
    {
        positionL = xs;
        positionM = xs;
        positionR = xs;
        y = ys;
    }
    void moveLeft()
    {
        if (y <= 22)
        {
            y += 1;
            if (y += 1)
            {
                positionL -= 2;
            }
        }
    }
    void moveMid()
    {
        if (y <= 22)
            y += 2;
    }

    void moveRight()
    {
        if (y <= 22)
        {
            y += 1;
            if (y += 1)
            {
                positionR += 2;
            }
        }
    }
    // Moving coins towards the character while having Magnet
    void moveMagLeft()
    {
        if (positionC == 40 && y <= 22)
        {
            y += 1;
            positionL -= 1;
            if (y > 9)
                positionL += 3;
        }

        if (positionC == 20 && y <= 22)
        {
            y += 1;
            positionL -= 2;
            if (y > 10)
                positionL += 4;
        }

        if (positionC == 0 && y <= 22)
        {
            y += 1;
            if (y += 1)
                positionL -= 2;
        }
    }

    void moveMagMid()
    {

        if (positionC == 40 && y <= 22)
        {
            y += 1;
            if (y > 9)
                positionM += 2;
        }

        if (positionC == 20 && y <= 22)
            y += 1;

        if (positionC == 0 && y <= 22)
        {
            y += 1;
            if (y > 10)
            {
                positionM -= 2;
            }
        }
    }

    void moveMagRight()
    {
        if (positionC == 40 && y <= 22)
        {
            y += 1;
            if (y += 1)
                positionR += 2;
        }

        if (positionC == 20 && y <= 22)
        {
            y += 1;
            positionR += 2;
            if (y > 10)
                positionR -= 4;
        }

        if (positionC == 0 && y <= 22)
        {
            y += 1;
            positionR += 1;
            if (y > 12)
                positionR -= 5;
        }
    }
};
// Derived coin class from item class for coins movement
class Coin : public Items
{
public:
    Coin(int xs, int ys) : Items(xs, ys)
    {
    }
    // Coins at left
    void coin1()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionL, y);
        cout << "     ___        " << endl;
        gotoxy(positionL, y + 1);
        cout << "    /:::\\       " << endl;
        gotoxy(positionL, y + 2);
        cout << "    \\___/       " << endl;
        gotoxy(positionL, y + 3);
        cout << "                " << endl;
    }
    // Coins at mid
    void coin2()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionM, y);
        cout << "     ___        " << endl;
        gotoxy(positionM, y + 1);
        cout << "    /:::\\       " << endl;
        gotoxy(positionM, y + 2);
        cout << "    \\___/       " << endl;
        gotoxy(positionM, y + 3);
        cout << "                " << endl;
    }
    // Coind at right
    void coin3()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionR, y);
        cout << "     ___        " << endl;
        gotoxy(positionR, y + 1);
        cout << "    /:::\\       " << endl;
        gotoxy(positionR, y + 2);
        cout << "    \\___/       " << endl;
        gotoxy(positionR, y + 3);
        cout << "                " << endl;
    }
};
// Derived magnet class from item class for magnet movement
class Magnet : public Items
{
public:
    int positionMag;
    clock_t startTime;
    bool draw5Active; // State variable to control draw5

    Magnet(int xs, int ys) : Items(xs, ys)
    {
        positionMag = xs;
        startTime = clock();
        draw5Active = false; // Initialize draw5 state to false
    }

    void mag()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionMag, y);
        cout << "                 " << endl;
        gotoxy(positionMag, y + 1);
        cout << "      ||     ||        " << endl;
        gotoxy(positionMag, y + 2);
        cout << "      ||     ||        " << endl;
        gotoxy(positionMag, y + 3);
        cout << "      ||     ||        " << endl;
        gotoxy(positionMag, y + 4);
        cout << "      ||_____||        " << endl;
        gotoxy(positionMag, y + 5);
        cout << "       \\_____/        " << endl;
    }
};
// Hurdles
class UpperBarrier : public Items
{
public:
    UpperBarrier(int xs, int ys) : Items(xs, ys)
    {
    }
    void upperBarrier1()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionL, y);
        cout << "      ________     " << endl;
        gotoxy(positionL, y + 1);
        cout << "     /|<<-->>|\\    " << endl;
        gotoxy(positionL, y + 2);
        cout << "     ||------||   " << endl;
        gotoxy(positionL, y + 3);
        cout << "     ||      ||    " << endl;
        gotoxy(positionL, y + 4);
        cout << "     ||      ||    " << endl;
        gotoxy(positionL, y + 5);
        cout << "             ||    " << endl;
    }

    void upperBarrier2()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionM, y);
        cout << "      ________     " << endl;
        gotoxy(positionM, y + 1);
        cout << "     /|<<-->>|\\    " << endl;
        gotoxy(positionM, y + 2);
        cout << "     ||------||   " << endl;
        gotoxy(positionM, y + 3);
        cout << "     ||      ||    " << endl;
        gotoxy(positionM, y + 4);
        cout << "     ||      ||    " << endl;
        gotoxy(positionM, y + 5);
        cout << "     ||      ||    " << endl;
    }

    void upperBarrier3()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionR, y);
        cout << "      ________     " << endl;
        gotoxy(positionR, y + 1);
        cout << "     /|<<-->>|\\    " << endl;
        gotoxy(positionR, y + 2);
        cout << "     ||------||      " << endl;
        gotoxy(positionR, y + 3);
        cout << "     ||      ||    " << endl;
        gotoxy(positionR, y + 4);
        cout << "     ||      ||    " << endl;
        gotoxy(positionR, y + 5);
        cout << "     ||            " << endl;
    }
};
// Hurdles
class LowerBarrier : public Items
{
public:
    LowerBarrier(int xs, int ys) : Items(xs, ys)
    {
    }
    void lowerBarrier1()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionL, y);
        cout << "      _______     " << endl;
        gotoxy(positionL, y + 1);
        cout << "     /|<<->>|\\    " << endl;
        gotoxy(positionL, y + 2);
        cout << "     ||<<->>||   " << endl;
        gotoxy(positionL, y + 3);
        cout << "       -----||    " << endl;
    }

    void lowerBarrier2()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionM, y);
        cout << "      _______     " << endl;
        gotoxy(positionM, y + 1);
        cout << "     /|<<->>|\\    " << endl;
        gotoxy(positionM, y + 2);
        cout << "     ||<<->>||   " << endl;
        gotoxy(positionM, y + 3);
        cout << "     ||-----||    " << endl;
    }
    void lowerBarrier3()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionR, y);
        cout << "      _______     " << endl;
        gotoxy(positionR, y + 1);
        cout << "     /|<<->>|\\    " << endl;
        gotoxy(positionR, y + 2);
        cout << "     ||<<->>||   " << endl;
        gotoxy(positionR, y + 3);
        cout << "     ||-----      " << endl;
    }
};
// Hurdles
class Train : public Items
{
public:
    Train(int xs, int ys) : Items(xs, ys)
    {
    }
    void train1()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionL, y);
        cout << "           <----->        " << endl;
        gotoxy(positionL, y + 1);
        cout << "          ///////        " << endl;
        gotoxy(positionL, y + 2);
        cout << "         ///////         " << endl;
        gotoxy(positionL, y + 3);
        cout << "        ///////          " << endl;
        gotoxy(positionL, y + 4);
        cout << "       ///////           " << endl;
        gotoxy(positionL, y + 5);
        cout << "      <----->           " << endl;
    }

    void train2()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionM, y);
        cout << "         <----->        " << endl;
        gotoxy(positionM, y + 1);
        cout << "         |||||||      " << endl;
        gotoxy(positionM, y + 2);
        cout << "         |||||||         " << endl;
        gotoxy(positionM, y + 3);
        cout << "         |||||||          " << endl;
        gotoxy(positionM, y + 4);
        cout << "         |||||||           " << endl;
        gotoxy(positionM, y + 5);
        cout << "         <----->           " << endl;
    }

    void train3()
    {
        if (y >= 21)
        {
            return;
        }
        gotoxy(positionR, y);
        cout << "         <----->        " << endl;
        gotoxy(positionR, y + 1);
        cout << "          \\\\\\\\\\\\\\       " << endl;
        gotoxy(positionR, y + 2);
        cout << "           \\\\\\\\\\\\\\      " << endl;
        gotoxy(positionR, y + 3);
        cout << "            \\\\\\\\\\\\\\     " << endl;
        gotoxy(positionR, y + 4);
        cout << "             \\\\\\\\\\\\\\   " << endl;
        gotoxy(positionR, y + 5);
        cout << "              <----->   " << endl;
    }
};
// Movement of the character
class MovementHandler
{
public:
    static void processInput(Character &c)
    {
        if (kbhit())
        {
            int key = getch();
            if (key == 224)
            {
                key = getch();
                switch (key)
                {
                case 77: // Right arrow
                    c.moveRight();
                    break;
                case 75: // Left arrow
                    c.moveLeft();
                    break;
                case 72: // Up arrow
                    for (int i = 0; i <= 200; i++)
                        c.drawU();
                    system("cls");
                    break;
                case 80: // Down arrow
                    for (int i = 0; i <= 200; i++)
                        c.drawD();
                    system("cls");
                    break;
                }
            }
        }
    }
};
int main()
{
    int coinsCollected = 0;
    int count = 1;

    bool conditionMet = false; // This flag will indicate when the 'else if' condition is met
    time_t startTime = 0;      // To keep track of when the 'else if' condition is first met
    // Making objects
    Score s;
    Way w;
    Character c;
    Information info;

    info.call();

    // Press Enter to continue
    while (true)
    {
        if (_kbhit())
        {
            if (_getch() == 13)
            {
                break;
            }
        }
    }
    // Setting positions of coins and the Hurdles
    Coin c1(49, 0), c2(49, 0), c3(49, 0);
    Coin c4(52, 0), c5(52, 0), c6(52, 0);
    Coin c7(54, 0), c8(54, 0), c9(54, 0);

    UpperBarrier u1(47, 0);
    UpperBarrier u2(49, 0);
    UpperBarrier u3(55, 0);

    LowerBarrier l1(47, 0);
    LowerBarrier l2(50, 0);
    LowerBarrier l3(55, 0);

    Train t1(42, 0);
    Train t2(46, 0);
    Train t3(48, 0);

    Magnet m(49, 0);
    // Game continue in infinite loop until character hits a Hurdle
    while (true)
    {

        system("cls");
        w.path();
        s.displayScore();
        s.increaseScore();
        s.displayScore();
        // Collecting the pick up Coins at topRight
        gotoxy(104, 2);
        cout << " COINS: " << coinsCollected;
        count += 1;

        if (count > 65 && count <= 85)
        {
            m.mag();
            m.moveMid();
        }

        if (count > 5 && count <= 20)
        {
            c1.coin1();
            c1.moveLeft();
            if (c1.y == 20 && positionC == 0)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }

            if (c1.y >= 5)
            {
                c2.coin1();
                c2.moveLeft();
                if (c2.y == 20 && positionC == 0)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
            if (c2.y >= 5)
            {
                c3.coin1();
                c3.moveLeft();
                if (c3.y == 20 && positionC == 0)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
        }
        if (count > 15 && count <= 30)
        {
            c4.coin2();
            c4.moveMid();
            if (c4.y == 20 && positionC == 20)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }

            if (c4.y >= 5)
            {
                c5.coin2();
                c5.moveMid();
                if (c5.y == 20 && positionC == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }

            if (c5.y >= 5)
            {
                c6.coin2();
                c6.moveMid();
                if (c6.y == 20 && positionC == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
        }
        if (count > 60 && count <= 75)
        {
            c7.coin3();
            c7.moveRight();
            if (c7.y == 20 && positionC == 40)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }

            if (c7.y >= 5)
            {
                c8.coin3();
                c8.moveRight();
                if (c8.y == 20 && positionC == 40)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }

            if (c8.y >= 5)
            {
                c9.coin3();
                c9.moveRight();
                if (c9.y == 20 && positionC == 40)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
        }

        // This is for magnet

        if (count > 85 && count <= 115)
        {
            c1.coin1();
            c1.moveMagLeft();
            if (c1.y == 20)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }
            if (c1.y >= 5)
            {
                c2.coin1();
                c2.moveMagLeft();
                if (c2.y == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
            if (c2.y >= 5)
            {
                c3.coin1();
                c3.moveMagLeft();
                if (c3.y == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }

            c4.coin2();
            c4.moveMagMid();
            if (c4.y == 21)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }

            if (c4.y >= 5)
            {
                c5.coin2();
                c5.moveMagMid();
                if (c5.y == 21)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }

            if (c5.y >= 5)
            {
                c6.coin2();
                c6.moveMagMid();
                if (c6.y == 21)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
            c7.coin3();
            c7.moveMagRight();
            if (c7.y == 20)
            {
                gotoxy(104, 2);
                coinsCollected += 1;
                cout << " COINS: " << coinsCollected;
            }

            if (c7.y >= 5)
            {
                c8.coin3();
                c8.moveMagRight();
                if (c8.y == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }

            if (c8.y >= 5)
            {
                c9.coin3();
                c9.moveMagRight();
                if (c9.y == 20)
                {
                    gotoxy(104, 2);
                    coinsCollected += 1;
                    cout << " COINS: " << coinsCollected;
                }
            }
        }

        if (count > 40 && count <= 55)
        {
            u1.upperBarrier1();
            u1.moveLeft();
            if (u1.y < 22 && positionC == 0)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (u1.y >= 19)
                    {
                        if ((!kbhit()) && (u1.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c); // Use MovementHandler to process input
                }
            }
        }

        if (count > 25 && count <= 45)
        {
            u2.upperBarrier2();
            u2.moveMid();
            if (u2.y < 22 && positionC == 20)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (u2.y >= 19)
                    {
                        if ((!kbhit()) && (u2.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 20 && count <= 35)
        {
            u3.upperBarrier3();
            u3.moveRight();
            if (u3.y < 22 && positionC == 40)
            {
                Sleep(40);

                if (!kbhit())
                {
                    if (u3.y >= 19)
                    {
                        if ((!kbhit()) && (u3.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 30 && count <= 45)
        {
            l1.lowerBarrier1();
            l1.moveLeft();
            if (l1.y < 22 && positionC == 0)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (l1.y >= 19)
                    {
                        if ((!kbhit()) && (l1.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 45 && count <= 65)
        {
            l2.lowerBarrier2();
            l2.moveMid();
            if (l2.y < 22 && positionC == 20)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (l2.y >= 19)
                    {
                        if ((!kbhit()) && (l2.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 50 && count <= 65)
        {
            l3.lowerBarrier3();
            l3.moveRight();
            if (l3.y < 22 && positionC == 40)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (l3.y >= 19)
                    {
                        if ((!kbhit()) && (l3.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 50 && count <= 65)
        {
            t1.train1();
            t1.moveLeft();
            if (t1.y < 22 && positionC == 0)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (t1.y >= 19)
                    {
                        if ((!kbhit()) && (t1.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 55 && count <= 75)
        {
            t2.train2();
            t2.moveMid();
            if (t2.y < 22 && positionC == 20)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (t2.y >= 19)
                    {
                        if ((!kbhit()) && (t2.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c);
                }
            }
        }

        if (count > 35 && count <= 50)
        {
            t3.train3();
            t3.moveRight();
            if (t3.y < 22 && positionC == 40)
            {
                Sleep(40);
                if (!kbhit())
                {
                    if (t3.y >= 19)
                    {
                        if ((!kbhit()) && (t3.y < 21))
                        {
                            gameOver();
                            break;
                        }
                    }
                }
                else
                {
                    MovementHandler::processInput(c); // Use MovementHandler to process input
                }
            }
        }
        // Restart all game after count=100 for continuation
        if (count == 115)
        {
            count = 1;
            c1.y = 10, c1.positionL = 41, c2.y = 5, c2.positionL = 46, c3.y = 1, c3.positionL = 49;

            c4.y = 10, c5.y = 5, c6.y = 1;

            c7.y = 10, c7.positionR = 62, c8.y = 5, c8.positionR = 58, c9.y = 1, c9.positionR = 54;

            u1.y = 1, u1.positionL = 47, u2.y = 1, u3.y = 1, u3.positionR = 55;

            l1.y = 1, l1.positionL = 47, l2.y = 1, l3.y = 1, l3.positionR = 55;

            t1.y = 1, t1.positionL = 42, t2.y = 1, t3.y = 1, t3.positionR = 48;
        }

        // Restart coin's positions for magnet
        if (count == 90)
        {

            c1.y = 1, c1.positionL = 47;
            c2.y = 1, c2.positionL = 47;
            c3.y = 1, c3.positionL = 47;

            c4.y = 1, c4.positionM = 53;
            c5.y = 1, c5.positionM = 53;
            c6.y = 1, c6.positionM = 53;

            c7.y = 1, c7.positionR = 59;
            c8.y = 1, c8.positionR = 59;
            c9.y = 1, c9.positionR = 59;
        }
        // Askicodes for kays

        if (kbhit())
        {
            MovementHandler::processInput(c);
        }
        if (m.y >= 17 && !conditionMet)
        {
            conditionMet = true;
            startTime = time(NULL);

            // Run this block once immediately after the condition is met

            c.drawM();
        }
        if (conditionMet)
        {
            // Check if 15 seconds have passed
            if (difftime(time(NULL), startTime) < 15)
            {

                c.drawM();
            }
        }

        system("cls");
        for (int i = 0; i < 20; i++)
            c.drawL();
        system("cls");
        for (int i = 0; i < 20; i++)
            c.drawR();
    }
    return 0;
}
