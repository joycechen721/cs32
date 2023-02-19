//
//  eval.cpp
//  Homework2
//
//  Created by Joyce Chen on 2/3/23.
//

#include "Set.h"  // with ItemType being a type alias for char
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

//declarations of any additional functions you might have written to help you evaluate an expression
int evaluate(string infix, const Set& trueValues, const Set& falseValues, string& postfix, bool& result);
string toPostfix(string infix);
bool evalPostfix(string postfix, const Set& trueValues);
bool checkPrecedence(char c1, char c2);
bool isOperator(char ch);
bool isValid(string infix);
int appearance(string infix, const Set& trueValues, const Set& falseValues);

int evaluate(string infix, const Set& trueValues, const Set& falseValues, string& postfix, bool& result){
    if(!isValid(infix)) return 1;
    postfix = toPostfix(infix);
    int returnNum = appearance(infix, trueValues, falseValues);
    if(returnNum == 0){
        result = evalPostfix(postfix, trueValues);
    }
    return returnNum;
}

//implementations of any additional functions you might have written to help you evaluate an expression
string toPostfix(string infix){
    string postfix = "";
    stack<char> optrStack;
    for(int i = 0; i < infix.size(); i++){
        char ch = infix.at(i);
        if(isspace(ch)) continue;
        if(isalpha(ch)){
            postfix += ch;
        }
        else if (ch == '('){
            optrStack.push(ch);
        }
        else if (ch == ')'){
            while(optrStack.top() != '('){
                postfix += optrStack.top();
                optrStack.pop();
            }
            optrStack.pop(); // remove the '('
        }
        else{
            while(!optrStack.empty() && optrStack.top() != '(' && checkPrecedence(optrStack.top(), ch)){
                postfix += optrStack.top();
                optrStack.pop();
            }
            optrStack.push(ch);
        }
    }
    while(!optrStack.empty()){
        postfix += optrStack.top();
        optrStack.pop();
    }
    return postfix;
}

bool evalPostfix(string postfix, const Set& trueValues){
    stack<char> operandStack;
    for(char ch : postfix){
        if(isalpha(ch)){
            operandStack.push(trueValues.contains(ch));
        }
        else if(ch == '!'){
            bool operand1 = operandStack.top();
            operandStack.pop();
            operandStack.push(!operand1);
        }
        else{
            bool operand1 = operandStack.top();
            operandStack.pop();
            bool operand2 = operandStack.top();
            operandStack.pop();
            switch(ch){
                case '&':
                    operandStack.push(operand1 && operand2);
                    break;
                default:
                    operandStack.push(operand1 || operand2);
            }
        }
    }
    return operandStack.top();
}

bool checkPrecedence(char c1, char c2){
    if(c2 == '!') return false;
    if(c1 == '!') return true;
    
    if(c1 == '&' || (c1 == '|' && c2 == '|')) return true;
    return false;
}

bool isOperator(char ch){
    if(ch != '!' && ch != '&' && ch != '|' && ch != ' ' && ch != '(') return false;
    return true;
}

bool isValid(string infix){
    if(infix == "") return false;
    string newInfix = "";
    for(char ch : infix){
        if(ch != ' ') newInfix += ch;
    }
    infix = newInfix;
    int count1 = 0;
    int count2 = 0;
    int i;
    for(i = 0; i < infix.size(); i++){
        char ch = infix.at(i);
        if(i == 0 && !isalpha(ch) && ch != '!' && ch != '(') return false;
        if(isalpha(ch)){
            if(!islower(ch) || (i > 0 && !isOperator(infix.at(i - 1)))) return false;
        }
        else if(ch == '&' || ch == '|'){
            if(i > 0 && (!isalpha(infix.at(i - 1)) && infix.at(i - 1) != ')')) return false;
        }
        else if(ch == '!'){
            if(i > 0 && !isOperator(infix.at(i - 1))) return false;
        }
        else if(ch == '('){
            if(i > 0 && !isOperator(infix.at(i - 1))) return false;
            count1++;
        }
        else if(ch == ')'){
            if(i > 0 && (infix.at(i - 1) == '(' || isOperator(infix.at(i - 1)))) return false;
            count2++;
        }
        else if(ch != '!' && ch != '&' && ch != '|') return false;
    }
    return count1 == count2 && (i > 0 && (isalpha(infix.at(i - 1)) || infix.at(i - 1) == ')'));
}

