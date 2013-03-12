#include <iostream>
#include "core/ValueModel.h"

using namespace std;

void tests()
{
    cout << "Test Valuemodel" << endl;
    core::ValueModel<int> test;
    test.SetValue(2);
    cout << test.Evaluate() << endl;

}

int main()
{
    cout << "Hello world!" << endl;
    tests();
    return 0;
}

