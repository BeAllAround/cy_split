
#include <string>
#include <vector>
#include <iostream>

#include <stack>
#include <deque>


#include "debug.h"

using namespace std;

#define TYPE stack

TYPE<string> split(string s, string delimiter) {
	int c = 0;
	int i = 0;

	// string*arr = (string*)malloc(sizeof(s) * 10);
	TYPE<string> arr;
	// int push = 0;

	string __s;

	int sp_l = delimiter.length();
	int s_l = s.length();

	while(i < s_l) {
		if(s_l-i >= sp_l) {
			for(int x = 0; x < sp_l; x++) {
				if(s[i+x] != delimiter[x]) {
					__s += s[i];
					c = 0;
					break;
				}
				else {
					c++;
				}
			}
		}
		else {
			__s += s[i];
		}
		if(c == sp_l) {
			// arr[push++] = (__s);
			// arr.push_back(__s);
			arr.push(__s);
			i += c-1;
			__s.clear();
			c = 0;

		}

		i++;
	}

	// arr[push++] = __s;
	// arr.push_back(__s);
	arr.push(__s);

	return arr;


}


string big_string() {
	string s;

	for(int i = 0; i < 100000; i++) {
		s += "a  ";
	}

	return s;
}

void print(const vector<string>& vec) {
	std::cout << '[';
	for(const string& s: vec) {
		std::cout << '"' << s << '"' << ", ";
	}
	std::cout << ']' << std::endl;
}

void print(stack<string>&& stack) {
	std::cout << '[';
	while(!stack.empty()) {
		std::cout << '"' << stack.top() << '"' << ", ";
		stack.pop();
	}
	std::cout << ']' << std::endl;
}


int main(void) {
	string s = big_string();
	// std::cout << s << std::endl;
	//
	//
	
	for(int i = 0; i < 10; i++) {
		start_time
		split(s, " ");
		end_time;
	}

	return 0;
}
