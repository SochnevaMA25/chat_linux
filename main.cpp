#include "Message.cpp"
#include "User.cpp"
#include <iostream>
#include <string>
//love m.Sochneva//
using namespace std;
int main()
{
    string name;
    string login;
    string pass;
    cout << "Name: " << endl;
    cin >> name;
    cout << "Login: " << endl;
    cin >> login;
    cout << "Pass: " << endl;
    cin >> pass;
    User user(name, login, pass);
    string receiver;
    string text;
    cout << "Receiver: " << endl;
    cin >> receiver;
    cout << "Text: " << endl;
    cin >> text;
    Message m(receiver, name, text);
    return 0;
}
