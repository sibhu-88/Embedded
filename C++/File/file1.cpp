#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, const char *argv[])
{

    if (argc != 4)
    {
        cout << "Usage : ./a.out file char1 char2" << endl;
        return 0;
    }

    fstream fout;
    fout.open(argv[1], ios::in | ios::out);

    if (fout.is_open() == 0)
    {
        cout << "The src_file doesn't exist" << endl;
        return 0;
    }

    char ch;
    while ((ch = fout.get()) != EOF)
    {
        if (ch == argv[2][0])
        {
            fout.seekg(-1, ios::cur);
            fout.put(argv[3][0]);
        }
    }
}