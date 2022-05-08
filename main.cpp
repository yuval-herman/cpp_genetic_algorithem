#include <iostream>
#include <algorithm>

#include "StringGenome.h"

#define POP_SIZE 300
#define GENERATIONS 2000
#define MAX_IMPROVE_TRIES 10
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "you need to define a goal!" << endl;
        return 1;
    }
    string goal = argv[1];
    StringGenome population[POP_SIZE];
    StringGenome newPop[POP_SIZE];
    StringGenome winner(goal);
    winner.calculateFitness(goal);

    for (int generation = 0; generation < GENERATIONS; generation++)
    {
        sort(begin(population), end(population), [=](StringGenome a, StringGenome b) -> bool
             { return a.calculateFitness(goal) > b.calculateFitness(goal); });

        for (int i = 0; i < POP_SIZE; i++)
        {
            int first = getRandomNum(0, POP_SIZE / 5);
            int second = getRandomNum(0, POP_SIZE / 5);
            while (second == first)
            {
                second = getRandomNum(0, POP_SIZE / 5);
            }
            StringGenome testGenome = population[first].crossover(population[second]).mutation();
            for (int j = 0; j < MAX_IMPROVE_TRIES; j++)
            {
                if (testGenome.calculateFitness(goal) <= population[first].getFitness())
                {
                    testGenome.mutation();
                }
                else
                {
                    break;
                }
            }
            if (testGenome.getFitness() < population[first].getFitness())
            {
                newPop[i] = population[first];
            }
            else
            {
                newPop[i] = testGenome;
            }
        }

        swap(population, newPop);
        cout << endl
             << population[0].getStr() << " ---- " << population[0].getFitness() << endl;

        if (population[0].getFitness() >= winner.getFitness())
        {
            cout << endl
                 << endl
                 << "Finished after " << generation << " generations." << endl
                 << "Solution:" << endl
                 << population[0].getStr() << endl;
            break;
        }
    }
    return 0;
}