#include <random>

using namespace std;

int getRandomNum(int start, int end)
{
    static random_device dev;
    static mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> randlength(start, end);
    return randlength(rng);
}