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
string getRandomStr(int size)
{
    string str = "";
    for (int i = 0; i < size; i++)
    {
        str += getRandomChar();
    }
    return str;
}
string getRandomStr()
{
    return getRandomStr(getRandomNum(2, 1000));
}