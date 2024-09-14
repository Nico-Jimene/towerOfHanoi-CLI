//
// Created by nico on 6/5/24.
//


#include <cstdlib>
#include <stack>
#include <vector>

#ifndef TOWEROFHANOI_OBJECTS_H
#define TOWEROFHANOI_OBJECTS_H


void clearScreen() {
    std::system("clear");
}

void initializeTowers(int stacks);
void gameplay(std::stack<std::vector<int>> &allTowers, int towerHeight);


#endif//TOWEROFHANOI_OBJECTS_H
