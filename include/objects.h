//
// Created by nico on 5/30/24.
//

#include <stack>
#include <vector>

#ifndef TOWEROFHANOI_OBJECTS_H
#define TOWEROFHANOI_OBJECTS_H

void initializeTowers(int stacks);
void gameplay(std::stack<std::vector<int>> &allTowers, int towerHeight);

class towerObject {

private:
    int weight = 0;

public:
    explicit towerObject(int weight_input) : weight(weight_input) {};

    towerObject() = default;

    int getWeight() {
        return weight;
    };
    static std::vector<int> towerCreation(int weight_input);

    static std::vector<int> emptyTower(int weight_input);
};


#endif//TOWEROFHANOI_OBJECTS_H