int appearance(string infix, const Set& trueValues, const Set& falseValues){
    for(char ch : infix){
        if(isalpha(ch)){
            if(!trueValues.contains(ch) && !falseValues.contains(ch)){
                return 2;
            }
            else if (trueValues.contains(ch) && falseValues.contains(ch)){
                return 3;
            }
        }
    }
    return 0;
}

int main()
{
//    string trueChars  = "tywz";
//    string falseChars = "fnx";
//    Set trues;
//    Set falses;
//    for (int k = 0; k < trueChars.size(); k++)
//        trues.insert(trueChars[k]);
//    for (int k = 0; k < falseChars.size(); k++)
//        falses.insert(falseChars[k]);
//
//    string pf;
//    bool answer = true;
//    assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  answer);
//    assert(evaluate("y|", trues, falses, pf, answer) == 1);
//    assert(evaluate("n t", trues, falses, pf, answer) == 1);
//    assert(evaluate("nt", trues, falses, pf, answer) == 1);
//    assert(evaluate("()", trues, falses, pf, answer) == 1);
//    assert(evaluate("!()", trues, falses, pf, answer) == 1);
//    assert(evaluate("()z", trues, falses, pf, answer) == 1);
//    assert(evaluate("y(n|y)", trues, falses, pf, answer) == 1);
//    assert(evaluate("!!!(t&(n&n))", trues, falses, pf, answer) == 0 && answer);
//    assert(evaluate("(n&(t|y))", trues, falses, pf, answer) == 0);
//    assert(evaluate("n+y", trues, falses, pf, answer) == 1);
//    assert(evaluate("", trues, falses, pf, answer) == 1);
//    assert(evaluate("f  |  !f & (t&n) ", trues, falses, pf, answer) == 0
//                           &&  pf == "ff!tn&&|"  &&  !answer);
//    assert(evaluate("", trues, falses, pf, answer) == 1);
//    assert(evaluate("       ", trues, falses, pf, answer) == 1);
//    assert(evaluate("(z)", trues, falses, pf, answer) == 0 && answer);
//    assert(evaluate("(z!)", trues, falses, pf, answer) == 1);
//    assert(evaluate("(!z)", trues, falses, pf, answer) == 0 && !answer);
//    assert(evaluate("((!!z))", trues, falses, pf, answer) == 0 && answer);
//    assert(evaluate("(!z!)", trues, falses, pf, answer) == 1);
//    assert(evaluate(" x  ", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  !answer);
//    assert(evaluate("((X))", trues, falses, pf, answer) == 1);
//    trues.insert('x');
//    assert(evaluate("((x))", trues, falses, pf, answer) == 3);
//    falses.erase('x');
//    assert(evaluate("((x))", trues, falses, pf, answer) == 0  &&  pf == "x"  &&  answer);
//    trues.erase('w');
//    assert(evaluate("w| f", trues, falses, pf, answer) == 2);
//    falses.insert('w');
//    assert(evaluate("w| f", trues, falses, pf, answer) == 0  &&  pf == "wf|" &&  !answer);
//
//    string trueChars2  = "ucla";
//    string falseChars2 = "snx";
//    Set trues2;
//    Set falses2;
//    for (int k = 0; k < trueChars2.size(); k++)
//        trues2.insert(trueChars2[k]);
//    for (int k = 0; k < falseChars2.size(); k++)
//        falses2.insert(falseChars2[k]);
//    assert(evaluate("u", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//    assert(evaluate("u&c&l&a & !(u&s&c)", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//    assert(evaluate("(n)", trues2, falses2, pf, answer) == 0  &&  !answer);
//    cout << pf << endl;
//    assert(evaluate("a&(s)", trues2, falses2, pf, answer) == 0  &&  !answer);
//    cout << pf << endl;
//    assert(evaluate("a & !s", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//    assert(evaluate("!(n|u)", trues2, falses2, pf, answer) == 0  &&  !answer);
//    cout << pf << endl;
//    assert(evaluate("!n|u", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//    assert(evaluate("a|n&n", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//    assert(evaluate("a&!(s|u&c|n)|!!!(s&u&n)", trues2, falses2, pf, answer) == 0  &&  answer);
//    cout << pf << endl;
//
//    cout << "Passed all tests" << endl;
}
