#pragma once
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <cstdlib>
#include <bits/stl_algobase.h>

template <typename T>
class ArrayList
{
public:
	ArrayList(int capacity = 10);
	ArrayList(const ArrayList<T> &array);
	ArrayList(const T *array, int size = sizeof(array) / sizeof(array[0]));
	~ArrayList();

	bool add(const T &item);
	bool insert(int index, const T &item);
	bool set(int index, const T &item);
	const int size() const;
	const int capacity() const;
	T get(int index) const;
	T remove(int index);
	const T *getArray() const;

private:
	T *_data;
	int _capacity;
	int _count;

	bool indexIsCorrect(int index) const;
	bool resize(int newCapacity);
	bool resizeSmart(int newSize);
};

template<typename T>
inline ArrayList<T>::ArrayList(int capacity)
{
	_count = 0;
	_capacity = 0;

	_data = static_cast<T *>(malloc(capacity * sizeof(T)));;
	if (_data != nullptr)
	{
		_capacity = capacity;
	}
}

template<typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T> &array) : ArrayList(array.getArray(), array.size()) {}

template<typename T>
inline ArrayList<T>::ArrayList(const T *array, int size)
{
	_count = 0;
	_capacity = 0;
	_data = static_cast<T *>(malloc(size * sizeof(T)));;
	if (_data != nullptr)
	{
		std::copy(array, array + size, _data);
		_count = size;
		_capacity = size;
	}
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
	free(_data);
}

template<typename T>
inline bool ArrayList<T>::add(const T &item)
{
	if (resizeSmart(_count + 1))
	{
		_data[_count++] = item;
		return true;
	}

	return false;
}

template<typename T>
inline bool ArrayList<T>::insert(int index, const T &item)
{
	if (indexIsCorrect(index) == false || resizeSmart(_count + 1) == false)
	{
		return false;
	}

	std::move_backward(_data + index, _data + _count, _data + _count + 1);
	_data[index] = item;
	_count++;
	return true;
}

template<typename T>
inline bool ArrayList<T>::set(int index, const T &item)
{
	if (indexIsCorrect(index))
	{
		_data[index] = item;
		return true;
	}
	return false;
}

template<typename T>
inline const int ArrayList<T>::size() const
{
	return _count;
}


template<typename T>
inline const int ArrayList<T>::capacity() const
{
	return _capacity;
}

template<typename T>
inline T ArrayList<T>::get(int index) const
{
	if (indexIsCorrect(index))
	{
		return _data[index];
	}
	return T();
}

template<typename T>
inline T ArrayList<T>::remove(int index)
{
	if (indexIsCorrect(index) == false)
	{
		return T();
	}

	T item = _data[index];
	std::move(_data + index + 1, _data + _count, _data + index);
	resizeSmart(--_count);
	return item;
}

template<typename T>
inline const T *ArrayList<T>::getArray() const
{
	return _data;
}

template<typename T>
inline bool ArrayList<T>::indexIsCorrect(int index) const
{
	if (index > -1 && index < _count)
	{
		return true;
	}
	return false;
}

template<typename T>
inline bool ArrayList<T>::resize(int newCapacity)
{
	T *newData = (T *) realloc(_data, newCapacity * sizeof(T));
	if (newData == nullptr)
	{
		return false;
	}
	_data = newData;
	_capacity = newCapacity;
	return true;
}

template<typename T>
inline bool ArrayList<T>::resizeSmart(int newSize)
{
	int ratio = 2;
	if (newSize < _capacity / (ratio * 2) || newSize > _capacity)
	{
		return resize(newSize * ratio);
	}

	return true;
}


#endif // ARRAY_LIST_H
