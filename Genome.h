#include <string>
#include "helpers.h"

using namespace std;
template <class T>

class Genome
{
private:
    float fitness = 0.f;

public:
    float getFitness() { return fitness; }
    virtual float calculateFitness(string goal) = 0;

    virtual T crossover(T) = 0;
    virtual T mutation() = 0;
};
