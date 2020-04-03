#include <iostream>
#include <vector>
#include <string>

using namespace std;

void gladys()
{
    cout << "ARE YOU NOT ENTERTAINED?" << endl;
}


int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    gladys();
}