#include "GCharacter.h"

using namespace std;

// constructor.
GCharacter::GCharacter(string name, int capacity)
{
    this->name = name;
    this->capacity = capacity;
    used = 0;
    toolBox = new string[capacity];
}

// copy constructor.
GCharacter::GCharacter(GCharacter& source)
{
    cout << "Copye constructor is called." << endl;

    this->name = source.name;
    this->capacity = source.capacity;
    this->used = source.used;
    this->toolBox = new string[source.capacity];

    copy(source.toolBox, source.toolBox + source.used, this->toolBox);
}

// Overloaded Assignment Operator.
GCharacter& GCharacter::operator=(const GCharacter& source)
{
    cout << "Overloaded Assignment Operator is called." << endl;
    
    if (this == &source)
    {
        return *this;
    }
    else
    {
        this->name = source.name;
        this->capacity = source.capacity;
        this->used = source.used;
        
        copy(source.toolBox, source.toolBox + source.used, this->toolBox);
    }
    return *this;
}   


// destructor.
GCharacter::~GCharacter()
{
    cout << "Deconstructor is called." << endl;
    delete[] toolBox;
}

// Inserting a new tool into our toolBox
void GCharacter::insert(const string& toolName)
{
    if (this->used == this->capacity)
    {
        cout << "The toolBox is full. Can't add any additional tools." << endl;
    }
    else
    {
        toolBox[this->used] = toolName;
        this->used++;
    }
}


std::ostream& operator<<(std::iostream os, const GCharacter& gc)
{
    os << "Game Character " << gc.name <<
        "\nhas the following tools:" << std::endl << "| ";

    for (int i = 0; i < gc.used; i++)
    {
        os << gc.toolBox[i] + " | ";
    }
    return os << std::endl;
}

