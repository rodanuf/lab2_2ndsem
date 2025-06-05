#include <iostream>

#include "../headers/sequence.hpp"
#include "../headers/sequence.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"

using namespace std;

template <typename T>
sequence<T> *main_menu()
{
    int choice;
    sequence<T> *seq = nullptr;
    while (true)
    {
        cout << "\n=== Main menu ===" << endl;
        cout << "Choose sequence type: ";
        cout << "1. array_sequence" << endl;
        cout << "2. list_sequence" << endl;
        cout << "0. exit" << endl; // обработка ошибок пользователя
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                seq = new array_sequence<T>();
                sequence_menu(seq);
                break;
            case 2:
                seq = new list_sequence<T>();
                sequence_menu(seq);
                break;
            case 0:
                return;
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    while (true)
    {
        cout << "Choose data type"
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
        cout << "\n=== Меню последовательности ===" << endl;
        cout << "1. Получить первый элемент" << endl;
        cout << "2. Получить последний элемент" << endl;
        cout << "3. Получить элемент по индексу" << endl;
        cout << "4. Добавить элемент в конец" << endl;
        cout << "5. Добавить элемент в начало" << endl;
        cout << "6. Вставить элемент по индексу" << endl;
        cout << "7. Объединить с другой последовательностью" << endl;
        cout << "8. Вывести последовательность" << endl;
        cout << "0. Вернуться в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Первый элемент: " << seq->get_first() << endl;
                break;
            case 2:
                cout << "Последний элемент: " << seq->get_last() << endl;
                break;
            case 3:
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Элемент: " << seq->get_element(index) << endl;
                break;
            case 4:
                cout << "Введите элемент: ";
                cin >> element;
                seq = seq->append_element(element);
                cout << "Элемент добавлен." << endl;
                break;
            case 5:
                cout << "Введите элемент: ";
                cin >> element;
                seq = seq->prepend_element(element);
                cout << "Элемент добавлен." << endl;
                break;
            case 6:
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Введите элемент: ";
                cin >> element;
                seq = seq->insert_element(element, index);
                cout << "Элемент вставлен." << endl;
                break;
            case 7:
            {
                cout << "Создание новой последовательности для объединения..." << endl;
                sequence<T> *other = new array_sequence<T>();
                int count;
                cout << "Введите количество элементов: ";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    cout << "Элемент " << i << ": ";
                    cin >> element;
                    other = other->append_element(element);
                }
                seq = seq->concat(other);
                cout << "Последовательности объединены." << endl;
                break;
            }
            case 8:
                seq.print(seq);
                break;
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
}
