#include <iostream>

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void push_front(const T& data);
	void pop_front();
	void clear();
	T& top();
	void print();
private:
	struct Node
	{
		T m_data;
		Node* m_next{ nullptr };
		Node(const T& data, Node* next = nullptr);
	};

	Node* m_head;
	int m_size;
};





int main()
{
	Stack<int>a;
	a.push_front(4);
	a.push_front(8);
	a.push_front(42);
	a.push_front(1);
	a.push_front(12);
	std::cout << "Stack :\n";
	a.print();
	std::cout << "Tot :" << a.top() << std::endl;
	a.pop_front();
	a.pop_front();
	std::cout << "Stack :\n";
	a.print();
    return 0;
}

template<typename T>
Stack<T>::Node::Node(const T& data, Node* next) :m_data{ data }, m_next{ next }{}

template<typename T>
Stack<T>::Stack() : m_size{ 0 }, m_head{ nullptr }{}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::push_front(const T& data)
{
	if (m_head)
	{
		m_head = new Node(data, m_head);
		m_size++;
	}
	else
	{
		m_head = new Node(data);
		m_size++;
	}
	
}

template<typename T>
void Stack<T>::pop_front()
{
	if (!m_head)return;
	Node* p = m_head;
	m_head = m_head->m_next;
	delete p;
	m_size--;
}

template<typename T>
void Stack<T>::clear()
{
	while (m_size)
	{
		pop_front();
	}
}

template<typename T>
T& Stack<T>::top()
{
	return m_head->m_data;
}

template<typename T>
void Stack<T>::print()
{
	Node* p = m_head;
	while (p)
	{
		std::cout << p->m_data << std::endl;
		p = p->m_next;
	}
}
