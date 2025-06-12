#include <iostream>
#include "BoxRuntime.hpp"

void ChangeNumberFromVoidPtr(void *ptr);
void ChangeNumberFromRef(int &a);

// In Struct Member is public as default
struct Person
{
    int age;

    void ModifyAge()
    {
        age = 17;
    }

    static void StaticModifyAge(Person &other)
    {
        other.age = 30;
    }
};

void ModifyPersonAge(Person person);
void ModifyPersonAgeFromRef(Person &person);

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::cout << "==========================================" << std::endl;

    auto a = 1;
    std::cout << "origin a: " << a << std::endl;

    // 这是转成指针
    ChangeNumberFromVoidPtr(&a);
    std::cout << "Changed By Ptr a: " << a << std::endl;

    ChangeNumberFromRef(a);
    std::cout << "Changed By Ref a: " << a << std::endl;

    std::cout << "==========================================" << std::endl;

    Person person;
    person.age = 18;
    std::cout << "origin person.age: " << person.age << std::endl;

    person.ModifyAge();
    std::cout << "ModifyAge: " << person.age << std::endl;

    // Struct is value type
    // Not Working
    ModifyPersonAge(person);
    std::cout << "ModifyPersonAge: " << person.age << std::endl;

    // Working
    ModifyPersonAgeFromRef(person);
    std::cout << "ModifyPersonAgeFromRef: " << person.age << std::endl;

    Person::StaticModifyAge(person);
    std::cout << "Person::StaticModifyAge: " << person.age << std::endl;

    std::cout << "==========================================" << std::endl;

    BoxRuntime::main();
}

void ChangeNumberFromVoidPtr(void *ptr)
{
    std::cout << "numberPointer: " << ptr << std::endl;

    // 写指针里的值
    *static_cast<int *>(ptr) = 2;

    // 写指针里的值
    auto numberPtr = static_cast<int *>(ptr);
    *numberPtr = 3;

    // 写指针里的值
    auto number = *numberPtr;
    number = 4;
}

void ChangeNumberFromRef(int &a)
{
    a = 10;
}

void ModifyPersonAge(Person person)
{
    person.age = 19;
}

void ModifyPersonAgeFromRef(Person &person)
{
    person.age = 20;
}
