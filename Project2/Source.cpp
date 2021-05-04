#include<iostream>
#include<cstring>//<cstring> header file declares a set of functions to work with C style string (null terminated byte strings) as strlen(), strcmp().
#include<string>
#include<deque>/*Double ended queues are sequence containers with the feature of expansion and contraction on both the ends.
We use functions at(), pop_front(), front(), pop_front(), empty(), size()*/

using namespace std;
/******************SCANNER********************/
bool isPunctuator(char ch)					//check if the given character is a punctuator or not
{
	if (ch == ':' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
		ch == '&' || ch == '|')
	{
		return true;
	}
	return false;
}

bool validIdentifier(char* str)						//check if the given identifier is valid or not
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isPunctuator(str[0]) == true)
	{
		return false;
	}									//if first character of string is a digit or a special character, identifier is not valid
	int i, len = strlen(str);/*The strlen() function returns the length of the null terminated byte string.
 It takes a null terminated byte string str as its argument and returns its length.The length does not include the null character.
 If there is no null character in the string, the behaviour of the function is undefined.*/
	if (len == 1)
	{
		return true;
	}										//if length is one, validation is already completed, hence return true
	else
	{
		for (i = 1; i < len; i++)						//identifier cannot contain special characters
		{
			if (isPunctuator(str[i]) == true)
			{
				return false;
			}
		}
	}
	return true;
}

bool isOperator(char ch)							//check if the given character is an operator or not
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=' || ch == '|' || ch == '&')
	{
		return true;
	}
	return false;
}

