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

	int insert_index(int index, var data) {
		if(size == 0) {
			push_back(data);
			return 1;
		} 
		if(index > size) {
			push_back(data);
			return 1;
		} 
		if(index == 0 || index == 1) {
			push_front(data);
			return 1;
		} 
		if(index < 0)
		{
			 	index = ((-1)*index)%size;
			 	if (index == 1) 
			 	{
			 		push_back(data);
			 		return 1;

			 	}
			 	else if (index == 0)
					 	{
							push_front(data);
							return 1; 
					 	}
					 	else
					 	 {
					 		Node<var> *now = tail;
						 	for(int i = 1; i <= index-2; i++)
						 		now = now->prev;
						 	Node<var> *added = new Node<var>(data);
						 	added->next = now;
						 	added->prev = now->prev;
						 	now->prev->next = added;
						 	now->prev = added;

						 	size++;
						 	return 1;
					 	}
	

		}
		if(index > 0) 
		{
			Node<var> *now = head;
		 	for(int i = 1; i <= index-2; i++)
		 		now = now->next;
		 	Node<var> *added = new Node<var>(data);
		 	added->prev = now;
		 	added->next = now->next;
		 	now->next->prev = added;
		 	now->next = added;
		 	size++;
		 	return 1; 
		}
		return 0;

	}

	int delete_index(int index) {
		if(size == 0) {
			pop_back();
			return 1;
		} 
		if(index > size) {
			pop_back();
			return 1;
		} 
		if(index == 0 || index == 1) {
			pop_front();
			return 1;
		}
		if(index == size) {
			pop_back();
			return 1;
		} 
		if(index < 0)
		{
			 	index = ((-1)*index)%size;
			 	if (index == 1) 
			 	{
			 		pop_back();
			 		return 1;

			 	}
			 	else if (index == 0)
					 	{
							pop_front();
							return 1; 
					 	}
					 	else
					 	 {
					 		Node<var> *now = tail;
						 	for(int i = 1; i <= index-1; i++)
						 		now = now->prev;
						 	Node<var> *deleted = now;
						 	deleted->prev->next = deleted->next;
						 	deleted->next->prev = deleted->prev;
						 	size--;
						 	delete deleted;
						 	return 1;
					 	}
	

		}
		if(index > 0) 
		{
			Node<var> *now = head;
		 	for(int i = 1; i <= index-1; i++)
		 		now = now->next;
		 	Node<var> *deleted = now;
		 	deleted->prev->next = deleted->next;
			deleted->next->prev = deleted->prev;
		 	size--;
		 	delete deleted;
		 	return 1; 
		}
		return 0;

	}

	int length() {
		return size;
	}

	bool isEmpty() {
		return (size == 0);
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

	void clear() {
		if(size != 0)
		{
			Node<var> *now = head;
			now = now->next;
			while (now != nullptr)
			{
				now->prev->next = nullptr;
				delete now->prev;
				now = now->next;
			}
			delete tail;
			tail = nullptr;
			delete head;
			head = nullptr;
		}
		size = 0;
	
	}

	Node<var> * getHead() {
		return head;
	}

	Node<var> * getTail() {
		return head;
	}

	List<var>& operator=(List<var> const other) {
		clear();
		Node<var> *now = other.head;
		while(now != nullptr) {
			push_back(now->data);
			now = now->next;
		}
		return *this;
	}

	List<var>& operator+(List<var> const other) {
		Node<var> *now = other.head;
		Node<var> *aux;
		while(now != nullptr) {
			push_back(now->data);
			aux = now;
 			now = now->next;
		}
		tail = aux;
		return *this;
	}

};

int main() {

	List<int> x, y;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);

	y.push_back(11);
	y.push_back(12);
	y.push_back(13);
	y.push_back(14);

	x = x+y;
	x.print();

	return 0;
}