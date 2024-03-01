#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> c;
    cout << c.size();
    cout << c.empty();
    c.push(8);
    c.push(7);
    cout << c.top();
    c.pop();
    cout << c.top();
    return 0;

}
