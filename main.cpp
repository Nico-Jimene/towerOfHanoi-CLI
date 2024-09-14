#include "include/TowerOfHanoi.h"
#include <iomanip>
#include <iostream>
#include <ncurses.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stack>
#include <string>

void gameplay(std::stack<std::vector<int>> &allTowers, int towerHeight)
{

    std::vector<int> finalTower = allTowers.top();
    allTowers.pop();
    std::vector<int> thirdTower = allTowers.top();
    allTowers.pop();
    std::vector<int> secondTower = allTowers.top();
    allTowers.pop();
    std::vector<int> firstTower = allTowers.top();
    allTowers.pop();

    char response;
    char towerFrom;
    char towerTO;

    bool gameWon = false;

    while (gameWon || response != 'n' || (secondTower.empty() && firstTower.empty()))
    {

        for (int i = 0; i < firstTower.size(); i++)
        {
            mvprintw(i + 10, 26, "%d", firstTower[i]);
            mvprintw(i + 10, 52, "%d", secondTower[i]);
            mvprintw(i + 10, 78, "%d", thirdTower[i]);
            refresh();
        }

        mvprintw(firstTower.size() + 12, 24, "Tower 1");
        mvprintw(firstTower.size() + 12, 50, "Tower 2");
        mvprintw(firstTower.size() + 12, 76, "Tower 3");

        if (gameWon)
        {
            break;
        }

        mvprintw(firstTower.size() + 20, 5, "Would you like to move?");
        refresh();

        while (true)
        {
            response = getch();
            if (response == 'n' || response == 'y')
            {
                printw("%c", response); // Display the character
                refresh();
                break;
            }
        }
        move(firstTower.size() + 20, 0);
        clrtoeol();
        refresh();

        if (response == 'n')
        {
            printw("Goodbye");
            break;
        }
        else if (response == 'y')
        {

            mvprintw(firstTower.size() + 20, 5, "Move From?");
            refresh();

            while (true)
            {
                towerFrom = getch();
                if (towerFrom == '1' || towerFrom == '2' || towerFrom == '3')
                {
                    printw("%c", towerFrom); // Display the character
                    refresh();
                    break;
                }
            }
            move(firstTower.size() + 20, 0);
            clrtoeol();
            refresh();

            mvprintw(firstTower.size() + 20, 5, "Move To?");
            refresh();

            while (true)
            {
                towerTO = getch();
                if (towerTO == '1' || towerTO == '2' || towerTO == '3')
                {
                    printw("%c", towerTO); // Display the character
                    refresh();
                    break;
                }
            }
            move(firstTower.size() + 20, 0);
            clrtoeol();
            refresh();

            switch (towerFrom)
            { // Check for edge cases -> Putting a larger weight ontop of another block, Removing Zeros from Cout
            case '1':
            {
                int val = 0;
                for (int i = 0; i < firstTower.size(); i++)
                {
                    if (firstTower[i] != 0)
                    {
                        val = i;
                        break;
                    }
                }

                if (firstTower[val] == 0)
                {
                    break;
                }
                else
                {

                    switch (towerTO)
                    {
                    case '2':
                    {

                        int valTwo = 0;

                        for (int i = 0; i < secondTower.size(); i++)
                        {
                            if (secondTower[i] != 0)
                            {
                                valTwo = i;
                                break;
                            }
                        }

                        if (secondTower.back() == 0)
                        {
                            secondTower.pop_back();
                            secondTower.push_back(firstTower[val]);
                            firstTower[val] = 0;
                        }
                        else if (secondTower[valTwo] > firstTower[val] && --valTwo >= 0)
                        {
                            secondTower[valTwo] = firstTower[val];
                            firstTower[val] = 0;
                        }
                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }
                        break;
                    }
                    case '3':
                    {
                        int valThird = 0;

                        for (int i = 0; i < thirdTower.size(); i++)
                        {
                            if (thirdTower[i] != 0)
                            {
                                valThird = i;
                                break;
                            }
                        }

                        if (thirdTower.back() == 0)
                        {
                            thirdTower.pop_back();
                            thirdTower.push_back(firstTower[val]);
                            firstTower[val] = 0;
                        }

                        else if (firstTower[val] < thirdTower[valThird] && --valThird >= 0)
                        {
                            thirdTower[valThird] = firstTower[val];
                            firstTower[val] = 0;
                        }

                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }

                        break;
                    }
                    default:
                    {
                        std::cout << "Please Select the 2nd or 3rd Tower" << std::endl;
                        break;
                    }
                    }
                }
                break;
            }
            case '2':
            {
                int val = 0;
                for (int i = 0; i < secondTower.size(); i++)
                {
                    if (secondTower[i] != 0)
                    {
                        val = i;
                        break;
                    }
                }

                if (secondTower[val] == 0)
                {
                    break;
                }
                else
                {

                    switch (towerTO)
                    {
                    case '1':
                    {

                        int valOne = 0;

                        for (int i = 0; i < firstTower.size(); i++)
                        {
                            if (firstTower[i] != 0)
                            {
                                valOne = i;
                                break;
                            }
                        }

                        if (firstTower.back() == 0)
                        {
                            firstTower.pop_back();
                            firstTower.push_back(secondTower[val]);
                            secondTower[val] = 0;
                        }
                        else if (secondTower[val] < firstTower[valOne] && --valOne >= 0)
                        {
                            firstTower[valOne] = secondTower[val];
                            secondTower[val] = 0;
                        }
                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }
                        break;
                    }
                    case '3':
                    {
                        int valThird = 0;

                        for (int i = 0; i < thirdTower.size(); i++)
                        {
                            if (thirdTower[i] != 0)
                            {
                                valThird = i;
                                break;
                            }
                        }

                        if (thirdTower.back() == 0)
                        {
                            thirdTower.pop_back();
                            thirdTower.push_back(secondTower[val]);
                            secondTower[val] = 0;
                        }
                        else if (secondTower[val] < thirdTower[valThird] && --valThird >= 0)
                        {
                            thirdTower[valThird] = secondTower[val];
                            secondTower[val] = 0;
                        }
                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }

                        break;
                    }
                    default:
                    {
                        std::cout << "Please Select the 1st or 3rd Tower" << std::endl;
                        break;
                    }
                    }
                }
                break;
            }
            case '3':
            {
                int val = 0;
                for (int i = 0; i < thirdTower.size(); i++)
                {
                    if (thirdTower[i] != 0)
                    {
                        val = i;
                        break;
                    }
                }

                if (thirdTower[val] == 0)
                {
                    break;
                }
                else
                {

                    switch (towerTO)
                    {
                    case '1':
                    {

                        int valOne = 0;

                        for (int i = 0; i < firstTower.size(); i++)
                        {
                            if (firstTower[i] != 0)
                            {
                                valOne = i;
                                break;
                            }
                        }

                        if (firstTower.back() == 0)
                        {
                            firstTower.pop_back();
                            firstTower.push_back(thirdTower[val]);
                            thirdTower[val] = 0;
                        }
                        else if (thirdTower[val] < firstTower[valOne] && --valOne >= 0)
                        {
                            firstTower[valOne] = thirdTower[val];
                            thirdTower[val] = 0;
                        }
                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }
                        break;
                    }
                    case '2':
                    {
                        int valTwo = 0;

                        for (int i = 0; i < secondTower.size(); i++)
                        {
                            if (secondTower[i] != 0)
                            {
                                valTwo = i;
                                break;
                            }
                        }

                        if (secondTower.back() == 0)
                        {
                            secondTower.pop_back();
                            secondTower.push_back(thirdTower[val]);
                            thirdTower[val] = 0;
                        }
                        else if (thirdTower[val] < secondTower[valTwo] && --valTwo >= 0)
                        {
                            secondTower[valTwo] = thirdTower[val];
                            thirdTower[val] = 0;
                        }
                        else
                        {
                            std::cout << "Cannot Add Other Block" << std::endl;
                        }

                        break;
                    }
                    default:
                    {
                        std::cout << "Please Select the 1st or 3rd Tower" << std::endl;
                        break;
                    }
                    }
                }
                break;
            }
            default:
            {
                std::cout << "Please Select" << std::endl;
                break;
            }
            }
        }

        int check = 0;
        for (int i = 0; i < towerHeight; i++)
        {
            if (thirdTower[i] == finalTower[i])
            {
                ++check;
            }
        }

        if (check == towerHeight)
        {
            gameWon = true;
            printw("YOU WON!!!!");
            refresh();
            endwin();
        }
    }
}

