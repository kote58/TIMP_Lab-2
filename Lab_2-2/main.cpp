#include "modRoutingCipher.h"
#include <string>
#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;
int main(int argc, char **argv)
{
int a; int b = 0; string s;
cout << "\t\t\t\t-----MENU-----"<< endl;
cout << "\t\tПРОГРАММА ДЛЯ ШИФРОВАНИЯ МЕТОДОМ МАРШРУТНОЙ КАРТЫ" << endl;
cout << "Введите ключ: ";
cin >> a; 
cout << endl;
try {
if (a<=0)
{throw "the table cannot contain negative and zero";}
}
catch (const string str)
{
cout << str << endl;
exit(1);
}
modRoutingCipher c{a};
cout << "1) Зашифровать сообщение" << endl;
cout << "2) Дешифровать сообщение" << endl;
cin >> b;
cout << "Введите сообщение: " << endl;
cin >> s;
try {
setlocale(LC_ALL, "Russian");
locale loc("ru_RU.UTF-8");
wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
wstring ws = codec.from_bytes(s);
if (ws.size()%b<0)
{throw "It is not possible to encrypt and decrypt or decrypt a message";}
}
catch (const string str) {
cout << str << endl;
exit(2);
}
if (b == 1) {
string s1 = c.encrypt(s);
cout << "Зашифрованное сообщение: " << s1 << endl;
}
if (b == 2) {
string s2 = c.decrypt(s);
cout << "Дешифрованное сообщение: " << s2 << endl;
}
return 0;
}