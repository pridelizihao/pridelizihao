#include <iostream>
#include <cmath>
#include <string>
using namespace std;

template <class T>
class stack {
private:
	int top;
	int maxsize;
	T* element;
public:
	stack(int size = 100) {
		top = -1;
		maxsize = size;
		element = new T[maxsize];
	}

	~stack() {
		delete[] element;
	}

	bool isempty() {
		return top == -1;
	}

	bool push(T item){
		if (top > maxsize-1) {
			cout << "the stack is full" << endl;
			return false;
		}
		else {
			element[++top] = item;
			return true;
		}
	}

	T pop() {
		if (top == -1) {
			cout << "the stack is empty" << endl;
			return static_cast<T>(0);
		}
		else {
			return element[top--];
		}
	}

	T getTop() {
		if (top == -1) {
			cout << " the stack is empty" << endl;
			return static_cast<T>(0);
		}
		else {
			return element[top];
		}
	}
};

bool isprime(int num) {
	if (num <= 1) {
		return false;
	}
	else {
		int temp = (int)sqrt(num) + 1;
		for (int i = 2; i < temp; i++) {
			if (num % i == 0) {
				return false;
			}
		}
		return true;
	}
}

void detach(int n){
	int temp = n;
	stack<int> mystack(100);
	while (n > 1) {
		if (isprime(n)) {
			mystack.push(n);
			n = 1;
		}
		else {
			int factor = 0;
			for (int i = 2; i <= int(sqrt(n)) + 1; i++) {
				if (isprime(i) and n % i == 0) {
					factor = i;
					break;
				}
			}
			if (factor != 0) {
				mystack.push(factor);
				n /= factor;
			}
			else {
				mystack.push(n);
				n = 1;
			}
		}
	}
	

	string str1 = "";
	while (mystack.isempty() == false) {
		int ch = mystack.pop();
		string ar = to_string(ch);
		str1 += ar;
		if (mystack.isempty()) {
			break;
		}
		else {
			str1 += "*";
		}
	}

	cout << temp << "=" << str1 << endl;
}


int main() {
	int n;
	cin >> n;
	detach(n);
}