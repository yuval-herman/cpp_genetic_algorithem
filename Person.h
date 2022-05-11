#include "headers.h"

class Person
{
private:
    string name;
    float grindScore; // the lower the better

public:
    Person()
    {
        this->name = getRandomStr(10);
        this->grindScore = getRandomNum(0, 100) / 100.f;
    }
    Person(string name)
    {
        this->name = name;
        this->grindScore = getRandomNum(0, 100) / 100.f;
    }
    Person(string name, float grindScore)
    {
        this->name = name;
        this->grindScore = grindScore;
    }
    string getName() {return name;}
    float getGrindScore() {return grindScore;}
};
