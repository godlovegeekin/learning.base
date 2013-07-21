#ifndef _GCHARACTER_H_

#include <iostream>
#include <string>

class GCharacter
{
        friend std::ostream& operator<<(std::ostream& os, const GCharacter& gc);

    public:

        static const int DEFAULT_CAPACITY = 5;

        // constructor.
        GCharacter(std::string name = "john", int capacity = DEFAULT_CAPACITY);

        // copy constructor
        GCharacter(const GCharacter& source);

        // Overloaded Assignment
        GCharacter& operator=(const GCharacter& source);

        // Deconstrutor
        ~GCharacter();
        
        // insert a tool to a toolbar.
        void insert(std::string toolName);

    private:
        // class members.
        std::string name;
        int capacity;
        int used;
        std::string* toolBox;
}

#define _GCHARACTER_H_
#endif
