#include <iostream>
#include "../headers/ui.hpp"
#include "../headers/sequence.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"

using namespace std;

void get_types_menu(int &sequence_type)
{
    int type_choice;
    cout << "Choose data type: " << endl;
    cout << "1. Integer" << endl;
    cout << "2. Double" << endl;
    cout << "3. String" << endl;
    cout << "4. Return to Main Menu" << endl;
    cout << "0. Exit " << endl;
    cin >> type_choice;

    switch (type_choice)
    {
    case 1:
        get_sequence_type<int>(sequence_type);
        break;
    case 2:
        get_sequence_type<double>(sequence_type);
        break;
    case 3:
        get_sequence_type<string>(sequence_type);
        break;
    case 4:
        break;
    case 0:
        exit(0);
    default:
        throw invalid_argument("Invalid choice");
    }
}

template <typename T>
void get_sequence_type(int &sequence_type)
{
    sequence<T> *seq = nullptr;
    if (sequence_type == 1)
    {
        seq = new array_sequence<T>();
    }
    if (sequence_type == 2)
    {
        seq = new list_sequence<T>();
    }
    if (seq)
    {
        sequence_menu(seq);
    }
}
template <typename T>
void sequence_menu(sequence<T> *seq)
{
    int choice;
    T element;
    int index;

    while (true)
    {
        cout << "\n=== Sequence Menu ===" << endl;
        cout << "Choose option: " << endl;
        cout << "1. Get first element " << endl;
        cout << "2. Get last element " << endl;
        cout << "3. Get index element " << endl;
        cout << "4. Add element to end" << endl;
        cout << "5. Add element to beginning " << endl;
        cout << "6. Insert element to index " << endl;
        cout << "7. Concat with another " << endl;
        cout << "8. Print sequence " << endl;
        cout << "0. Return to main menu" << endl;
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << "First element: " << seq->get_first() << endl;
                break;
            case 2:
                cout << "Last element: " << seq->get_last() << endl;
                break;
            case 3:
                cout << "Choose index: ";
                cin >> index;
                cout << "Element: " << seq->get_element(index) << endl;
                break;
            case 4:
                cout << "Input element: ";
                cin >> element;
                seq = seq->append_element(element);
                cout << "Element added." << endl;
                break;
            case 5:
                cout << "Input element: ";
                cin >> element;
                seq = seq->prepend_element(element);
                cout << "Elemnt added." << endl;
                break;
            case 6:
                cout << "Choose index: ";
                cin >> index;
                cout << "Input element: ";
                cin >> element;
                seq = seq->insert_element(element, index);
                cout << "Element added." << endl;
                break;
            case 7:
            {
                cout << "Creating a new sequence to concat..." << endl;
                sequence<T> *other = new array_sequence<T>();
                int count;
                cout << "Input count of elements: ";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    cout << "Element" << i << ": ";
                    cin >> element;
                    other = other->append_element(element);
                }
                seq = seq->concat(*other);
                cout << "Sequences were concatenated." << endl;
                break;
            }
            case 8:
                seq->print();
                break;
            case 0:
                return;
            default:
                cout << "Something went wrong, please retry" << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}
