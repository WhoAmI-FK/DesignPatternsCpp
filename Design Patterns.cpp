#include <iostream>


namespace Auth {
    class User {
    private:
        std::string _name;
        std::string _email;
        std::string _password;
    public:
        explicit User() = default;

    };

}
