// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct customException : public exception {
    virtual const char* what() const throw() {
        return "My name is Nick Els, and this is an error I created";
    }
};

bool do_even_more_custom_application_logic()
{
    // DONE: Throw any standard exception
    throw bad_exception(); //throws an error

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // DONE: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    if (do_even_more_custom_application_logic())
        cout << "Running Custom Application Logic." << endl;
    try { //start of wrap for function below
        if (do_even_more_custom_application_logic()) {
            cout << "Even More Custom Application Logic Succeeded." << endl;
        }
    }
    catch (const exception& exception) { //catch for function
        cerr << "Exception message: " << exception.what() << endl;
    }
    throw customException(); //custom excpetion to be caught in main

    // DONE: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // DONE: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) { //exception for dividing by zero
        throw runtime_error("you can not do that");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  DONE: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try { //try except for dividing
        auto result = divide(numerator, denominator);
        cout << "divide(" << numerator << ", " << denominator << ") = " << result << endl;
    }
    catch (const exception& exception) { //catch exception for divide
        cerr << "you still can not do this operation because: " << exception.what() << endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // DONE: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (const customException& exception) { //calling the catch defined earlier
        cerr << "Exception message: " << exception.what() << endl;
    }
    catch (...) {}//end of wrap for main function
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu