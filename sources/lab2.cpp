#include <iostream>
#include "../headers/ui.hpp"

using namespace std;

int main()
{
    int choice = 0;
    while (true)
    {
        cout << "\n=== Main menu ===" << endl;
        cout << "Choose sequence type: " << endl;
        cout << "1. array_sequence" << endl;
        cout << "2. list_sequence" << endl;
        cout << "0. exit" << endl;
        cin >> choice;

        try
        {
            get_types_menu(choice);
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
