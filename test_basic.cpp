//hi
#include <iostream>
#include <string> // Include the string library
//
//#define MYTEST 1

int main() {

#if 0 // strings - Code to find length of string ///////////////////////////////
    // Declare a string variable
    std::string greeting = "Hello, world!";

    // Length of the string
    int len = greeting.length();
    std::cout << "Length of the string: " << len << std::endl;

    // Substring example
    std::string part = greeting.substr(7, 5); // "world"
    std::cout << "Substring: " << part << std::endl;
#endif

#if 0 // strings - Code to find length of string ///////////////////////////////
    // Declare a string variable
    std::string greeting = "Hello, world!";

    // Length of the string
    int len = greeting.length();
    std::cout << "Length of the string: " << len << std::endl;

    // Substring example
    std::string part = greeting.substr(7, 5); // "world"
    std::cout << "Substring: " << part << std::endl;
#endif
#if 0
#ifndef MYTEST
    // Declare a string variable
    std::string greeting = "Hello, world!";

    // Length of the string
    int len = greeting.length();
    std::cout << "Length of the string: " << len << std::endl;

    // Substring example
    std::string part = greeting.substr(7, 5); // "world"
    std::cout << "Substring: " << part << std::endl;
#endif
#endif
#if 1
    // Initialization
    std::string str = "Hello, world!";
#if 1
    std::cout << "Original string: " << str << std::endl;
#endif
#if 0
    // Length and size
    std::cout << "Length: " << str.length() << std::endl;
#endif
#if 0
    // Empty check
    std::cout << "Is empty: " << std::boolalpha << str.empty() << std::endl;
#endif
#if 0
    // Accessing characters
    std::cout << "First character: " << str[0] << std::endl;
#endif
#if 0
    // Appending
    str += " How are you?";
    str.append(" I'm fine.");
    std::cout << "After appending: " << str << std::endl;
#endif
#if 1
    // Insertion
    str.insert(13, "beautiful ");
    std::cout << "After insertion: " << str << std::endl;
#endif
#if 0
    // Erasing
    str.erase(5, 7);
    std::cout << "After erasing: " << str << std::endl;
#endif
#if 0
    // Clearing
    str.clear();
    std::cout << "After clearing: " << str << std::endl;
#endif
#if 0
    // Resetting the string
    str = "Hello, world!";
#endif
#if 1
    // Substring
    std::string substr = str.substr(7, 5);
    std::cout << "Substring: " << substr << std::endl;
#endif
#if 1
    // Finding substrings
    size_t pos = str.find("world");
    if (pos != std::string::npos) {
        std::cout << "\"world\" found at position: " << pos << std::endl;
    } else {
        std::cout << "\"world\" not found" << std::endl;
    }
#endif
#if 1
    // Replacing
    str.replace(7, 5, "universe");
    std::cout << "After replacing: " << str << std::endl;
#endif
#if 1
    // Comparing
    std::string str1 = "abc";
    std::string str2 = "def";
    int result = str1.compare(str2);
    std::cout << "Comparison result: " << result << std::endl;
#endif
#if 1
    // Conversion to C-string
    const char* cstr = str.c_str();
    std::cout << "C-string: " << cstr << std::endl;
#endif
#endif
    return 0;
}
