#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main() 
{
    //Blocks assigning the given grammar
    map<char, string> E = {
        {'a', "TQ"},
        {'(', "TQ"}
    };
    map<char, string> Q = {
        {'+', "+TQ"},
        {'-', "-TQ"},
        {')', ""},
        {'$', ""}
    };
    map<char, string> T = {
        {'a', "FR"},
        {'(', "FR"}
    };
    map<char, string> R = {
        {'+', ""},
        {'-', ""},
        {'*', "*FR"},
        {'/', "/FR"},
        {')', ""},
        {'$', ""}
    };
    map<char, string> F = {
        {'a', "a"},
        {'(', "(E)"}
    };

    //Declaration of starting symbol
    string startSymbol = "E";
    string userInput = "";
    std::cout << "Input string to test (input STOP to terminate)" << endl;
    std::cout << "Input: ";

    //Outer loop to take in multiple user inputs to test
    while(cin >> userInput)
    {
        //Guard of the loop
        if (userInput == "STOP")
        {
            break;
        }
        
        
        //Creation of User Stack
        stack<char> userStack;
        for (int i = userInput.length()-1; i >= 0; i--)
        {
            userStack.push(userInput[i]);
        }
        
        //Creation of our Stack
        stack<char> myStack;
        myStack.push('$');
        myStack.push(startSymbol[0]);

        stack<char> tempStack;
        
        while(!userStack.empty() && !myStack.empty())
        {
            //block to print out the stack at each stage
            std::cout << "Stack: [ ";
            while(!myStack.empty())
            {
                tempStack.push(myStack.top());
                myStack.pop();
            }
            while(!tempStack.empty())
            {
                std::cout << tempStack.top() << " ";
                myStack.push(tempStack.top());
                tempStack.pop();
            }
            std::cout << "]" << endl;

            //Check if tops of both stacks match
            if (myStack.top() != userStack.top())
            {
                char temp = userStack.top();
                string next;
                //Switch cases for a given Non-Terminal
                switch(myStack.top()) 
                {
                    case 'E':
                    if (E.find(temp) == E.end())
                    {
                        std::cout << "Output: String is not accepted/invalid" << endl;
                        return 0;
                    }
                    next = E[temp];
                    myStack.pop();
                    for (int i = next.length()-1; i >=0; --i)
                    {
                        myStack.push(next[i]);
                    }
                    break;

                    case 'Q':
                    if (Q.find(temp) == Q.end())
                    {
                        std::cout << "Output: String is not accepted/invalid" << endl;
                        return 0;
                    }
                    next = Q[temp];
                    myStack.pop();
                    for (int i = next.length()-1; i >=0; --i)
                    {
                        myStack.push(next[i]);
                    }
                    break;

                    case 'T':
                    if (T.find(temp) == T.end())
                    {
                        std::cout << "Output: String is not accepted/invalid" << endl;
                        return 0;
                    }
                    next = T[temp];
                    myStack.pop();
                    for (int i = next.length()-1; i >=0; --i)
                    {
                        myStack.push(next[i]);
                    }
                    break;

                    case 'R':
                    if (R.find(temp) == R.end())
                    {
                        std::cout << "Output: String is not accepted/invalid" << endl;
                        return 0;
                    }
                    next = R[temp];
                    myStack.pop();
                    for (int i = next.length()-1; i >=0; --i)
                    {
                        myStack.push(next[i]);
                    }
                    break;

                    case 'F':
                    if (F.find(temp) == F.end())
                    {
                        std::cout << "Output: String is not accepted/invalid" << endl;
                        return 0;
                    }
                    next = F[temp];
                    myStack.pop();
                    for (int i = next.length()-1; i >=0; --i)
                    {
                        myStack.push(next[i]);
                    }
                    break;
                }
            }
            else
            {
                //Top of both stacks match means we pop them
                userStack.pop();
                myStack.pop();
            }
        }
        if (userStack.empty() && myStack.empty())
        {
            std::cout << "Output: String is accepted/valid \n" << endl;
        }
        else
        {
            std::cout << "Output: String is not accepted/invalid \n" << endl;
        }
        
        std::cout << "Input string to test (input STOP to terminate)" << endl;
        std::cout << "Input: ";
    }

    return 0;
}