std::vector<int> towerCreation(int weight_input)
{

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++)
    {
        tower.push_back(i);
    }

    return tower;
}

std::vector<int> emptyTower(int weight_input)
{

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++)
    {
        tower.push_back(0);
    }

    return tower;
}

std::stack<std::vector<int>> initializeTowers()
{

    int stacks = 0;
    char ch;

    printw("Please Enter Number Of Stacks (1-9): ");

    while (true)
    {
        ch = getch();
        if (isdigit(ch))
        {
            stacks = (ch - '0');
            printw("%d", stacks);
            refresh();
            break;
        }
    }

    std::stack<std::vector<int>> allTowers;

    std::vector<int> firstTower;
    std::vector<int> secondTower;
    std::vector<int> thirdTower;
    std::vector<int> finalTower;

    firstTower = towerCreation(stacks);
    secondTower = emptyTower(stacks);
    thirdTower = emptyTower(stacks);
    finalTower = towerCreation(stacks);

    allTowers.push(firstTower);
    allTowers.push(secondTower);
    allTowers.push(thirdTower);
    allTowers.push(finalTower);

    // gameplay(allTowers, stacks);
}

void displayGameMenu()
{

    printw("Tower of Hanoi Game\n\n");
    printw("1. Start Game (Press Space)\n");
    printw("2. Instructions For Game (Press i)\n\n");
}

