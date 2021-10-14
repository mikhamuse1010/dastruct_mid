#include<bits/stdc++.h>
using namespace std;

class history
{
	private:
		queue <string> histo;
		queue <string> temp;
	public:
		void addtohis(string s, double ans)
		{
			string addd;
			string n;
			n=to_string(ans);
			addd=s+"= "+n;
			histo.push(addd);
			return;
		}
		void showhis()
		{
			if(histo.empty())
			{
				cout<<"history is empty"<<endl;
			}
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
			cout<<"History has been cleared!!"<<endl;
			return;
		}
		void delone()
		{
			cout<<histo.front()<<" has been deleted!!"<<endl;
			histo.pop();
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
	order() { head = NULL; }

	void push(DataType element, bool output = false)
	{
    // if (output){
      cout << "element being pushed: " <<element << endl;
    // }
		struct Node* newNode;
		newNode = new Node();
		newNode->data = element;
		newNode->next = head;
		head = newNode;
	}
  void loop(){
    struct Node* temp;
    temp = head;
    cout << "looping: ";
    while (temp != NULL){
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << endl;
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
	order <double> operands;
	order <char> operators;

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
		// try 
		// {
		// 	for (size_t i = 0; i < infix.length(); i++)
		// 	{
		// 		switch (infix[i])
		// 		{
		// 		case '.': legal = false; throw 1; break;
		// 		default: break;
		// 		}
		// 	}
		// }
		// catch (...)
		// {
		// 	cout << "Error: Operands must be integers!"<<endl<<endl;
		// }
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
		if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')' ||op == '[' || op == ']' || op == '{' || op == '}' || op == '^'){
      return true;
    }
		else{
			return false;
    }
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
			return 4;
		else if (character == '*' || character == '/')
			return 3;
		else if (character == 's' || character == 'c' || character == 't')
			return 2;
		else if (character == '+' || character == '-')
			return 1;
		else if (character == '(' || character == ')' || character == '[' || character == ']' || character == '{' || character == '}')
			return 0;
		else 
			return -1;
	}

	double operate(double valueOne, double valueTwo, char op)
	{
  

		switch (op) 
		{
		case '+': return valueOne + valueTwo; break;
		case '-': return valueOne - valueTwo; break;
		case '*': return valueOne * valueTwo; break;
		case '/': return valueOne / valueTwo; break;
		case '^': return (double)pow(valueOne, valueTwo); break;
		}
	}
	
	double trigonometry(char character, double value) 
	{
		switch(character) {
			case 's': return (sin(value)); break;
      case 'c': return (cos(value)); break;
      case 't': return (tan(value)); break;
		}
	}
	
	double trigonometry(char character, int value) 
	{
		switch(character) {
			case 's': return (sin(value)); break;
            		case 'c': return (cos(value)); break;
            		case 't': return (tan(value)); break;
		}
	}

	double eval()
	{
		double finalAnswer;
		for (size_t i = 0; i < infix.length(); i++)
		{
			if (isOperand(infix[i]) == true)
			{
				double currentNumber = 0;
				while (i < infix.length() && ( isOperand(infix[i]) || infix[i] == '.'))
				{
          if (infix[i] == '.'){
            int counter = 0;
            int dec = 0;
            i++; 
            for(; i < infix.length(); i++){
              if (isOperand(infix[i])){
                dec = 10 * dec + (int)(infix[i] - '0');
                counter++;
              }
              else break;
            }
            double calculatedDec= (double)dec / (double)(pow(10, counter));
            cout << currentNumber << endl;
            cout << fixed << setprecision(5) << calculatedDec << endl;
            currentNumber += calculatedDec;
            
          }
          else {
					  currentNumber = 10 * currentNumber + (double)(infix[i] - '0');
					  ++i;
          }
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
					double valueOne = operands.pop();
					double valueTwo = operands.pop();
					char op = operators.pop();
					operands.push(operate(valueTwo,valueOne,op));
				}
				operators.pop();
			}

			else if (isSpace(infix[i]) == true)
				continue;

			else if (isOperator(infix[i]) == true)
			{
				if (operators.empty() == true || precedence(infix[i]) > precedence(operators.top()))
				{
					operators.push(infix[i]);
				}
				else
				{
					double valueTwo = operands.pop();
					double valueOne = operands.pop();
					char op = operators.pop();
          double operatedValue = operate(valueOne, valueTwo, op);
          cout << valueOne << " " << op << " " << valueTwo << " = " << operatedValue << endl;
					operands.push(operatedValue);
					operators.push(infix[i]);
				}
			}
		}
    //4 * 5 + 6 ^ 3 
		finalAnswer = operands.top();

		while (!operators.empty())
		{
      operands.loop();
			double valueTwo = operands.pop();
			double valueOne = operands.pop();
			char op = operators.pop();

      double operateValue = operate(valueOne, valueTwo, op);

			operands.push(operateValue, true);
			finalAnswer = operateValue;
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
cout << "Enter 0 to exit the program"<<endl;
cout<<"Enter H to view history"<<endl;
cout<<"Enter D to delete latest history"<<endl;
cout<<"Enter C to clear history"<<endl;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

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
	else if(userInput=="C")
	{
		hh.clearhis();
		continue;
	}
	else if(userInput=="D")
	{
		hh.delone();
		continue;
	}
<<<<<<< HEAD
  cout << userInput << endl;
=======
>>>>>>> 3af5daea99f6709c85db70716511865a96be9c87
	Calculator userExpression(userInput);
	if (userExpression.isLegal(userInput) == false)
		continue;
	else
	{
    double finalValue = userExpression.eval();
		cout << "\nResult: " <<  finalValue << "\n\n";
		hh.addtohis(userInput, finalValue);
	}
}

	system("pause");

	return 0;
}