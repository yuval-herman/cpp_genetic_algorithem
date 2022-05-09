#include <algorithm>

#include "GuardList.h"

#define POP_SIZE 300
#define GENERATIONS 100
#define MAX_IMPROVE_TRIES 10
using namespace std;

GuardList *select(GuardList *pop, int selectionRange)
{
    return pop + getRandomNum(0, selectionRange);
}

void sortPop(GuardList *pop)
{
    sort(pop, pop + POP_SIZE, [=](GuardList a, GuardList b)
         { return a.calculateFitness() > b.calculateFitness(); });
}

int main(int argc, char *argv[])
{
    GuardList pop[POP_SIZE];
    GuardList nextPop[POP_SIZE];
    for (int i = 0; i < POP_SIZE; i++)
    {
        pop[i].FromFile("testPeople.txt").mutate(1.f);
    }

    for (int generation = 0; generation < GENERATIONS; generation++)
    {
        sortPop(pop);

        cout << "gen " << generation << " end, best fitness is " << pop[0].calculateFitness() << '\r';
        for (int i = 0; i < POP_SIZE; i++)
        {
            nextPop[i] = select(pop, POP_SIZE / 5)->crossover(*select(pop, POP_SIZE / 5)).mutate(.1f);
        }
        swap(nextPop, pop);
    }

    sortPop(pop);
    cout << endl
         << pop[0] << endl
         << pop[0].calculateFitness() << endl;
    return 0;
}