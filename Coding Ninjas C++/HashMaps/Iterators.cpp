#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key : " << (*it).first << " Value : " << it->second << endl;
        it++;
    }
    // If we had used ordered map, the values would be printed in a sorted manner

    unordered_map<string, int>::iterator it2 = ourmap.find("abc");

    ourmap.erase(it2, next(it2, 4));

    it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key : " << (*it).first << " Value : " << it->second << endl;
        it++;
    }
}