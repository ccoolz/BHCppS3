#include "Test.h"
using namespace std;

namespace np2 {
    void Cout()
    {
        std::cout << "np2";
    }
}

namespace np3 {
    int a = 1;
    int b = 2;
}

void Test1()
{
    //cout << a << endl;
    using np3::a;
    cout << a << endl;
    //cout << b << endl;
    //int a;
}

void Test2()
{
    using namespace np3;
    cout << a << endl;
    int a = 3;
    cout << a << endl;
}

int main()
{

    Test1();
    //cout << a << endl;

    Test2();

    np1::Print();
}
