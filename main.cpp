#include <iostream>
#include "Time.h"
#include "elem.h"

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    Time t1;
    queue_base queue,queue2,queue3;
    double user_value, divider;
    char menu_value; char submenu;
    do
    {
        system("cls");
        cout << t1;
        cout << "\nВыберите действие" << endl;
        cout << "[1] ++(постфиксная форма, метод). Увеличить на Ваш выбор: минуты, секунды, часы" << endl;
        cout << "[2] --(постфиксная форма, метод). Уменьшить на Ваш выбор: минуты, секунды, часы" << endl;
        cout << "[3] ++(префиксная форма, дружественная функция) увеличивает на выбор пользователя либо секунды, либо минуты, либо часы на единицу." << endl;
        cout << "[4] --(префиксная форма, дружественная функция) уменьшает на выбор пользователя либо секунды, либо минуты, либо часы на единицу." << endl << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "Очередь №1: "; queue.show(); cout << endl;
        cout << "Очередь №2: "; queue2.show(); cout << endl;
        cout << "[5] += добавление элемента в очередь (дружественная функция)" << endl;
        cout << "[6] + сложение двух очередей (метод)" << endl;
        cout << "[7] =- для извлечения элемента из очереди(метод)" << endl;
        cout << "[8] - для вычитания очередей друг с другом (дружественная функция)" << endl;
        cout << "[9] * для поэлементного умножения очередей друг на друга(метод)" << endl;
        cout << "[0] / для деления очереди на число(метод)" << endl;
        cout << "[x] Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> menu_value;
        switch (menu_value)
        {
        case '1':
            (t1)++;
            system("Pause");
            break;
        case '2':
            (t1)--;
            system("Pause");
            break;
        case '3':
            ++(t1);
            system("Pause");
            break;
        case '4':
            --(t1);
            system("Pause");
            break;
        case '5':
            do
            {
                system("cls");
                if (queue.get_k() == queue2.get_k())
                {
                    if ((queue.get_k() && queue2.get_k()) == 0)
                        cout << "Очереди пусты. Добавьте элементы." << endl;
                    else
                        cout << "В очередях одинаковое количество аргументов, функции разблокированы." << endl << queue.get_k() << " = " << queue2.get_k() << endl;
                }
                else
                    cout << "В очередях разное количество аргументов, функции заблокированы." << endl << queue.get_k() << " != " << queue2.get_k() << endl;
                cout << "[1] Добавь элементы в очередь №1" << endl;
                cout << "[2] Добавь элементы в очередь №2" << endl;
                cout << "[3] Выйти" << endl << "Ваш выбор: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    cout << "Выбрана Очередь №1" << endl;
                    queue.show();
                    cout << "Введите число: "; cin >> user_value;
                    queue += user_value;
                    cout << "Успех! Текущая очередь: "; queue.show(); cout << endl;
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    cout << "Выбрана Очередь №2" << endl;
                    queue2.show();
                    cout << "Введите число: "; cin >> user_value;
                    queue2 += user_value;
                    cout << "Успех! Текущая очередь: "; queue2.show(); cout << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (submenu != '3');
            break;
        case '6':
            system("cls");
            cout << "Очередь №1: "; queue.show(); cout << endl;
            cout << "Очередь №2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout << "Количество элементов в очередях не совпадает для выполнения функции!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "Сложение невозможно. Очереди пусты." << endl;
                system("pause");
                break;
            }
            queue3 = queue + queue2;
            cout << "Успех! Результат суммы двух очередей равен: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '7':
            do
            {
                system("cls");
                cout << "Очередь №1: "; queue.show(); cout << endl;
                cout << "Очередь №2: "; queue2.show(); cout << endl;
                if ((queue.get_k()) == 0) {
                    cout << "ВНИМАНИЕ! Очередь №1 - пуста. Извлечение невозможно." << endl;
                    system("pause");

                    if ((queue2.get_k()) == 0) {
                        cout << "ВНИМАНИЕ! Очередь №2 - пуста. Извлечение невозможно. Выход в главное меню." << endl;
                        system("pause");
                        break;
                    }
                }
                cout << "[1] Удалить элемент из очереди №1" << endl;
                cout << "[2] Удалить элемент из очереди №2" << endl;
                cout << "[3] Выйти" << endl << "Ваш выбор: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    queue -= 1;
                    cout << "Элемент удален успешно!" << endl;
                    cout << "Текущая очередь: "; queue.show();
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    queue2 -= 1;
                    cout << "Элемент удален успешно!" << endl;
                    cout << "Текущая очередь: "; queue2.show(); cout << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (submenu != '3');
            break;
        case '8':
            system("cls");
            cout << "Очередь №1: "; queue.show(); cout << endl;
            cout << "Очередь №2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout <<  "Количество элементов в очередях не совпадает для выполнения функции!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "Вычитание невозможно. Очереди пусты." << endl;
                system("pause");
                break;
            }
            queue3 = queue - queue2;
            cout << "Успех! Результат поэлементного вычитания равен: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '9':
            system("cls");
            cout << "Очередь №1: "; queue.show(); cout << endl;
            cout << "Очередь №2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout << "Количество элементов в очередях не совпадает для выполнения функции!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "Умножение невозможно. Очереди пусты." << endl;
                system("pause");
                break;
            }
            queue3 = queue * queue2;
            cout << "Успех! Результат поэлементного умножения равен: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '0':
            do
            {
                system("cls");
                if ((queue.get_k()) == 0) {
                    cout << "ВНИМАНИЕ! Очередь №1 - пуста. Деление невозможно." << endl;
                    system("pause");
                    if ((queue2.get_k()) == 0) {
                        cout << "ВНИМАНИЕ! Очередь №2 - пуста. Деление невозможно. Выход в главное меню." << endl;
                        system("pause");
                        break;
                    }
                }
                cout << "Очередь №1: "; queue.show(); cout << endl;
                cout << "Очередь №2: "; queue2.show(); cout << endl;
                cout << "[1] Делить на число очередь №1" << endl;
                cout << "[2] Делить на число очередь №2" << endl;
                cout << "[3] Выйти" << endl << "Ваш выбор: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    cout << "Выбрана Очередь №1" << endl;
                    queue.show();
                    cout << endl;
                    cout << "Введите число: "; cin >> divider;
                    if (!divider) {
                        cout << "Делить на 0 нельзя! Выход в подменю." << endl;
                        system("pause");
                        break;
                    }
                    queue3 = queue / divider;
                    cout << "Успех! Текущая очередь: "; queue3.show(); cout << endl;
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    cout << "Выбрана Очередь №2" << endl;
                    queue2.show();
                    cout << endl;
                    cout << "Введите число: "; cin >> divider;
                    if (!divider) {
                        cout << "Делить на 0 нельзя! Выход в подменю." << endl;
                        system("pause");
                        break;
                    }
                    queue3 = queue2 / divider;
                    cout << "Успех! Текущая очередь: "; queue3.show(); cout << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (submenu != '3');
            break;
        default:
            break;
        }
    } while (menu_value != 'x');
    return 0;
}