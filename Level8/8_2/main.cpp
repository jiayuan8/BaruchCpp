/* main.cpp
 * ----------------------------------------------
 * @description: test functionality of shared_ptr
 * @author: Jiayuan Li
 * @version: 1.0 Jan 18th 2020
 */


#include <iostream>
#include <boost/tuple/tuple.hpp>

typedef boost::tuple<std::string, unsigned, double> Person;

#define NAME      0
#define AGE       1
#define HEIGHT    2

// helper function declaration
void PrintPerson(const Person& tuple_person);

int main()
{
    // create 3 person objects
    Person person1("John", 17, 111.11);
    Person person2("Marry", 19, 333.33);
    Person person3("Johnson", 21, 999.99);

    // print the 3 people out
    PrintPerson(person1);
    PrintPerson(person2);
    PrintPerson(person3);

    // increment one person's age by 10
    person1.get<AGE>() += 10;

    // print out the incremented info
    PrintPerson(person1);

    return 0;
}

void PrintPerson(const Person& tuple_person)
{
    std::cout << "--------------------------------\n";
    std::cout << "Name:    " << tuple_person.get<NAME>() << std::endl; 
    std::cout << "Age:     " << tuple_person.get<AGE>() << std::endl; 
    std::cout << "Height:  " << tuple_person.get<HEIGHT>() << std::endl; 
    std::cout << "--------------------------------\n";
}
