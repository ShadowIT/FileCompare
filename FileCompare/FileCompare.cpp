#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;


inline void errOccured() {
    cout << "\nPress enter to exit...";
    getchar();
    getchar();
}

int main(int argc, char* argv[])
{
    bool debug = false;
    string file_1;
    string file_2;
    switch (argc)
    {
    case 1:
        cout << "Enter the file names separated by a space: ";
        cin >> file_1 >> file_2;
        cout << endl;
        break;
    case 3:
        file_1 = argv[1];
        file_2 = argv[2];
        break;
    case 4:
        if (argv[3] == "-debug")
            debug = true;
        break;
    default:
        cout << "Invalid arguments...\n"
            << "Use the following template: "
            << "FileCompare [file_1] [file_2]\n";
        errOccured();
        return -3;
        break;
    }
    if (argc != 3) {
        
    }

    ifstream fin_1(file_1);
    ifstream fin_2(file_2);

    if (!fin_1.is_open()) {
        cout << "Error opening the first file...";
        errOccured();
        return -1;
    }
    if (!fin_2.is_open()) {
        cout << "Error opening the second file...";
        errOccured();
        return -2;
    }
    char ch_1;
    char ch_2;
    int strCount = 1;
    int chCount = 0;
    int chLineCount = 1;
    while (fin_1) {
        fin_1.get(ch_1);
        fin_2.get(ch_2);
        if (fin_1.eof() && !fin_2.eof())
            break;
        if (!(ch_1 == ch_2)) {
            cout << endl << "First not equal on line " << strCount 
                << ", character from line beginning " << chLineCount
                << " and character from the file beggining " << chCount << endl;
            errOccured();
            return 1;
        }
        ++chCount;
        ++chLineCount;
        if (ch_1 == '\n') {
            ++strCount;
            chLineCount = 1;
        }
        if(debug)
            cout << ch_1 << " : " << ch_2 << endl;
    }
    if (!fin_1 && !fin_2) {
        cout << "OK!!! Files " << file_1 << " and " << file_2
            << " are equal in characters." << endl << "Number of lines " << strCount << ".\n"
            << "Number of characters " << chCount << ".\n";
    }
    else {
        cout << endl << "The file " << file_1 << " is completely included in the file " << file_2
            << ", but the file " << file_2 << " is larger.\n"
            << "The files are partially equal. " << endl;
    }
    errOccured();
    return 0;
}