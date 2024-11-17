#include <iostream>
#include <windows.h>
using namespace std;

class Pet
{
protected:
    char* name;
public:
    Pet(const char* Name) 
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
    }

    virtual void Sound() const = 0;
    virtual void Show() const 
    {
        cout << "Name: " << name << endl;
    }
    virtual void Type() const = 0;

    virtual ~Pet() 
    {
        if (name != nullptr) 
        {
            delete[] name;
        }
    }
};

class Dog : public Pet 
{
public:
    Dog(const char* Name) : Pet(Name) {}

    void Sound() const
    {
        cout << "Woof" << endl;
    }

    void Type() const
    {
        cout << "Dog" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(const char* Name) : Pet(Name) {}

    void Sound() const
    {
        cout << "Meow" << endl;
    }

    void Type() const
    {
        cout << "Cat" << endl;
    }
};

class Parrot : public Pet 
{
public:
    Parrot(const char* Name) : Pet(Name) {}

    void Sound() const
    {
        cout << "Kaar" << endl;
    }

    void Type() const
    {
        cout << "Parrot" << endl;
    }
};

class Hamster : public Pet 
{
public:
    Hamster(const char* Name) : Pet(Name) {}

    void Sound() const
    {
        cout << "Squi" << endl;
    }

    void Type() const
    {
        cout << "Hamster" << endl;
    }
};

int main() 
{
   
    Pet* pets[4] = 
    {
        new Dog("Lucky"),
        new Cat("Motya"),
        new Parrot("Patrick"),
        new Hamster("Buddy")
    };

    for (int i = 0; i < 4; ++i) 
    {
        pets[i]->Show();
        pets[i]->Type();
        pets[i]->Sound();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i)
    {
        delete pets[i];
    }

    system("pause");
    return 0;
}
