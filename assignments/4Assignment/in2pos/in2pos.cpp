#include <iostream>
#include <stack>
#include <map>
#include <string>
//Aritmetic Expression

//  / does integer division
// ^ will always be >= 0



bool it_is_a_number(char c, bool outlier){
    return  (c >= '0' && c <= '9') || (outlier && c == '-');
}

bool it_is_an_operator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


int order(char c){
    std::map<char, int> post_order;
    //Opposite of PEMDAS
    post_order['+'] = 1;
    post_order['-'] = 1;
    post_order['*'] = 2;
    post_order['/'] = 2;
    post_order['^'] = 3;

    return post_order[c];
}

void pop_operators(std::stack<char>& operators, std::string& postfix, char input){

    while(operators.size()!= 0 &&
    (order(operators.top()) > order(input) ||
      order(operators.top()) == order(input) && input != '^'  ) ){
        
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
      }



}

std::string infix_to_postfix(std::string& infix){
    std::stack<char> operators;
    std::string postfix;

    for(int i = 0; i < infix.size(); i++){
        char input = infix[i];

        bool outlier = (i == 0 || infix[i - 1] == '(') && input == '-';

        if(it_is_a_number(input,outlier)){
            postfix += input;

            if (i + 1 < infix.size() && !it_is_a_number(infix[i + 1], false) && infix[i + 1] != ' ') {
                postfix += ' ';
            }


        }
        else if(input == '('){
            operators.push(input);
        }
        else if(input == ')'){
            while(operators.size() != 0 && operators.top() != '('){
                postfix += ' ';//Adding spaces between each number
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if(it_is_an_operator(input)){
            pop_operators(operators, postfix, input);
            operators.push(input);
        }

    }

    while(operators.size() != 0){
        postfix += operators.top();
        postfix += ' '; //Adding spaces between each number
        operators.pop();
    }

    return postfix;



}

int main(int argc, char* argv[]){

    std::string infix_input = argv[1];
    std::string postfix_output = infix_to_postfix(infix_input);
    std::cout << postfix_output << std::endl;
    

    //  Infix 
    // 1. any number is a valid infix expression
    // 2. if E is an infix expression, then '( E )' is an infix expression
    // 3. if E1 and E2 are infix expressions, and OP is an operator, then 'E1 OP E2' is an infix expression

    // Postfix
    //1. any number is a valid postfix expression
    // 2. if P1 and P2 are postfix expressions, and OP is an operator, then 'P1 P2 OP' is a postfix expression

    // if left parenthesis
    //     push it onto the stack
    // if operator
    //     pop and write to the output string all consecutive operators that are either operators of higher precedence; or left-associative operators of equal precedence
    //     push the operator onto the stack
    // if right parenthesis
    //     pop and write to the output string all operators until a left parenthesis is popped off the stack
    // if number
    //     it may be immediately written to the output string
    // if end of the string
    //     pop and write to the output string all operators until the stack is empty




}