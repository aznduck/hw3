#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;

int main(int argc, char* argv[])
{

    Heap<int, std::less<int>> c;
    cout << c.size() << endl;
    cout << c.empty() << endl;
    c.push(0);
    c.push(10);
    c.push(5);                   
    cout << c.top() << endl;    
    c.pop();                        
    cout << c.top() << endl;
    c.pop();
    cout << c.top() << endl;
    c.pop();
    //cout << c.empty() << endl;
    //return 0;

}
