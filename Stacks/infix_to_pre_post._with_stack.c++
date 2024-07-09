// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std ; 

/**
 * @brief A generic stack data structure implemented using a linked list.
 *
 * This class provides a stack data structure that can store elements of any
 * type `T`. It supports the basic stack operations of pushing, popping, and
 * checking the top element. The stack is implemented using a linked list of
 * `StackNode` objects, where each node holds an element of type `T` and a
 * pointer to the next node in the list.
 */
template<class T> // T is the type of the data stored in the stack
class Stack {
    class StackNode { 
        public:
            T data ;
            StackNode *Next ;
            StackNode() : data(0), Next(nullptr) {} 
            StackNode(const T&data) : data(data), Next(nullptr) {}
    } ; 
    StackNode*TOP;
    int SIZE ;
public:
    Stack() : SIZE(0) , TOP(NULL) {} 
    void push (const T&data) { 
        StackNode* newNode = new StackNode(data) ; 
        if (empty()) TOP = newNode; 
        else newNode->Next = TOP , TOP = newNode ; 
        ++SIZE; 
    }
    void pop () { 
        if (empty() == false) { 
            StackNode* delNode = TOP ;
            TOP = TOP->Next ;
            --SIZE ;   
            delete delNode ; 
        }
    }
    bool empty () { 
        bool empty_stack = (TOP == NULL) ; 
        return  empty_stack ; 
    }
    int size () { return SIZE ; }
    T top () { if(empty() == 0) return TOP->data ; }
} ; 


/**
 * @brief Calculates the precedence of a given character
 *
 * @param op The operator to calculate the  for.
 * @return The precedence of the given char.
 */
int prcedance (char op) { 
    if (op == '^')  
        return 4 ; 
    if (op == '/' || op == '%' || op == '*')
        return 3 ;
    else if (op == '+' || op == '-') { 
        return 2 ; 
    } 
    else return -1 ; 
}

/**
 * @brief Checks if a given character is an alphabetic character (letter).
 *
 * @param c The character to be checked.
 * @return true if the character is an alphabetic character (letter), false otherwise.
 */
bool isAlpha (char c) { 
    bool is_Small_alphabet = ('a' <= c && c <= 'z') ; 
    bool is_Capital_alphabet = ('A' <= c && c <= 'Z') ; 
    return is_Small_alphabet || is_Capital_alphabet  ; 
}

 /**
 * @brief Checks if a given character is a digit character (0-9).
 *
 * @param c The character to be checked.
 * @return true if the character is a digit character, false otherwise.
 *  Note that this function only checks for the standard decimal digits (0-9) 
    and does not handle other numeral systems or non-ASCII digit characters.
 */
bool isDigit (char c) {
    bool isDicimalDigit = ('0' <= c && c <= '9') ;  
    return  isDicimalDigit ; 
}

/**
 * @brief Checks if a given character is a space character.
 *
 * @param c The character to be checked.
 * @return true if the character is a space, false otherwise.
 */
bool isSpace(char c) {
    return c == ' ';
}

/**
 * @brief Converts an infix expression to its equivalent postfix expression.
 *
 * @param expression The infix expression to be converted.
 * @return The equivalent postfix expression.
 * This function takes an infix expression as input and 
   converts it to its equivalent postfix expression using the Shunting-yard algorithm.
 
 @param Algorithm works as follows:
  j 1.Initialize an empty stack to store operators and output string to store the postfix expression.
   
   2.Scan the infix expression from left to right.

   3.For each character in the infix expression:   
      3.1 If the character is an operand (a digit or a variable), add it to the output string.
      3.2 If the character is an operator, do the following:
            3.2.1 Pop operators from the stack and add them to the output string until either the stack is empty or the operator at the top of the stack has higher precedence than the current operator.
            3.2.2 Push the current operator onto the stack.
      3.3 If the character is a left parenthesis '(', push it onto the stack.
      3.4 If the character is a right parenthesis ')', pop operators from the stack and add them to the output string until a left parenthesis '(' is encountered. Discard the left parenthesis.
      3.5 If the character is space
        3.5.1 continue to ignore this character 
   
   4.After scanning the entire infix expression, pop any remaining operators from the stack and add them to the output string.

   5.The resulting string is the postfix expression.
   
 * The function uses a stack to keep track of the operators and their precedence. It
 * also uses helper functions `isAlpha` and `isDigit` to identify operands, and a
 * function `precedance` (not shown) to determine the precedence of operators.
 * 
 * Some inputs and thier outputs:
    [1] AB*CF/+ => A*B+C/F
    [2] ABC+*F/ => A*(B+C)/F
    [3] ABCP-+*F/ => A*(B+(C-p))/F
    [4] (3+2)+7/2*((7+3)*2) => 32+72/73+2**+
    you can add more.. 
 */
