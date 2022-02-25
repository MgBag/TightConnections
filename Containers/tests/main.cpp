#if _DEBUG
#include <iostream>
#include "vector.h"

int main()
{
    auto boi = tc::Vector<int>();
    boi.Reserve(20);
    boi.PushBack(1); 

    return 0;
}
#endif