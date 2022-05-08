#include "Genome.h"
#include <string>

class StringGenome : public Genome<StringGenome>
{
private:
    string str = "";
    float fitness = 0.f;

public:
    StringGenome()
    {
        this->str = generateRandomStr();
    }
    StringGenome(string str)
    {
        this->str = str;
    }

    string getStr() { return str; }
    float getFitness() { return fitness; }

    StringGenome crossover(StringGenome mate)
    {
        string mateStr = mate.getStr();
        bool useOurStr = getRandomNum(0, 1);
        string newStr = (useOurStr) ? str : mateStr;
        for (int i = 0; i < newStr.length(); i++)
        {
            if ((useOurStr) ? mateStr.length() : str.length() < i) // might cause problems, off-by-one-error TODO FIXME
            {
                newStr[i] = (!useOurStr) ? mateStr[i] : str[i];
            }
            else
            {
                newStr[i] = (getRandomNum(0, 1)) ? mateStr[i] : str[i];
            }
        }
        return StringGenome(newStr);
    }

    StringGenome mutation()
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = (getRandomNum(0, 100) == 0) ? getRandomChar() : str[i];
        }
        if ((getRandomNum(0, 1000) == 0))
            str.pop_back();
        if ((getRandomNum(0, 1000) == 0))
            str.push_back(getRandomChar());
        return *this;
    }

    float calculateFitness(string goal)
    {
        if (goal.length() > str.length())
        {
            fitness = (float)str.length() / goal.length();
        }
        else
        {
            fitness = (float)goal.length() / str.length();
        }
        fitness /= 2;
        float correctCharValue = 1.0f / goal.length() / 2;

        for (int i = 0; i < min(goal.length(), str.length()); i++)
        {
            if (str[i] == goal[i])
            {
                fitness += correctCharValue;
            }
        }

        return fitness;
    }
};