bool isKeyword(char* str)						//check if the given substring is a keyword or not         char*str: str pointer points to adress of char in memory and we made this to pass an array in function ande this is made only in parameters in function
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||           //strcmp(str1,str2):compare str1 and str2 if they are equal it returns 0 we put ! to return it 1 as if don't return 0
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") || !strcmp(str, "continue")
		|| !strcmp(str, "int") || !strcmp(str, "double")
		|| !strcmp(str, "float") || !strcmp(str, "return")
		|| !strcmp(str, "char") || !strcmp(str, "case")
		|| !strcmp(str, "long") || !strcmp(str, "short")
		|| !strcmp(str, "typedef") || !strcmp(str, "switch")
		|| !strcmp(str, "unsigned") || !strcmp(str, "void")
		|| !strcmp(str, "static") || !strcmp(str, "struct")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "volatile") || !strcmp(str, "typedef")
		|| !strcmp(str, "enum") || !strcmp(str, "const")
		|| !strcmp(str, "union") || !strcmp(str, "extern")
		|| !strcmp(str, "bool") || !strcmp(str, "alignas")
		|| !strcmp(str, "alignof") || !strcmp(str, "and")
		|| !strcmp(str, "and_eq") || !strcmp(str, "asm")
		|| !strcmp(str, "atomic_cancel") || !strcmp(str, "atomic_commit")
		|| !strcmp(str, "atomic_noexcept") || !strcmp(str, "auto")
		|| !strcmp(str, "bitor") || !strcmp(str, "bitand")
		|| !strcmp(str, "catch") || !strcmp(str, "char16_t")
		|| !strcmp(str, "char32_t") || !strcmp(str, "class")
		|| !strcmp(str, "compl") || !strcmp(str, "concept")
		|| !strcmp(str, "constexpr") || !strcmp(str, "const_cast")
		|| !strcmp(str, "co_await") || !strcmp(str, "co_return")
		|| !strcmp(str, "co_yield") || !strcmp(str, "bool")
		|| !strcmp(str, "decltype") || !strcmp(str, "default")
		|| !strcmp(str, "delete") || !strcmp(str, "double")
		|| !strcmp(str, "dynamic_cast") || !strcmp(str, "else")
		|| !strcmp(str, "explicit") || !strcmp(str, "export")
		|| !strcmp(str, "false") || !strcmp(str, "float")
		|| !strcmp(str, "for") || !strcmp(str, "friend")
		|| !strcmp(str, "goto") || !strcmp(str, "import")
		|| !strcmp(str, "inline") || !strcmp(str, "module")
		|| !strcmp(str, "mutable") || !strcmp(str, "namespace")
		|| !strcmp(str, "new") || !strcmp(str, "noexcept")
		|| !strcmp(str, "not") || !strcmp(str, "not_eq")
		|| !strcmp(str, "nullptr") || !strcmp(str, "operator")
		|| !strcmp(str, "or") || !strcmp(str, "or_eq")
		|| !strcmp(str, "private") || !strcmp(str, "protected")
		|| !strcmp(str, "public") || !strcmp(str, "register")
		|| !strcmp(str, "reinterpret_cast") || !strcmp(str, "requires")
		|| !strcmp(str, "return") || !strcmp(str, "short")
		|| !strcmp(str, "signed") || !strcmp(str, "static")
		|| !strcmp(str, "static_assert") || !strcmp(str, "static_cast")
		|| !strcmp(str, "synchronized") || !strcmp(str, "template")
		|| !strcmp(str, "this") || !strcmp(str, "thread_local"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNumber(char* str)							//check if the given substring is a number or not
{
	int i, len = strlen(str), numOfDecimal = 0;
	if (len == 0)
	{
		return false;
	}
		for (i = 0; i < len; i++)
		{
			if (numOfDecimal > 1 && str[i] == '.') //numOfDecimal > 1 this means it must pass on number 1
			{
				return false;
			}
			else if (numOfDecimal <= 1)
			{
				numOfDecimal++;
			}
			if (str[i] != '0' && str[i] != '1' && str[i] != '2'
				&& str[i] != '3' && str[i] != '4' && str[i] != '5'
				&& str[i] != '6' && str[i] != '7' && str[i] != '8'
				&& str[i] != '9' || (str[i] == '.' && i > 0))
			{
				return false;
			}
		}
		return true;
}

char* subString(char* realStr, int l, int r)				//extract the required substring from the main string
{
	int i;

	char* str = (char*)malloc(sizeof(char) * (r - l));/*malloc function allocates memory at runtime. It takes the size in bytes and allocates that much space in the memory.
	It means that malloc(r - l) will allocate (r - l) byte in the memory. It returns a void pointer and is defined in stdlib.h.
	char *address → Here we declared a pointer to character for address without specifying how much memory is required.address = (char*)malloc( (r - l) * sizeof(char) ) → By writing this, we assigned a memory of '(r - l) * sizeof(char)' bytes for address.
	We used (char*) to typecast the pointer returned by malloc to character.*/

	for (i = l; i <= r; i++)
	{
		str[i - l] = realStr[i];

		str[r - l + 1] = '\0';  // '\0' means the end of array e.g. if [0:9] '\0' is the index no. 10
	}
	return str;
}

void scanner(char* str)						//make a scanner to the expression
{
	int left = 0, right = 0;
	int len = strlen(str);
	while (right <= len && left <= right) {
		if (isPunctuator(str[right]) == false)			//if character is a digit or an alphabet
		{
			right++;
		}

		if (isPunctuator(str[right]) == true && left == right)		//if character is a punctuator
		{
			if (isOperator(str[right]) == true)
			{
				cout << str[right] << " IS AN OPERATOR\n";

				right++;
				left = right;
			}
		}
		else if (isPunctuator(str[right]) == true && left != right
			|| (right == len && left != right)) 			//check if scanned substring is a keyword or identifier or number
		{
			char* sub = subString(str, left, right - 1);   //extract substring

			if (isKeyword(sub) == true)
			{
				cout << sub << " IS A KEYWORD\n";
			}
			else if (isNumber(sub) == true)
			{
				cout << sub << " IS A NUMBER\n";
			}
			else if (validIdentifier(sub) == true
				&& isPunctuator(str[right - 1]) == false)
			{
				cout << sub << " IS A VALID IDENTIFIER\n";
			}
			else if (validIdentifier(sub) == false
				&& isPunctuator(str[right - 1]) == false)
			{
				cout << sub << " IS NOT A VALID IDENTIFIER\n";
			}

			left = right;
		}
	}
	return;
}

/*===============================================================================================================================*/

/******************PARSER********************/
int n, n1, n2;
int getPosition(string arr[], string q, int size)
{
	for (int j = 0;j < size;j++)
	{
		if (q == arr[j])
			return j;
	}
	return -1;
}
int main()
{
	cout << "|++++++|COMPILER|++++++|" << endl;

	cout << "\n|******|LEXICAL ANALYSER|******|" << endl;
	cout << "Enter a C++ statement to make a scanner" << endl;
	char l[100];
	cin >> l;
	scanner(l);

	cout << "\n===============================\n" << endl;

	cout << "|******|SYNTAX ANALYSER|******|" << endl;
	string prods[10], first[10], follow[10], nonterms[10], terms[10];
	string pp_table[20][20] = {};
	cout << "Enter the number of productions : ";
	cin >> n;
	cin.ignore();//The cin.ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
	cout << "Enter the productions" << endl;
	for (int j = 0;j < n;j++)
	{
		getline(cin, prods[j]);/*getline() is a standard library function that is used to read a string or a line from an input stream.
		It is a part of the <string> header.*/ 
		cout << "Enter first for " << prods[j].substr(3) << " : ";
		getline(cin, first[j]);
	}
	cout << "Enter the number of Terminals : ";
	cin >> n2;
	cin.ignore();
	cout << "Enter the Terminals" << endl;
	for (int j = 0;j < n2;j++)
	{
		cin >> terms[j];
	}
	terms[n2] = "$";
	n2++;
	cout << "Enter the number of Non-Terminals : ";
	cin >> n1;
	cin.ignore();
	for (int j = 0;j < n1;j++)
	{
		cout << "Enter Non-Terminal : ";
		getline(cin, nonterms[j]);
		cout << "Enter follow of " << nonterms[j] << " : ";
		getline(cin, follow[j]);
	}


	cout << endl;
	cout << "Grammar" << endl;
	for (int j = 0;j < n;j++)
	{
		cout << prods[j] << endl;
	}


	for (int d = 0;d < n;d++)
	{
		int row = getPosition(nonterms, prods[d].substr(0, 1), n1);/*substr():This function contains two parameters: pos and len.
		The pos parameter specifies the start position of the substring and len denotes the number of characters in a substring.*/
		if (prods[d].at(3) != '#')//at(): function is used reference the element present at the position given as the parameter to the function.
		{
			for (int j = 0;j < first[d].length();j++)
			{
				int col = getPosition(terms, first[d].substr(0, 1), n2);
				pp_table[row][col] = prods[d];
			}
		}
		else
		{
			for (int j = 0;j < follow[row].length();j++)
			{
				int col = getPosition(terms, follow[row].substr(j, 1), n2);
				pp_table[row][col] = prods[d];
			}
		}
	}
	//Display Table
	for (int d = 0;d < n2;d++)
		cout << "\t" << terms[d];
	cout << endl;
	for (int j = 0;j < n1;j++)
	{
		cout << nonterms[j] << "\t";
		//Display Table
		for (int d = 0;d < n2;d++)
		{
			cout << pp_table[j][d] << "\t";
		}
		cout << endl;
	}
	//Parsing String
	char c;
	do {
		string ip;/* IP address is a unique address that identifies a device on the internet or a local network. IP stands for "Internet Protocol,"
		which is the set of rules governing the format of data sent via the internet or local network.*/
		deque<string> pp_stack;
		pp_stack.push_front("$");
		pp_stack.push_front(prods[0].substr(0, 1));
		cout << "Enter the string to be parsed : ";
		getline(cin, ip);
		ip.push_back('$');
		cout << "Stack\tInput\tAction" << endl;
		while (true)
		{
			for (int j = 0;j < pp_stack.size();j++)//size(): function is used to return the size of the deque container or the number of elements in the deque container.
				cout << pp_stack[j];
			cout << "\t" << ip << "\t";
			int row1 = getPosition(nonterms, pp_stack.front(), n1);
			int row2 = getPosition(terms, pp_stack.front(), n2);
			int column = getPosition(terms, ip.substr(0, 1), n2);
			if (row1 != -1 && column != -1)
			{
				string p = pp_table[row1][column];
				if (p.empty())//empty() function is used to check if the deque container is empty or not.
				{
					cout << endl << "String cannot be Parsed." << endl;
					break;
				}
				pp_stack.pop_front();
				if (p[3] != '#')
				{
					for (int x = p.size() - 1;x > 2;x--)
					{
						pp_stack.push_front(p.substr(x, 1));
					}
				}
				cout << p;
			}
			else
			{
				if (ip.substr(0, 1) == pp_stack.front())
				{
					if (pp_stack.front() == "$")// front() function is used to reference the first element of the deque container. 
					{
						cout << endl << "String Parsed." << endl;
						break;
					}
					cout << "Match " << ip[0];
					pp_stack.pop_front();
					ip = ip.substr(1);
				}
				else
				{
					cout << endl << "String cannot be Parsed." << endl;
					break;
				}
			}
			cout << endl;
		}
		cout << "Continue?(Y/N) ";
		cin >> c;
		cin.ignore();
	} while (c == 'y' || c == 'Y');
	return 0;
}
