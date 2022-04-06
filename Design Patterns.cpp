#include <iostream>


namespace whoamifk {
    class User {
    private:
        std::string _name;
        std::string _email;
        std::string _password;
    public:
        explicit User() = default;

    };

}

int main()
{
    std::cout << "Hello World!\n";
}
