#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>

using namespace sf;


template <typename Tipe>
class List
{

public:
	Node<Tipe>* first;
	Node<Tipe>* last;
	List() : first(nullptr), last(nullptr) {};
	void insertLast(Tipe newValue);
	void DrawList(RenderWindow& window);
    
};

