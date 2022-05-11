#include "headers.h"

#define POP_SIZE 300
#define GENERATIONS 1000
#define MAX_IMPROVE_GENERATIONS 10
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
    float prevFitness = 0.f;
    int noImproveCounter = 0;
    for (int i = 0; i < POP_SIZE; i++)
    {
        pop[i].FromFile("testPeople.txt").mutate(1.f);
    }

    for (int generation = 0; generation < GENERATIONS; generation++)
    {
        sortPop(pop);
        if (pop[0].getFitness() <= prevFitness)
        {
            noImproveCounter++;
        }
        if (noImproveCounter == MAX_IMPROVE_GENERATIONS)
        {
            break;
        }
        prevFitness = pop[0].getFitness();

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