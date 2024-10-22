#include "List.h"
template <typename Tipe>
void List<Tipe>::insertLast(Tipe newValue) {
	Node<Tipe>* newNode = new Node<Tipe>(newValue);
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	else {
		last->next = newNode;
		newNode->previous = last;
		last = newNode;
	}
}

template <typename Tipe>
void List<Tipe>::DrawList(RenderWindow& window) {
	Node<Tipe>* actual = first;
	while (actual) {
		window.draw(actual->value);
		actual = actual->next;
	}
}


template class List<CircleShape>;