
#include "string_delimiter.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

template <class T>
using V = typename std::vector<T>;

int main()
{
    V<V<int>> vectors = {{}, {1}, {1,2,3,4,5}};

    cout << "JoinLoop demonstration:" << endl;

    for (auto v : vectors)
        cout << JoinLoop(v.begin(), v.end(), ", ") << endl;

    cout << "JoinFunc demonstration:" << endl;

    for (auto v : vectors)
        cout << JoinFunc(v.begin(), v.end(), ", ") << endl;

    return 0;
}