int main()
{
    // Need to add CLI Features
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    displayGameMenu();
    refresh();
    int ch;

    while (true)
    {
        ch = getch();
        switch (ch)
        {
        case ' ':
        {
            clear();
            refresh();
            std::stack<std::vector<int>> combinedTowers = initializeTowers();

            std::cout << "it worked";
            int xCord = 29;
            int yCord = 22;

            int maxXCord;
            int maxYCord;
            getmaxyx(stdscr, maxYCord, maxXCord);
            int count = 0;

            while (true)
            {

                refresh();
                clear();

                mvprintw(yCord, xCord, "1");

                int input = getch();

                switch (input)
                {
                case KEY_UP:
                    yCord = (yCord - 9);
                    break;
                case KEY_DOWN:
                    yCord = (yCord + 10);
                    break;
                case KEY_LEFT:
                    if (xCord - 29 < 29)
                    {
                        xCord = 29;
                    }
                    else
                    {
                        xCord -= 29;
                    }
                    break;
                case KEY_RIGHT:

                    if (xCord + 29 > 87)
                    {
                        xCord = 87;
                    }
                    else
                    {
                        xCord += 29;
                    }
                    break;
                case ' ':
                    // yCord = (yCord + 9);
                    break;
                case 'q': // Quit if 'q' is pressed
                    endwin();
                    return 0;
                default:
                    break;
                }
            }

            endwin();

            break;
        }
        case 'i':
        {
            clear();
            refresh();
            printw("Instructions Listed");
            break;
        }
            //            default: {
            //                std::cout << "Please choose an option" << std::endl;
            //                break;
            //            }
        }
    }

    return 0;
    int result = 0;
    std::cout << "How many Stacks?" << std::endl;
    std::cin >> result;

    //    displayGameMenu();
    //    char choice;
    //
    //    std::cout << "Press the space bar" << std::endl;
    //
    //

    initializeTowers(result);
}