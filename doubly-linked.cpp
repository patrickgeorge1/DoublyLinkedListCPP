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
			tail->next = added;
			added->next = nullptr;
			added->prev = tail;
			tail = added;

		}
		size++;
	}

	void push_front(var data) {
		Node<var> *added = new Node<var>(data);
		if (this->size == 0) {
			head = added;
			tail = added;
		} else {
			head->prev = added;
			added->next = head;
			added->prev = nullptr;
			head = added;
		}
		size++;
	}

	var pop_back() {
		var x;
		if (size == 1) {
			x = tail->data;
			delete tail;
			delete head;
			size--;
		} else if (size > 1) {
			x = tail->data;
			Node<var> *removed = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete removed;
			size--;
		}
		return x;

	}

	var pop_front() {
		var x;
		if (size == 1) {
			x = head->data;
			delete tail;
			delete head;
			size--;
		} else if (size > 1) {
			x = head->data;
			Node<var> *removed = head;
			head = head->next;
			head->prev = nullptr;
			delete removed;
			size--;
		}
		return x;
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
	x.push_front(0);
	x.pop_back();
	x.pop_front();
	x.print();

	return 0;
}