#include <iostream>
 #include <string>
#include <regex>

namespace validators {
    class StringValidator {
    public:
        virtual ~StringValidator() {};
        virtual StringValidator* setNext(StringValidator* nextValidator) = 0;
        virtual std::string validate(std::string) = 0;

    };
    class BaseValidator : public StringValidator {
    protected:
        StringValidator* next = nullptr;
    public:
        virtual ~BaseValidator() {
            delete next;
        };
        StringValidator* setNext(StringValidator* nextValidator) override {
            next = nextValidator;
            return nextValidator;
        };
        virtual std::string validate(std::string testString) override {
            if (this->next) return this->next->validate(testString);

            return "Success!";
        }
    };
    class NotEmptyValidator : public BaseValidator {
    public:
        NotEmptyValidator() {};
        std::string validate(std::string testString) override {
            puts("Checking if empty...");
            if (testString.empty()) return "Please enter a value";
            return BaseValidator::validate(testString);
        }
    };
    class LengthValidator : public BaseValidator {
        int _minLength;
    public:
        LengthValidator(int minLength) :
            _minLength(minLength) {

        }
        std::string validate(std::string testString) override {
            puts("Checking string length...");
            if (testString.length() < _minLength) {
                return "Please enter a value longer than " + std::to_string(_minLength);
            }
            return BaseValidator::validate(testString);
        };
    };
    class RegexValidator : public BaseValidator {
    private:
        std::string _patternName;
        std::string _regexString;
    public:
        RegexValidator(std::string patternName, std::string regexString) :
            _patternName(patternName), _regexString(regexString) {

        };
        std::string validate(std::string testString) override {
            puts("Checking regex match...");
            if (!std::regex_match(testString, std::regex(_regexString))) {
                return "The value entered does not match the proper format for a " + _patternName;
            }
            return BaseValidator::validate(testString);
        };
    };
    bool in_array(const std::string& value, const std::vector<std::string>& array) {
        return std::find(array.begin(), array.end(), value) != array.end();
    }
    class HistoryValidator : public BaseValidator {
    private:
        std::vector<std::string> _historyItems;
    public:
        HistoryValidator(std::vector<std::string> historyItems)
            : _historyItems(historyItems)
        {
        }
        std::string validate(std::string testString) override {
            puts("Checking if string has been used before...");
            if (in_array(testString, _historyItems)) {
                return "Please enter a value here that you haven't entered before";
            }
            return BaseValidator::validate(testString);
        }
    };
};
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
