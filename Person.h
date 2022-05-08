#include "Genome.h"
#include <string>

class Person
{
private:
    string name;
    float grindScore;

public:
    Person(string name)
    {
        this->name = name;
    }
    Person(string name, float grindScore)
    {
        this->name = name;
        this->grindScore = grindScore;
    }
};
