#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

template <typename Tipe>
class Node
{
public:
	Tipe value;
	Node<Tipe>* next;
	Node<Tipe>* previous;
	Node(Tipe value) : value(value), next(nullptr), previous(nullptr) {};
};

