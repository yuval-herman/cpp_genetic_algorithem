#include "headers.h"

using namespace std;
template <class T>

class Genome
{
protected:
    float fitness = 0.f;

public:
    float getFitness() { return fitness; }

    virtual float calculateFitness() = 0;
    virtual T crossover(T) = 0;
    virtual T mutate(float rate) = 0;
};
