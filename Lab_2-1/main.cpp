#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);// зашифровывание
        if (destructCipherText)// надо "портить"?
            cipherText.front() = tolower(cipherText.front());// "портим"
        decryptedText = cipher.decrypt(cipherText);
        wcout<<"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
// установка глобальной локали
    check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"Simple");
    check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"");
    check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"ABCD123");
    check(L"The Quick Brown Fox Jumps Over The Lazy Dog",L"SUPER");
    check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"TOPSECRET",true);
    check(L"123",L"ABCD");
    return 0;
}