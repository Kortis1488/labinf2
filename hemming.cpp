#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string hem,hem2="0000000";
    int t = 1;
    while (t != 0) {
        t = 1;
        cout << "Введите число строго состоящее из 7 цифр в двоичной системе счисления\n";

        cin >> hem;
        if (hem.length() != 7) {
            if (hem.length() > 7) cout << "Вы ввели больше цифр чем ожидалось\n";
            else cout << "Вы ввели меньше цифр чем ожидалось\n\n";
            continue;
        }
        int hem1[7];
        for (int i = 0; i < 7; i++) {
            hem1[i] = 0;
            if (hem[i] != 48 and hem[i] != 49) {
                cout << "Вы ввели недопустимые символы\n\n";
                t = 2;
                break;

            }
            if (i == 2 or i == 4 or i == 5 or i == 6) {
                if (hem[i] == 48) {
                    hem1[i] = 0;
                }
                else {
                    hem1[i] = 1;
                }
            }
        }
        if (t == 2) continue;
        cout << "Представим, что изначальный код передан без ошибок\nОбнулим контрольные биты:\n\n";
        for (int i = 0; i < 7; i++) {
            cout << hem1[i];
        }
        cout << "\n\n";
        for (int i = 0; i < 7; i++) {
            if (i == 0) {
                hem1[i] = (hem1[2] + hem1[4] + hem1[6]) % 2;
            }
            if (i == 1) {
                hem1[i] = (hem1[2] + hem1[6] + hem1[5]) % 2;
            }
            if (i == 3) {
                hem1[i] = (hem1[4] + hem1[5] + hem1[6]) % 2;
            }
        }
        
        for (int i = 0; i < 7; i++) {
            if (hem1[i] == 1) hem2[i] = '1';
            else hem2[i] = '0';
        }
        cout << "Сравним ваш ввод и вывод программы:\n\n";
        cout << hem << endl << hem2<<endl<< endl;
        if (hem == hem2) {
            cout << "Вы ввели правильный код\n\n";
        }
        else cout << "Вы ввели неправильный код\n\n";
    }
}