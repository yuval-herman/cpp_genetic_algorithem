#include <algorithm>

#include "GuardList.h"

#define POP_SIZE 300
#define GENERATIONS 2000
#define MAX_IMPROVE_TRIES 10
using namespace std;

int main(int argc, char *argv[])
{
    GuardList pop[POP_SIZE];
    for (int i = 0; i < POP_SIZE; i++)
    {
        pop[i].FromFile("testPeople.txt").mutation();
    }

    sort(pop, pop + POP_SIZE, [=](GuardList a, GuardList b)
         { return a.calculateFitness() > b.calculateFitness(); });
    cout << pop[0] << endl;
    // GuardList test;
    // test.FromFile("testPeople.txt");
    // cout << test<<endl;
    return 0;
}