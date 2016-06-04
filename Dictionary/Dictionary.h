#pragma once
#include<iostream>

template<class K, class V>
class Dictionary
{
	K *key;
	V *value;

	int currentSize;
	int capacity;

	void resize();
	void destroy();

	void copy(const Dictionary &other);

	bool isEmty() const;
	bool isFull() const;
	void noElementMessage(const K &keyElement) const;

public:
	Dictionary();
	Dictionary(K *key, V *value, int currentSize, int capacity);
	Dictionary(const Dictionary &other);
	
	Dictionary &operator=(const Dictionary &other);
	virtual ~Dictionary();

	void addNewElement(const K &newKey, const V &newValue);
	
	V searchByKey(const K &keySearch) const;

	
	friend std::ostream &operator<<(std::ostream &out, const Dictionary &source)
	{
		Dictionary<K, V> tmpObject(source);

		for (size_t i = 0; i < tmpObject.currentSize; i++)
				out << "Key: " << tmpObject.key[i] << " Value : " << tmpObject.value[i] << std::endl;

		return out;
	}
};

template<class K, class V>
inline void Dictionary<K, V>::resize()
{
	K *bufferKey = new K[this->capacity * 1.5];

	V *bufferValue = new V[this->capacity * 1.5];

	for (size_t i = 0; i < this->capacity; i++)
	{
		bufferKey[i] = this->key[i];

		bufferValue[i] = this->value[i];
	}

	this->capacity = this->capacity * 1.5;
}

template<class K, class V>
inline void Dictionary<K, V>::copy(const Dictionary & other)
{
	this->currentSize = other.currentSize;

	this->capacity = other.capacity;

	this->key = new K[this->capacity];

	this->value = new V[this->capacity];

	for (size_t i = 0; i < this->currentSize; i++)
	{
		this->key[i] = other.key[i];

		this->value[i] = other.value[i];
	}
}

template<class K, class V>
inline void Dictionary<K, V>::destroy()
{
	if (this->key != nullptr) delete[] this->key;

	if (this->value != nullptr) delete[] this->value;
}

template<class K, class V>
inline bool Dictionary<K, V>::isEmty() const
{
	return this->capacity <= 0;
}

template<class K, class V>
inline bool Dictionary<K, V>::isFull() const
{
	return this->capacity == this->currentSize;
}

template<class K, class V>
inline void Dictionary<K, V>::noElementMessage(const K & keyElement) const
{
	std::cout << "No element with key: " << keyElement << std::endl;
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary()
{
	this->key = nullptr;

	this->value = nullptr;

	this->currentSize = -1;

	this->capacity = -1;
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary(K * key, V * value, int currentSize, int capacity)
{
	this->currentSize = currentSize;

	this->capacity = capacity;

	this->key = new K[capacity];

	this->value = new V[capacity];

	for (size_t i = 0; i < currentSize; i++)
	{
		this->key[i] = key[i];

		this->value[i] = value[i];
	}
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary(const Dictionary & other)
{
	this->copy(other);
}

template<class K, class V>
inline Dictionary<K, V> & Dictionary<K, V>::operator=(const Dictionary & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		this->destroy();

		this->copy(other);
	}

	return *this;
}

template<class K, class V>
inline Dictionary<K, V>::~Dictionary()
{
	delete[] this->key;

	delete[] this->value;
}

template<class K, class V>
inline void Dictionary<K, V>::addNewElement(const K & newKey, const V & newValue)
{
	if (this->isFull())
	{
		this->resize();

		this->key[this->currentSize] = newKey;

		this->value[this->currentSize] = newValue;

		this->currentSize++;
	}
	else
	{
		this->key[this->currentSize] = newKey;

		this->value[this->currentSize] = newValue;

		this->currentSize++;

	}
}

template<class K, class V>
inline V Dictionary<K, V>::searchByKey(const K & keySearch) const
{
	bool checkCondition = false;

	for (size_t i = 0; i < this->currentSize; i++)
	{
		if (this->key[i] == keySearch)
		{
			return this->value[i];
		}
	}

	this->noElementMessage();

	return V();
}
