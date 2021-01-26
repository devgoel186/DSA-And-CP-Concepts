#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

int main()
{
    unordered_map<string, int> ourmap;

    // Insert operation
    pair<string, int> p("abc", 1);
    ourmap.insert(p);  // We can insert an element into an
    ourmap["def"] = 2; // unordered map using these syntaxes

    // Find or access elements
    cout << ourmap.at("abc") << endl;
    cout << ourmap["abc"] << endl;

    // cout << ourmap.at("ghi") << endl; // This gives an error
    cout << ourmap["ghi"] << endl; // This will insert a key-value pair
                                   // ("ghi", 0) [0 is the default value]
    if (ourmap.count("ghi") > 0)
        cout << "'ghi' is present" << endl;
    cout << ourmap.size() << endl;
}