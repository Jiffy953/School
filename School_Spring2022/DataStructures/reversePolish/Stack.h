//
// Created by Jared See on 11/8/21.
//

#ifndef REVERSEPOLISH_STACK_H
#define REVERSEPOLISH_STACK_H

class Stack {
    std::vector<double> stack;
public:
    void push(int data)
    {
        stack.push_back(data);
    }

    void pop()
    {
        stack.pop_back();
    }
    void size()
    {
        int count=0;
        for (auto i: stack)
        {
            count++;
        }
        std::cout << "Size: " << count << std::endl;
    }
    void top()
    {
        std::cout << "Top: " << stack.back() << std::endl;
    }
    double evaluate()
    {
        if (top() == '+')
        {

        }
        if (top() == '-')
        {

        }
        if (top() == '*')
        {

        }
        if (top() == '/')
        {

        }
        if (top() == '+')
        {

        }
    }
};


#endif //REVERSEPOLISH_STACK_H
