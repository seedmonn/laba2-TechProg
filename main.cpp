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
        cout << "\n�������� ��������" << endl;
        cout << "[1] ++(����������� �����, �����). ��������� �� ��� �����: ������, �������, ����" << endl;
        cout << "[2] --(����������� �����, �����). ��������� �� ��� �����: ������, �������, ����" << endl;
        cout << "[3] ++(���������� �����, ������������� �������) ����������� �� ����� ������������ ���� �������, ���� ������, ���� ���� �� �������." << endl;
        cout << "[4] --(���������� �����, ������������� �������) ��������� �� ����� ������������ ���� �������, ���� ������, ���� ���� �� �������." << endl << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        cout << "������� �1: "; queue.show(); cout << endl;
        cout << "������� �2: "; queue2.show(); cout << endl;
        cout << "[5] += ���������� �������� � ������� (������������� �������)" << endl;
        cout << "[6] + �������� ���� �������� (�����)" << endl;
        cout << "[7] =- ��� ���������� �������� �� �������(�����)" << endl;
        cout << "[8] - ��� ��������� �������� ���� � ������ (������������� �������)" << endl;
        cout << "[9] * ��� ������������� ��������� �������� ���� �� �����(�����)" << endl;
        cout << "[0] / ��� ������� ������� �� �����(�����)" << endl;
        cout << "[x] �����" << endl;
        cout << "��� �����: ";
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
                        cout << "������� �����. �������� ��������." << endl;
                    else
                        cout << "� �������� ���������� ���������� ����������, ������� ��������������." << endl << queue.get_k() << " = " << queue2.get_k() << endl;
                }
                else
                    cout << "� �������� ������ ���������� ����������, ������� �������������." << endl << queue.get_k() << " != " << queue2.get_k() << endl;
                cout << "[1] ������ �������� � ������� �1" << endl;
                cout << "[2] ������ �������� � ������� �2" << endl;
                cout << "[3] �����" << endl << "��� �����: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    cout << "������� ������� �1" << endl;
                    queue.show();
                    cout << "������� �����: "; cin >> user_value;
                    queue += user_value;
                    cout << "�����! ������� �������: "; queue.show(); cout << endl;
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    cout << "������� ������� �2" << endl;
                    queue2.show();
                    cout << "������� �����: "; cin >> user_value;
                    queue2 += user_value;
                    cout << "�����! ������� �������: "; queue2.show(); cout << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (submenu != '3');
            break;
        case '6':
            system("cls");
            cout << "������� �1: "; queue.show(); cout << endl;
            cout << "������� �2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout << "���������� ��������� � �������� �� ��������� ��� ���������� �������!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "�������� ����������. ������� �����." << endl;
                system("pause");
                break;
            }
            queue3 = queue + queue2;
            cout << "�����! ��������� ����� ���� �������� �����: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '7':
            do
            {
                system("cls");
                cout << "������� �1: "; queue.show(); cout << endl;
                cout << "������� �2: "; queue2.show(); cout << endl;
                if ((queue.get_k()) == 0) {
                    cout << "��������! ������� �1 - �����. ���������� ����������." << endl;
                    system("pause");

                    if ((queue2.get_k()) == 0) {
                        cout << "��������! ������� �2 - �����. ���������� ����������. ����� � ������� ����." << endl;
                        system("pause");
                        break;
                    }
                }
                cout << "[1] ������� ������� �� ������� �1" << endl;
                cout << "[2] ������� ������� �� ������� �2" << endl;
                cout << "[3] �����" << endl << "��� �����: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    queue -= 1;
                    cout << "������� ������ �������!" << endl;
                    cout << "������� �������: "; queue.show();
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    queue2 -= 1;
                    cout << "������� ������ �������!" << endl;
                    cout << "������� �������: "; queue2.show(); cout << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (submenu != '3');
            break;
        case '8':
            system("cls");
            cout << "������� �1: "; queue.show(); cout << endl;
            cout << "������� �2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout <<  "���������� ��������� � �������� �� ��������� ��� ���������� �������!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "��������� ����������. ������� �����." << endl;
                system("pause");
                break;
            }
            queue3 = queue - queue2;
            cout << "�����! ��������� ������������� ��������� �����: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '9':
            system("cls");
            cout << "������� �1: "; queue.show(); cout << endl;
            cout << "������� �2: "; queue2.show(); cout << endl;
            if (queue.get_k() != queue2.get_k()) {
                cout << "���������� ��������� � �������� �� ��������� ��� ���������� �������!" << endl;
                system("pause");
                break;
            }
            if ((queue.get_k() && queue2.get_k()) == 0) {
                cout << "��������� ����������. ������� �����." << endl;
                system("pause");
                break;
            }
            queue3 = queue * queue2;
            cout << "�����! ��������� ������������� ��������� �����: "; queue3.show(); cout << endl;
            system("pause");
            break;
        case '0':
            do
            {
                system("cls");
                if ((queue.get_k()) == 0) {
                    cout << "��������! ������� �1 - �����. ������� ����������." << endl;
                    system("pause");
                    if ((queue2.get_k()) == 0) {
                        cout << "��������! ������� �2 - �����. ������� ����������. ����� � ������� ����." << endl;
                        system("pause");
                        break;
                    }
                }
                cout << "������� �1: "; queue.show(); cout << endl;
                cout << "������� �2: "; queue2.show(); cout << endl;
                cout << "[1] ������ �� ����� ������� �1" << endl;
                cout << "[2] ������ �� ����� ������� �2" << endl;
                cout << "[3] �����" << endl << "��� �����: ";
                cin >> submenu;
                switch (submenu)
                {
                case '1':
                    system("cls");
                    cout << "������� ������� �1" << endl;
                    queue.show();
                    cout << endl;
                    cout << "������� �����: "; cin >> divider;
                    if (!divider) {
                        cout << "������ �� 0 ������! ����� � �������." << endl;
                        system("pause");
                        break;
                    }
                    queue3 = queue / divider;
                    cout << "�����! ������� �������: "; queue3.show(); cout << endl;
                    system("pause");
                    break;
                case '2':
                    system("cls");
                    cout << "������� ������� �2" << endl;
                    queue2.show();
                    cout << endl;
                    cout << "������� �����: "; cin >> divider;
                    if (!divider) {
                        cout << "������ �� 0 ������! ����� � �������." << endl;
                        system("pause");
                        break;
                    }
                    queue3 = queue2 / divider;
                    cout << "�����! ������� �������: "; queue3.show(); cout << endl;
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