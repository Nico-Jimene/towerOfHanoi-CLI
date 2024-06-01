#include "include/objects.h"
#include <iomanip>
#include <iostream>
#include <stack>


void gameplay(std::stack<std::vector<int>> &allTowers, int towerHeight) {

    std::vector<int> thirdTower = allTowers.top();
    allTowers.pop();
    std::vector<int> secondTower = allTowers.top();
    allTowers.pop();
    std::vector<int> firstTower = allTowers.top();
    allTowers.pop();

    char response = 0;

    while (response != 'n' || (secondTower.empty() && firstTower.empty())) {

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
                case 1:
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
                            case 2:

                                if (firstTower[val] != 0) {
                                    secondTower.pop_back();
                                    secondTower.push_back(firstTower[val]);
                                    firstTower[val] = 0;
                                }
                                break;
                            case 3:
                                int newVal = 0;


                                break;
                        }
                    }
            }
        }
    }
}

void initializeTowers(int stacks) {

    std::stack<std::vector<int>> allTowers;

    std::vector<int> firstTower;
    std::vector<int> secondTower;
    std::vector<int> thirdTower;


    firstTower = towerObject::towerCreation(stacks);
    secondTower = towerObject::emptyTower(stacks);
    thirdTower = towerObject::emptyTower(stacks);

    allTowers.push(firstTower);
    allTowers.push(secondTower);
    allTowers.push(thirdTower);

    gameplay(allTowers, stacks);
}


std::vector<int> towerObject::towerCreation(int weight_input) {

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++) {
        tower.push_back(i);
    }

    return tower;
}

std::vector<int> towerObject::emptyTower(int weight_input) {

    std::vector<int> tower;
    for (int i = 1; i < weight_input + 1; i++) {
        tower.push_back(0);
    }

    return tower;
}


int main() {
    // Need to add CLI Features
    int result = 0;
    std::cout << "How many Stacks?" << std::endl;
    std::cin >> result;

    initializeTowers(result);
}
