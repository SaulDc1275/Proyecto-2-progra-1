#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

template <typename Tipe>
struct Node
{
	Tipe value;
	Node<Tipe>* next;
	Node<Tipe>* prev;
	Node(Tipe value) : value(value), next(nullptr), prev(nullptr) {};
};

