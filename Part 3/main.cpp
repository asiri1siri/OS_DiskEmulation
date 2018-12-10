#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> elements;
double cylinders;
double sectors;

void initialize()
{
    string line_;
    ifstream file_("128bit.txt");

    if(file_.is_open())
    {
        while(getline(file_,line_))
        {
            if(line_.size() > 128)
            {
                elements.push_back("0");
            }
            else
            {
                elements.push_back(line_);
            }
        }

        file_.close();
    }
    else
    {
        cout << "File is not open!" << '\n';
    }
}

void info()
{
    sectors = elements.size();
    cylinders = ceil(sectors / 16);

    cout << endl;
    cout << "*********************************************" << endl;
    cout << "This disk contains " << cylinders << " cylinders" << endl;
    cout << "This disk contains " << sectors << " sectors" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void contentsAt(int x)
{
    sectors = elements.size();
    cylinders = ceil(sectors / 16);

    cout << "Contents at Sector " << sectors << " Cylinder " << cylinders << ": " <<  elements[x - 1] << endl;
}

void contentsAll()
{
    cout << "Disk Contents: " << endl;

    for(int i = 0; i < elements.size(); i++)
    {
        cout << elements[i] << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
}

void available()
{
    for(int i = 0; i < elements.size(); i++)
    {
        if(elements[i].length() == 0)
        {
            int cyl = ceil(i / 16);
            cout << "Sector " << i + 1 << " in Cylinder " << cyl << " is Available" << endl;
        }
    }

    cout << "Sector " << elements.size() << " and above are Available" << endl;
}

void write()
{
    string text;
    cout << "Enter your text: ";
    cin.ignore();
    getline(cin, text);

    std::ofstream outfile;
    outfile.open("128bit.txt", std::ios_base::app);
    outfile << text + "\n";
    elements.push_back(text);
}

void writeTo(int x)
{
    string text;
    cout << "Enter your text: ";
    cin.ignore();
    getline(cin, text);

    elements[x - 1] = text;

    cout << elements[x - 1] << endl;

    std::ofstream outfile;
    outfile.open("128bit.txt");
    outfile << "";

    for(int j = 0; j < elements.size(); j++)
    {
        std::ofstream outfile;
        outfile.open("128bit.txt", std::ios_base::app);
        outfile << elements[j] + "\n";
    }
}

void deleteAt(int x)
{
    for(int i = 0; i < elements.size(); i++)
    {
        std::ofstream outfile;
        outfile.open("128bit.txt");
        outfile << "";
    }

    for(int j = 0; j < elements.size(); j++)
    {
        if(j == (x - 1))
        {
            std::ofstream outfile;
            outfile.open("128bit.txt", std::ios_base::app);
            outfile << "\n";
        }
        else
        {
            std::ofstream outfile;
            outfile.open("128bit.txt", std::ios_base::app);
            outfile << elements[j] + "\n";
        }
    }
}

void format()
{
    std::ofstream outfile;
    outfile.open("128bit.txt");
    outfile << "";
}

int main()
{
    initialize();

    char choice;

    cout << endl;
    cout << ">>> Disk Storage System <<<" << endl;
    cout << "| I | Disk Info" << endl;
    cout << "| R | View Contents at a Sector" << endl;
    cout << "| A | View All Contents" << endl;
    cout << "| N | View Next Available Sector" << endl;
    cout << "| W | Write to end of Disk" << endl;
    cout << "| T | Write to a Sector" << endl;
    cout << "| D | Delete Contents at Sector" << endl;
    cout << "| F | Format Disk" << endl;
    cout << "| X | Exit Program" << endl;
    cout << "Enter the character corresponding to the function: ";
    cin >> choice;
    cout << endl;

        switch (choice)
        {
            case 'I':
                info();
                break;
            case 'R':
                int num1, num2;
                cout << "Enter Sector Number: ";
                cin >> num1;
                contentsAt(num1);
                break;
            case 'A':
                contentsAll();
                break;
            case 'N':
                available();
                break;
            case 'W':
                write();
                break;
            case 'T':
                int line;
                cout << "Enter Sector Number: ";
                cin >> line;
                writeTo(line);
                break;
            case 'D':
                int num3;
                cout << "Enter Sector Number: ";
                cin >> num3;
                deleteAt(num3);
                break;
            case 'F':
                char option;
                cout << "Are you sure you want to format disk? This operation is irreversible" << endl;
                cout << "Continue? (Y/N): ";
                cin >> option;
                if(option == 'Y')
                {
                    format();
                }
                break;
            case 'X':
                break;
            default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! operator is not correct\n";
            break;
        }

    return 0;
}