string infixTOpostfix (string expression) { 
    string output = "" ; 
    Stack<char> operators ; 

    int len = expression.size() ; 
    for (int i = 0 ; i < len ; ++i) { 

        if (isSpace(expression[i])) 
            continue;

        if ( isAlpha(expression[i]) || isDigit(expression[i]) ) { 
            output.push_back(expression[i]) ; 
        } else if (expression[i] == '(') { 
            operators.push('(') ; 
        } else if (expression[i] == ')') { 
            while (operators.empty() == 0 && operators.top() != '(') {
                output.push_back(operators.top()) ;  
                operators.pop() ; 
            }
            operators.pop() ; 
        } else {
            while (operators.empty() == 0 &&  (prcedance(expression[i]) <= prcedance(operators.top()))) { 
                output+= operators.top() ; 
                operators.pop() ; 
            }
            operators.push(expression[i]) ; 
        }
    }
    while (operators.empty() == 0) { 
        output.push_back(operators.top());
        operators.pop() ; 
    }
    return output ; 
}

// Function to reverse the expression and replace brackets
/**
 * @brief Reverses the order of characters in the given expression string and swaps all opening and closing parentheses.
 *
 * @param expr The expression string to reverse and swap parentheses.
 * @return The reversed and swapped expression string.
 */
string reverseExpression(string expr){
    reverse(expr.begin(), expr.end());
    for (int i = 0; i < expr.size(); i++){
        if (expr[i] == '(')
            expr[i] = ')';
        else if (expr[i] == ')')
            expr[i] = '(';
    }
    return expr;
}

/**
 * @brief Converts an infix expression to a prefix expression.
 *
 * @param expression The infix expression to be converted.
 * @return The prefix expression.
 */
string infixToPrefix(string expression) {
    // Step 1: Reverse the infix expression
    string reversedInfix = reverseExpression(expression);

    // Step 2: Get the postfix of the reversed infix expression
    string postfix = infixTOpostfix(reversedInfix);

    // Step 3: Reverse the postfix expression to get prefix
    string prefix = reverseExpression(postfix);

    return prefix;
}


// ======================== evaluation postfix & prefix expression ========================

/**
 * @brief Performs arithmetic operation on two double-precision floating-point numbers.
 *
 * @param left_operand The left operand for the arithmetic operation.
 * @param op The arithmetic operator to be applied. Supported operators are: '+' (addition), '-' (subtraction), '/' (division), and '*' (multiplication).
 * @param right_operand The right operand for the arithmetic operation.
 *
 * @return The result of the arithmetic operation as a double-precision floating-point number.
 *
 * @note If the operator is not one of the supported operators, the function will not perform any operation and return 0.0.
 * @note If the operator is division ('/') and the right operand is 0.0, the behavior is undefined (may result in a division by zero error).
 */
double calc (double left_operand , char op , double right_operand) { 
    if (op == '+') return left_operand + right_operand ; 
    else if (op == '^') return  powf(left_operand,right_operand); 
    else if(op == '-') return left_operand - right_operand ; 
    else if (op == '/') return left_operand / right_operand ; 
    else if (op == '*') return left_operand * right_operand ; 
    // If the operator is not one of the supported operators, return 0.0
    return 0.0;
}

/**
 * @brief Evaluates the given mathematical expression and returns the result.
 *
 * @param expression The mathematical expression to evaluate, in infix notation.
 * @return The result of evaluating the expression.
 */
double evaluation_postfix (string expression) { 
    string postfix_expression = infixTOpostfix(expression) ; 
    Stack<double> evaluator ; 
    int len = postfix_expression.size() ; 
    for (int i = 0 ; i < len ; ++i) { 
        if (isDigit(postfix_expression[i])) { 
            evaluator.push(postfix_expression[i] - '0') ; 
        } else {
            double right_op  = evaluator.top() ; 
            evaluator.pop() ; 
            double left_op  = evaluator.top() ; 
            evaluator.pop() ; 
            evaluator.push(calc(left_op , postfix_expression[i]  , right_op)) ; 
        }
    }
    return evaluator.top() ; 
}

// out 
/**
 * @brief Evaluates a prefix expression and returns the result.
 *
 * @param expression The prefix expression to evaluate.
 * @return The result of evaluating the prefix expression.
 */
double evaluttion_prefix(string expression) { 
    string prefix = infixToPrefix(expression) ; 
    Stack<double> evaluator ; 

    int len = prefix.size() ; 
    for (int i = len - 1 ; i >= 0 ; --i) { 
        if (isDigit(prefix[i])) { 
            evaluator.push(prefix[i] - '0');
        }else {
             double left_op  = evaluator.top() ; 
             evaluator.pop() ; 
             double right_op  = evaluator.top() ; 
            evaluator.pop() ; 
            evaluator.push(calc(left_op , prefix[i]  , right_op)) ; 
        }
    }
    return evaluator.top() ; 
}

int main()  { 
    // here is some samples you can use . 
    string infixArray[] = {"A*B+C/F" , "A*(B+C)/F" , "A*(B+(C-p))/F" } ;
    
    cout << infixTOpostfix("5*2^(3+9)*2/4") << '\n' ; // 5239+^*2*4/ 
    cout << infixToPrefix("5*6/2+(5+2*5)/2") << '\n' ;  // *5*^2+39/24

    cout << evaluation_postfix("5+6/(5+6)^2*3") << '\n'  ;     // 10240
}
