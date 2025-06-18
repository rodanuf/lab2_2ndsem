#include <iostream>
#include <limits>
#include <memory>
#include "../headers/ui.hpp"
#include "../headers/sequence.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"

using namespace std;

void check_input(int &choice)
{
    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input: programm cann't read letters");
    }
}

void get_types_menu(int &sequence_type)
{
    int type_choice;
    while (true)
    {
        cout << "Choose data type: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Double" << endl;
        cout << "3. String" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "0. Exit " << endl;
        try
        {
            check_input(type_choice);
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
                cout << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            continue;
        }
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
    int count;
    unique_ptr<sequence<T>> buffer_sequence;
    while (true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n=== Sequence Menu ===" << endl;
        cout << "Choose option: " << endl;
        cout << "1. Get first element " << endl;
        cout << "2. Get last element " << endl;
        cout << "3. Get index element " << endl;
        cout << "4. Add element to end" << endl;
        cout << "5. Add element to beginning " << endl;
        cout << "6. Insert element to index " << endl;
        cout << "7. Concat with another " << endl;
        cout << "8. Immutable add element to end" << endl;
        cout << "9. Immutable add element to beginning " << endl;
        cout << "10. Immutable insert element to index " << endl;
        cout << "11. Immutable concat with another " << endl;
        cout << "12. Print sequence " << endl;
        cout << "13. Print all sequences " << endl;
        cout << "14. Clear sequence " << endl;
        cout << "0. Return to previous menu" << endl;

        try
        {
            check_input(choice);
            switch (choice)
            {
            case 1:
            {
                cout << "First element: " << seq->get_first() << endl;
                break;
            }
            case 2:
            {
                cout << "Last element: " << seq->get_last() << endl;
                break;
            }
            case 3:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Element: " << seq->get_element(index) << endl;
                break;
            }
            case 4:
            {
                cout << "Input element: ";
                cin >> element;
                seq = seq->append_element(element);
                cout << "Element added." << endl;
                break;
            }
            case 5:
            {
                cout << "Input element: ";
                cin >> element;
                seq = seq->prepend_element(element);
                cout << "Elemnt added." << endl;
                break;
            }
            case 6:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Input element: ";
                cin >> element;
                seq = seq->insert_element(element, index);
                cout << "Element added." << endl;
                break;
            }
            case 7:
            {
                cout << "Creating a new sequence to concat..." << endl;
                sequence<T> *other = new array_sequence<T>();
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
            {
                cout << "Input element: " << endl;
                cin >> element;
                buffer_sequence.reset(seq->immutable_append_element(element));
                cout << "Element added." << endl;
                break;
            }
            case 9:
            {
                cout << "Input element: " << endl;
                cin >> element;
                buffer_sequence.reset(seq->immutable_prepend_element(element));
                cout << "Element added." << endl;
                break;
            }
            case 10:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Input element: ";
                cin >> element;
                buffer_sequence.reset(seq->immutable_insert_element(element, index));
                cout << "Element added." << endl;
                break;
            }
            case 11:
            {
                cout << "Creating a new sequence to concat..." << endl;
                sequence<T> *other = new array_sequence<T>();
                cout << "Input count of elements: ";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    cout << "Element" << i << ": ";
                    cin >> element;
                    other = other->append_element(element);
                }
                buffer_sequence.reset(seq->immutable_concat(*other));
                cout << "Sequences were concatenated." << endl;
                break;
            }
            case 12:
            {
                cout << "Sequence: ";
                seq->print();
                cout << endl;
                break;
            }
            case 13:
            {
                cout << "Sequence: ";
                seq->print();
                cout << endl;
                if (buffer_sequence != nullptr)
                {
                    cout << "Buffer sequence: ";
                    buffer_sequence->print();
                    cout << endl;
                }
                break;
            }
            case 14:
            {
                seq->clear();
                cout << "Sequence cleared." << endl;
                break;
            }
            case 0:
            {
                delete seq;
                return;
            }
            default:
            {
                throw invalid_argument("Invalid choice");
                cout << endl;
            }
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}
