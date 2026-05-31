#include <iostream>
int main() {
    using std::cout;
    using std::string;

    string name;
    int age;

    cout << "What is your name: ";
    std::getline(std::cin, name );

    cout << "How old are you: ";
    std::cin >> age;

    cout << "Hello " << name << ", welcome to my world. Even though it's in theory for now. You are " << age << " years old. Now let's get this wedding started." << '\n';

    



    return 0;
}