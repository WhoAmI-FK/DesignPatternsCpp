// test of the pattern
/*
using namespace validators;
int main()
{
    // test
    StringValidator* emailValidator = new BaseValidator;
    emailValidator
        ->setNext(new NotEmptyValidator)
        ->setNext(new RegexValidator("email adress",
            "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));
    std::cout << "Checking Emails ----------------\n";
    std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
    std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
    std::cout << "Input: shaun@test.com\n" <<
        emailValidator->validate("shaun@test.com") << "\n\n";
    delete emailValidator;
    // end test
    
    return 0;
}
*/