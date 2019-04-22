/**
 * This program intends to test that additional compiler definitions will make stdlibc++ crash.
 * Normally this program wonät crash.
 *
 * Program taken from: https://kristerw.blogspot.com/2018/03/detecting-incorrect-c-stl-usage.html
 */

#include <iostream>
#include <list>

int main()
{
    std::list<int> list1 = { 1, 2, 3, 4 };
    list1.insert(list1.begin(), list1.begin(), list1.end());
    for (auto x : list1)
        std::cout << x << '\n';
}