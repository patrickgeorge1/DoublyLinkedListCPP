#include <iostream>

using namespace std;

template <typename var>
struct Node {
	var data;
	Node<var> *next;
	Node<var> *prev;
	Node(var data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename var>
class List {

private:
	int size;
	Node<var> *head;
	Node<var> *tail;

public:
	List() {                                                  // List<var> x
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	List(Node<var> *head) {                                   // List<var> x(head) -- dau alta lista
		this->head = head;
		Node<var> *now;
		while (head != nullptr) {
			size++;
			now = head;
			head = head->next;
		}
		this->tail = now;
	}

	~ List() {
		if(this->size == 1) {
			delete this->head;
			delete this->tail;
		} else if (this->size > 1) {
			Node<var> *now = this->head;
			while(now != nullptr) {
				Node<var> *removed = now;
				now = now->next;
				delete removed;
			}
		}
	}

	void push_back(var data) {                      // x.push_back(3)
		Node<var> *added = new Node<var>(data);
		if (this->size == 0) {
			head = added;
			tail = added;

		} else {
			Node<var> *now = tail;
			now->next = added;
			added->next = nullptr;
			added->prev = tail;
			tail = added;

		}
		size++;
	}


	void print() {											// print head->tail
		Node<var> *now = head;
		while(now != nullptr)
		{
			cout << now->data << endl;
			now = now->next;
		}
	}

	void print_r() {                          				// print tail->head
		Node<var> *now = tail;
		while(now != nullptr)
		{
			cout << now->data << endl;
			now = now->prev;
		}
	}
};

int main() {

	List<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(4);
	x.print();

	return 0;
}