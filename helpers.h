#include <random>

using namespace std;

int getRandomNum(int start, int end)
{
    static random_device dev;
    static mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> randlength(start, end);
    return randlength(rng);
}
char getRandomChar()
{
    return (char)getRandomNum(32, 126);
}
string generateRandomStr()
{
    string str = "";
    int len = getRandomNum(2, 1000);
    for (int i = 0; i < len; i++)
    {
        str += getRandomChar();
    }
    return str;
}