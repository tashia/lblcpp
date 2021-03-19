// cpp17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <optional>

// std::optional demo
std::optional<std::string> CreateString(std::string_view str) {
    if (str.empty()) {
        return std::nullopt;
    }
    else {
        return std::string(str);
    }
}

void OptionalDemo() {
    std::string empty_input;
    auto result = CreateString("");
    if (!result.has_value()) {
        std::cout << "Empty input" << std::endl;
    }
    std::string valid_input("optional");
    auto result2 = CreateString(valid_input);
    if (result2.has_value()) {
        std::cout<<result2.value()<<std::endl;
    }
}

int main()
{
    OptionalDemo();
    std::cout << "Hello World!\n";
}
