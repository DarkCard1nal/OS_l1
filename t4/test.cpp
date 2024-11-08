#include <iostream>
#include "ArrayList.hpp"

int main()
{
	std::cout << "Test Start!" << std::endl;

	std::cout << "class ArrayList" << std::endl;

	ArrayList<int> list(5);

	list.add(10);
	list.add(20);
	list.add(30);
	list.add(40);
	list.add(50);

	std::cout << "After adding 5 elements:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	list.insert(2, 25);
	std::cout << "After inserting 25 at index 2:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	list.set(3, 35);
	std::cout << "After setting index 3 to 35:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	int removed = list.remove(2);
	std::cout << "Removed element: " << removed << std::endl;
	std::cout << "After removing element at index 2:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	removed = list.remove(2);
	std::cout << "Removed element: " << removed << std::endl;
	std::cout << "After removing element at index 2:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	removed = list.remove(2);
	std::cout << "Removed element: " << removed << std::endl;
	std::cout << "After removing element at index 2:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "Current size: " << list.size() << std::endl;
	std::cout << "Current capacity: " << list.capacity() << std::endl;

	removed = list.remove(3);
	std::cout << "Removed element: " << removed << std::endl;
	std::cout << "After removing element at index 3:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	removed = list.remove(2);
	std::cout << "Removed element: " << removed << std::endl;
	std::cout << "After removing element at index 2:" << std::endl;
	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list.get(i) << " ";
	}
	std::cout << std::endl;

	std::cout << "Current size: " << list.size() << std::endl;
	std::cout << "Current capacity: " << list.capacity() << std::endl;

	std::cout << "Test Stop!" << std::endl;
	return 0;
}
