#include <iostream>

int main(){
    //integer (whole number)
    int x = 5;
    int y = 6;
    int sum = x + y;
    int product = x * y;

    std::cout << x <<'\n';
    std::cout << y <<'\n';
    std::cout << sum <<'\n';
    std::cout << product <<'\n';

    //double (number including decimal)
    double price = 69.99; 
    double height = 1.78;
    double temperature = 18.4;



    //char (single character datatype)
    char grade = 'A';
    char key = 'C';
    char currency = '$';

   

    //boolean (true or false = 2 state only)
    bool single = true;
    bool available = false;

    //const variable allows for characters to remain unchanged or in read only. Writing the constant characters in capitals is essential.
    const double PI = 3.14159;
    double radius = 3.5;
    int circumference = 2 * PI * radius;

    std::cout << "The circumference of deez nuts is " << circumference << " cm." << '\n';

    // Namespaces allow for indentically named entities and prevents naming conflicts (using namespace first/second)
    // (using namespace std), (using std::cout, using std::string)
    // the two latter saves for a lot of typing
    using std::cout;
    using text_t = std::string;
    // the second one is like typedef - gives new indentifier (nickname) to an existing, longer datatype. Helps to reduce typos
    // typedef std::string text_t (works like the "using" one. however using is better)

    //string (objects that represents a sequence of text)
    text_t name = "Mitchel Maritim";
    text_t scale = "F Major";
    text_t drink = "Predator";
    text_t church = "Agape Community Church Ruaka";
    text_t day = "Sunday";

    cout << "Hello " << name << " and good morning to you." <<'\n';
    cout << "You're welcomed to my church, " << church << " this " << day << " where I'll be singing on your least favorite key, " << scale << '\n';
    cout << "Rest assured you'll see me feast on some cold milk as I walk you home since I stopped taking " << drink << " which costs Ksh." << price << '\n';
    cout << "And only then would I sing for you in your somehow favorite key, " << key << ", as the wind breezes on our skins in the very cool " << temperature << "^C." << '\n';


return 0;
}