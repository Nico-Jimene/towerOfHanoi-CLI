#include "include/TowerOfHanoi.h"
#include <iomanip>
#include <iostream>
#include <stack>


void gameplay(std::stack<std::vector<int>> &allTowers, int towerHeight) {

    std::vector<int> finalTower = allTowers.top();
    allTowers.pop();
    std::vector<int> thirdTower = allTowers.top();
    allTowers.pop();
    std::vector<int> secondTower = allTowers.top();
    allTowers.pop();
    std::vector<int> firstTower = allTowers.top();
    allTowers.pop();

    char response = 0;
    bool gameWon = false;

    while (gameWon || response != 'n' || (secondTower.empty() && firstTower.empty())) {

        int towerFrom = 0;
        int towerTO = 0;

        for (int i = 0; i < firstTower.size(); i++) {
            std::cout << std::setw(3) << firstTower[i];
            std::cout << std::setw(8) << secondTower[i];
            std::cout << std::setw(8) << thirdTower[i];
            std::cout << std::endl;
        }

        std::cout << "\nTower 1\t"
                  << "Tower 2\t"
                  << "Tower 3\t" << std::endl;

        if (gameWon) {
            break;
        }


        std::cout << "Would you like to move?" << std::endl;
        std::cin >> response;

        if (response == 'n') {
            break;
        } else if (response == 'y') {
            std::cout << "Move From?" << std::endl;
            std::cin >> towerFrom;

            std::cout << "Move To?" << std::endl;
            std::cin >> towerTO;
            std::cout << "\n";


            switch (towerFrom) {// Check for edge cases -> Putting a larger weight ontop of another block, Removing Zeros from Cout
                case 1: {
                    int val = 0;
                    for (int i = 0; i < firstTower.size(); i++) {
                        if (firstTower[i] != 0) {
                            val = i;
                            break;
                        }
                    }

                    if (firstTower[val] == 0) {
                        break;
                    } else {

                        switch (towerTO) {
                            case 2: {

                                int valTwo = 0;

                                for (int i = 0; i < secondTower.size(); i++) {
                                    if (secondTower[i] != 0) {
                                        valTwo = i;
                                        break;
                                    }
                                }

                                if (secondTower.back() == 0) {
                                    secondTower.pop_back();
                                    secondTower.push_back(firstTower[val]);
                                    firstTower[val] = 0;
                                } else if (secondTower[valTwo] > firstTower[val] && --valTwo >= 0) {
                                    secondTower[valTwo] = firstTower[val];
                                    firstTower[val] = 0;
                                } else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }
                                break;
                            }
                            case 3: {
                                int valThird = 0;

                                for (int i = 0; i < thirdTower.size(); i++) {
                                    if (thirdTower[i] != 0) {
                                        valThird = i;
                                        break;
                                    }
                                }

                                if (thirdTower.back() == 0) {
                                    thirdTower.pop_back();
                                    thirdTower.push_back(firstTower[val]);
                                    firstTower[val] = 0;
                                }

                                else if (firstTower[val] < thirdTower[valThird] && --valThird >= 0) {
                                    thirdTower[valThird] = firstTower[val];
                                    firstTower[val] = 0;
                                }

                                else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }

                                break;
                            }
                            default: {
                                std::cout << "Please Select the 2nd or 3rd Tower" << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    int val = 0;
                    for (int i = 0; i < secondTower.size(); i++) {
                        if (secondTower[i] != 0) {
                            val = i;
                            break;
                        }
                    }


                    if (secondTower[val] == 0) {
                        break;
                    } else {

                        switch (towerTO) {
                            case 1: {

                                int valOne = 0;

                                for (int i = 0; i < firstTower.size(); i++) {
                                    if (firstTower[i] != 0) {
                                        valOne = i;
                                        break;
                                    }
                                }

                                if (firstTower.back() == 0) {
                                    firstTower.pop_back();
                                    firstTower.push_back(secondTower[val]);
                                    secondTower[val] = 0;
                                } else if (secondTower[val] < firstTower[valOne] && --valOne >= 0) {
                                    firstTower[valOne] = secondTower[val];
                                    secondTower[val] = 0;
                                } else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }
                                break;
                            }
                            case 3: {
                                int valThird = 0;

                                for (int i = 0; i < thirdTower.size(); i++) {
                                    if (thirdTower[i] != 0) {
                                        valThird = i;
                                        break;
                                    }
                                }

                                if (thirdTower.back() == 0) {
                                    thirdTower.pop_back();
                                    thirdTower.push_back(secondTower[val]);
                                    secondTower[val] = 0;
                                } else if (secondTower[val] < thirdTower[valThird] && --valThird >= 0) {
                                    thirdTower[valThird] = secondTower[val];
                                    secondTower[val] = 0;
                                } else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }

                                break;
                            }
                            default: {
                                std::cout << "Please Select the 1st or 3rd Tower" << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    int val = 0;
                    for (int i = 0; i < thirdTower.size(); i++) {
                        if (thirdTower[i] != 0) {
                            val = i;
                            break;
                        }
                    }


                    if (thirdTower[val] == 0) {
                        break;
                    } else {

                        switch (towerTO) {
                            case 1: {

                                int valOne = 0;

                                for (int i = 0; i < firstTower.size(); i++) {
                                    if (firstTower[i] != 0) {
                                        valOne = i;
                                        break;
                                    }
                                }

                                if (firstTower.back() == 0) {
                                    firstTower.pop_back();
                                    firstTower.push_back(thirdTower[val]);
                                    thirdTower[val] = 0;
                                } else if (thirdTower[val] < firstTower[valOne] && --valOne >= 0) {
                                    firstTower[valOne] = thirdTower[val];
                                    thirdTower[val] = 0;
                                } else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }
                                break;
                            }
                            case 2: {
                                int valTwo = 0;

                                for (int i = 0; i < secondTower.size(); i++) {
                                    if (secondTower[i] != 0) {
                                        valTwo = i;
                                        break;
                                    }
                                }

                                if (secondTower.back() == 0) {
                                    secondTower.pop_back();
                                    secondTower.push_back(thirdTower[val]);
                                    thirdTower[val] = 0;
                                } else if (thirdTower[val] < secondTower[valTwo] && --valTwo >= 0) {
                                    secondTower[valTwo] = thirdTower[val];
                                    thirdTower[val] = 0;
                                } else {
                                    std::cout << "Cannot Add Other Block" << std::endl;
                                }

                                break;
                            }
                            default: {
                                std::cout << "Please Select the 1st or 3rd Tower" << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                default: {
                    std::cout << "Please Select" << std::endl;
                    break;
                }
            }
        }

        int check = 0;
        for (int i = 0; i < towerHeight; i++) {
            if (thirdTower[i] == finalTower[i]) {
                ++check;
            }
        }

        if (check == towerHeight) {
            gameWon = true;
            std::cout << "YOU WON!!!\n\n"
                      << std::endl;
        }
    }
}


std::vector<int> towerCreation(int weight_input) {

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++) {
        tower.push_back(i);
    }

    return tower;
}

std::vector<int> emptyTower(int weight_input) {

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++) {
        tower.push_back(0);
    }

    return tower;
}


void initializeTowers(int stacks) {

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

    gameplay(allTowers, stacks);
}

void displayGameMenu() {
    clearScreen();
    std::cout << "Tower of Hanoi Game" << std::endl;
    std::cout << "1. Press Space to Start\n";
    std::cout << "2. Instructions For Game (Press I)" << std::endl;
}

int main() {
    // Need to add CLI Features
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
