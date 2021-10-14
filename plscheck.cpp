#include <bits/stdc++.h>
using namespace std;

class history
{
	private:
		queue <string> histo;
		queue <string> temp;
		
	public:
		void addtohis(string s, int ans)
		{
			string addd;
			string n;
			n = to_str(ans);
			addd=s + "= "+ n;
			histo.push(addd);
			return;
		}
		
		void showhis()
		{
			while(!histo.empty())
			{
				cout<<histo.front()<<endl;
				temp.push(histo.front());
				histo.pop();
			}
			while(!temp.empty())
			{
				histo.push(temp.front());
				temp.pop();
			}
			return;
		}
		
		void clearhis()
		{
			while(!histo.empty())
			{
				histo.pop();
			}
			return;
		}
};

template <typename DataType>
class order {
	private:
		struct Node
		{
			DataType data;
			Node* next;
		};
		Node* head;
	public:
		order() { 
			head = NULL; 
		}
		void push(DataType element)
		{
			struct Node* newNode;
			newNode = new Node();
			newNode->data = element;
			newNode->next = head;
			head = newNode;
		}

		DataType pop()
		{
			struct Node* temp;
			temp = head;
			DataType poppedValue = head->data;
			head = head->next;
			temp->next = NULL;
			free(temp);
			return poppedValue;
		}

		DataType top()
		{
			return head->data;
		}

		bool empty()
		{
			if (head == NULL)
				return true;
			else 
				return false;
		}
};

class Calculator
{
private:
	string infix;
	order <char> operands;
	order <int> operators;

public: 
	Calculator() { string infix = ""; }
	Calculator(string userExpr) { infix = userExpr; }

	bool isLegal(string infix)
	{
		bool legal = true;
		int parenthesisCount = 0;
		try 
		{
			for (size_t i = 0; i < infix.length(); i++)
			{
				switch (infix[i])
				{
				case '(': parenthesisCount++; break;
				case ')': parenthesisCount--; break;
				default: break;
				}
			}
			if (parenthesisCount != 0)
			{
				legal = false;
				throw 0;
			}
		}
		catch (...)
		{
			cout<<"Error: Unmatched Parenthesis (Brackets)"<<endl<<endl;;
		}
		try 
		{
			for (size_t i = 0; i < infix.length(); i++)
			{
				switch (infix[i])
				{
				case '.': legal = false; throw 1; break;
				default: break;
				}
			}
		}
		catch (...)
		{
			cout << "Error: Operands must be integers!"<<endl<<endl;
		}
		return legal;
	}

	bool isOperand(char number)
	{
		if (number >= '0' && number <= '9')
			return true;
		else
			return false;
	}

	bool isOperator(char op)
	{
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')' ||op == '[' || op == ']' || op == '{' || op == '}' || op == '^')
			return true;
		else
			return false;
	}

	bool isSpace(char character)
	{
		if (character == ' ' || character == '\r' || character == '\n')
			return true;
		else
			return false;
	}

	int precedence(char character)
	{
		if (character == '^')
			return 3;
		else if (character == '*' || character == '/')
			return 2;
		else if (character == '+' || character == '-')
			return 1;
		else if (character == '(' || character == ')' || character == '[' || character == ']' || character == '{' || character == '}')
			return 0;
		else 
			return -1;
	}

	int operate(int valueOne, int valueTwo, char op)
	{
		switch (op) 
		{
		case '+': return valueOne + valueTwo; break;
		case '-': return valueOne - valueTwo; break;
		case '*': return valueOne * valueTwo; break;
		case '/': return valueOne / valueTwo; break;
		case '^': return (int)pow(valueOne, valueTwo); break;
		}
	}

	int eval()
	{
		int finalAnswer;
		for (size_t i = 0; i < infix.length(); i++)
		{
			if (isOperand(infix[i]) == true)
			{
				int currentNumber = 0;
				while (i < infix.length() && isOperand(infix[i]))
				{
					currentNumber = 10 * currentNumber + (int)(infix[i] - '0');
					++i;
				}
				operands.push(currentNumber);
				--i;
			}

			else if (infix[i] == '(')
				operators.push(infix[i]);
			
			else if (infix[i] == ')')
			{
				while (operators.top() != '(')
				{
					int valueOne = operands.pop();
					int valueTwo = operands.pop();
					char op = operators.pop();
					operands.push(operate(valueTwo,valueOne,op));
				}
				operators.pop();
			}

			else if (isSpace(infix[i]) == true)
				continue;

			else if (isOperator(infix[i]) == true)
			{
				if (operators.empty() == true || precedence(infix[i]) >= precedence(operators.top()))
				{
					operators.push(infix[i]);
				}
				else
				{
					int valueTwo = operands.pop();
					int valueOne = operands.pop();
					char op = operators.pop();
					operands.push(operate(valueOne, valueTwo, op));
					operators.push(infix[i]);
				}
			}
		}
		finalAnswer = operands.top();

		while (operators.empty() != true)
		{
			int valueTwo = operands.pop();
			int valueOne = operands.pop();
			char op = operators.pop();
			operands.push(operate(valueOne, valueTwo, op));
			finalAnswer = operate(valueOne, valueTwo, op);
		}

		return finalAnswer;
	}
	
	void setExpr(string infixExpr)
	{
		infix = infixExpr;
	}

	string getExpr()
	{
		return infix;
	}
};

int main()
{
	history hh;
	string userInput, sentinel = "0";
	cout << "Enter 0 to exit the program.\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	while (userInput != sentinel)	{
		cout << "Enter an expression: ";
		getline(cin, userInput);
		if (userInput == "0")
			break;
		else if(userInput=="H")
		{
			hh.showhis();
        	continue;
		}
		Calculator userExpression(userInput);
		if (userExpression.isLegal(userInput) == false)
			continue;
		else
		{
			cout << "\nResult: " << userExpression.eval() << "\n\n";
			hh.addtohis(userInput, userExpression.eval());
		}
	}	
	system("pause");

	return 0;
}
