#include "headers.h"

class GuardList : public Genome<GuardList>
{
private:
    vector<Person> people;

public:
    // GuardList(int amount)
    // {
    //     this->people = new Person[amount];
    // }

    GuardList() {}

    GuardList(vector<Person> people)
    {
        this->people = people;
    }

    GuardList FromFile(string pathToFile)
    {
        people.clear();
        string line;
        int delimeterPos;
        ifstream dataFile(pathToFile);
        while (getline(dataFile, line))
        {
            delimeterPos = line.find(',');
            people.push_back(
                Person(line.substr(0, delimeterPos),
                       atof(line.substr(delimeterPos + 1).c_str())));
        }
        return *this;
    }

    string getStrRepr()
    {
        string str = "";
        for (int i = 0; i < people.size(); i++)
        {
            str.append(people[i].getName() + " - grindingScore: " + to_string(people[i].getGrindScore()) + "\n");
        }
        return str;
    }

    float calculateFitness()
    {
        float avgScore = 0.f;
        int bef, aft;
        float maxScore = (people.size() - 1) / 2;
        for (int i = 0; i < people.size(); i++)
        {
            // take the shorter rest time, before or after the guard.
            // then divide it by the shortest rest time possible.
            // the ones that rest the most time will get a zero score and the ones who rest the shortest will get one.
            // we power the result by two in order to motivate harsher sorting.
            avgScore += pow(abs(people[i].getGrindScore() - min((unsigned long)i, people.size() - 1 - i) / maxScore), 2);
        }
        fitness = avgScore;
        return fitness;
    }
    GuardList crossover(GuardList mate)
    {
        int swapIndex = getRandomNum(0, people.size() - 1);
        string swapName = mate.people[swapIndex].getName();
        swap(people[swapIndex], *find_if(people.begin(), people.end(), [&](Person p)
                                         { return p.getName() == swapName; }));
        return *this;
    }
    GuardList mutate(float rate)
    {
        if (people.size() < 2)
            return *this;
        if (getRandomNum(0, 100) > rate * 100)
            return *this;
        for (int i = 0; i < getRandomNum(1, people.size()); i++)
        {
            int firstI = getRandomNum(0, people.size() - 1);
            int secondI = getRandomNum(0, people.size() - 1);

            while (secondI == firstI)
            {
                secondI = getRandomNum(0, people.size() - 1);
            }
            swap(people[firstI], people[secondI]);
        }
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, GuardList &m)
{
    return os << m.getStrRepr();
}