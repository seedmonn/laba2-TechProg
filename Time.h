#include <cmath>
#include <iostream>

using namespace std;

class Time
{
private: 
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {};

    void changePlusPlus() {
        char c; int user_value;
        do
        {
            system("cls");
            cout << "��� ������ ���������, ����?" << endl;
            cout << "[1] ����" << endl;
            cout << "[2] ������" << endl;
            cout << "[3] �������" << endl;
            cout << "[4] �����" << endl;
            cout << "��� �����: ";
            cin >> c;
            switch (c)
            {
            case '1':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                hours = hours + user_value;
                cout << "������, ����! ������� ��� ������: " << hours << endl;
                system("pause");
                break;
            case '2':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                minutes = minutes + user_value;
                cout << "������, ����! ������� �������� ����� ������: " << minutes << endl;
                system("pause");
                break;
            case '3':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                seconds = seconds + user_value;
                cout << "������, ����! ������� �������� ������ ������: " << seconds << endl;
                system("pause");
                break;
            case '4':
                c = '4';
            default:
                break;
            }
        } while (c != '4');
    }
    
    void changeMinusMinus() {
        char c; int user_value;
        do
        {
            system("cls");
            cout << "��� ������ ���������, ����?" << endl;
            cout << "[1] ����" << endl;
            cout << "[2] ������" << endl;
            cout << "[3] �������" << endl;
            cout << "[4] �����" << endl;
            cout << "��� �����: ";
            cin >> c;
            switch (c)
            {
            case '1':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                hours = hours - user_value;
                cout << "������, ����! ������� ��� ������: " << hours << endl;
                system("pause");
                break;
            case '2':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                minutes = minutes - user_value;
                cout << "������, ����! ������� �������� ����� ������: " << minutes << endl;
                system("pause");
                break;
            case '3':
                system("cls");
                cout << "�� ������� ���������, ����?" << endl << "=> ";
                cin >> user_value;
                seconds = seconds - user_value;
                cout << "������, ����! ������� �������� ������ ������: " << seconds << endl;
                system("pause");
                break;
            case '4':
                c = '4';
            default:
                break;
            }
        } while (c != '4');
    }

    Time operator++(int) {
        changePlusPlus();
        return *this;
    }

    Time operator--(int) {
        changeMinusMinus();
        return *this;
    }

    friend Time &operator++(Time &time) {
        char c; int user_value;
        do
        {
            system("cls");
            cout << "��� ������ ���������, ����?" << endl;
            cout << "[1] ����" << endl;
            cout << "[2] ������" << endl;
            cout << "[3] �������" << endl;
            cout << "[4] �����" << endl;
            cout << "��� �����: ";
            cin >> c;
            switch (c)
            {
            case '1':
                system("cls");
                time.hours = time.hours + 1;
                cout << "������, ����! ������� ��� ������: " << time.hours << endl;
                system("pause");
                break;
            case '2':
                system("cls");
                time.minutes = time.minutes + 1;
                cout << "������, ����! ������� �������� ����� ������: " << time.minutes << endl;
                system("pause");
                break;
            case '3':
                system("cls");
                time.seconds = time.seconds + 1;
                cout << "������, ����! ������� �������� ������ ������: " << time.seconds << endl;
                system("pause");
                break;
            case '4':
                c = '4';
            default:
                break;
            }
        } while (c != '4');
        return time;
    }

    friend Time &operator--(Time &time) {
        char c; int user_value;
        do
        {
            system("cls");
            cout << "��� ������ ���������, ����?" << endl;
            cout << "[1] ����" << endl;
            cout << "[2] ������" << endl;
            cout << "[3] �������" << endl;
            cout << "[4] �����" << endl;
            cout << "��� �����: ";
            cin >> c;
            switch (c)
            {
            case '1':
                system("cls");
                time.hours = time.hours - 1;
                cout << "������, ����! ������� ��� ������: " << time.hours << endl;
                system("pause");
                break;
            case '2':
                system("cls");
                time.minutes = time.minutes - 1;
                cout << "������, ����! ������� �������� ����� ������: " << time.minutes << endl;
                system("pause");
                break;
            case '3':
                system("cls");
                time.seconds = time.seconds - 1;
                cout << "������, ����! ������� �������� ������ ������: " << time.seconds << endl;
                system("pause");
                break;
            case '4':
                c = '4';
            default:
                break;
            }
        } while (c != '4');
        return time;
    }

    friend ostream &operator << (ostream &s, Time &time)
    {
        return cout << "����: " << time.hours << " ������: " << time.minutes << " �������: " << time.seconds;
    }     //����������� �������� ������ ��� ������ �������
    };