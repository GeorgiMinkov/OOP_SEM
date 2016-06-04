#pragma once
#include<iostream>

template<class K, class V>
class Dictionary
{
	K *keys;
	V *values;

	int currentSize;
	int capacity;

	void resize();
	void copyElemets(K *keys, V *values, int currentSize, int capacity);
	void copyObjet(const Dictionary &other);
	void destroy();

	void sort();

	bool isEmpty() const;
	bool isFull() const;
public:
	Dictionary();
	Dictionary(K *keys, V *values, int currentSize, int capacity);
	Dictionary(const Dictionary &other);
	Dictionary &operator=(const Dictionary &other);
	~Dictionary();

	V searchByKey(const K &searchKey) const;
	void addNewElement(const K &newKey, const V &newValue);
	void deleteByKey(const K &deleteKey);

	template<class KK, class VV>
	friend std::ostream &operator<<(std::ostream &out, const Dictionary<KK, VV> &source);
};

template<class K, class V>
inline void Dictionary<K, V>::resize()
{
	if (this->capacity == 0) this->capacity = 1;

	int GAP = ceil(this->capacity * 1.7);

	K *keyBuffer = new K[GAP];
	V *valueBuffer = new V[GAP];

	for (size_t i = 0; i < this->currentSize; i++)
	{
		keyBuffer[i] = this->keys[i];

		valueBuffer[i] = this->values[i];
	}

	this->destroy();

	this->keys = keyBuffer;
	this->values = valueBuffer;

	this->capacity = GAP;
}

template<class K, class V>
inline void Dictionary<K, V>::copyElemets(K * keys, V * values, int currentSize, int capacity)
{
	this->keys = new K[capacity];
	this->values = new V[capacity];

	this->currentSize = currentSize;
	this->capacity = capacity;

	for (size_t i = 0; i < currentSize; i++)
	{
		this->keys[i] = keys[i];
		
		this->values[i] = values[i];
	}
}

template<class K, class V>
inline void Dictionary<K, V>::copyObjet(const Dictionary & other)
{
	this->capacity = other.capacity;
	this->currentSize = other.currentSize;

	this->keys = new K[this->capacity];
	this->values = new V[this->capacity];

	for (size_t i = 0; i < this->currentSize; i++)
	{
		this->keys[i] = other.keys[i];

		this->values[i] = other.values[i];
	}
}

template<class K, class V>
inline void Dictionary<K, V>::destroy()
{
	if (this->keys != nullptr) delete[] this->keys;
	if (this->values != nullptr) delete[] this->values;
}

template<class K, class V>
inline void Dictionary<K, V>::sort()
{
	if (this->currentSize == 0) return;

	for (size_t i = 0; i < this->currentSize - 1; i++)
	{
		for (size_t j = 0; j < this->currentSize - i - 1; j++)
		{
			if (this->keys[j] > this->keys[j + 1])
			{
				K tmpKey = this->keys[j];
				V tmpValue = this->values[j];

				this->keys[j] = this->keys[j + 1];
				this->keys[j + 1] = tmpKey;

				this->values[j] = this->values[j + 1];
				this->values[j + 1] = tmpValue;
			}
		}
	}
}

template<class K, class V>
inline bool Dictionary<K, V>::isEmpty() const
{
	return this->currentSize == 0;
}

template<class K, class V>
inline bool Dictionary<K, V>::isFull() const
{
	return this->currentSize == this->capacity;
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary()
{
	this->keys = nullptr;
	this->values = nullptr;
	this->currentSize = 0;
	this->capacity = 0;
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary(K * keys, V * values, int currentSize, int capacity)
{
	this->copyElemets(keys, values, currentSize, capacity);
}

template<class K, class V>
inline Dictionary<K, V>::Dictionary(const Dictionary & other)
{
	this->copyObjet(other);
}

template<class K, class V>
inline Dictionary<K,V> & Dictionary<K, V>::operator=(const Dictionary & other)
{
	// TODO: =
	if (this != &other)
	{
		this->destroy();

		this->copyObject(other);
	}

	return *this;
}

template<class K, class V>
inline Dictionary<K, V>::~Dictionary()
{
	delete[] this->keys;
	delete[] this->values;
}

template<class K, class V>
inline V Dictionary<K, V>::searchByKey(const K & searchKey) const
{
	if (!(this->isEmpty()))
	{
		for (size_t i = 0; i < this->currentSize; i++)
		{
			if (this->keys[i] == searchKey)
			{
				return this->values[i];
			}
		}
	}

	std::cout << "No element with key: " << searchKey << " was founded\nWill return empty value\n";

	return V();
}

template<class K, class V>
inline void Dictionary<K, V>::addNewElement(const K & newKey, const V & newValue)
{
	if (this->isFull())
	{
		this->resize();

		this->keys[this->currentSize] = newKey;
		this->values[this->currentSize] = newValue;

		this->currentSize++;
	}
	else
	{
		this->keys[this->currentSize] = newKey;
		this->values[this->currentSize] = newValue;

		this->currentSize++;
	}
}

template<class K, class V>
inline void Dictionary<K, V>::deleteByKey(const K & deleteKey)
{
	bool check = false;
	if (type_name<K>::get() == "string")
	{
		for (size_t i = 0; i < this->currentSize && !check; i++)
		{
			std::string tmpKey = this->keys[i], tmpDelKey = deleteKey;
			if (tmpKey.compare(deleteKey) == 0)
			{
				for (size_t j = i; j < this->currentSize - 1; j++)
				{
					this->keys[j] = this->keys[j + 1];
					this->values[j] = this->values[j + 1];
				}
				this->currentSize--;
				check = true;
			}
		}
	}
	else
	{
		for (size_t i = 0; i < this->currentSize && !check; i++)
		{
			if (this->keys[i] == deleteByKey) // Отделил съм отделен случай за стринг, как да преодолея Грешка C2678 тогава.
			{
				for (size_t j = i; j < this->currentSize - 1; j++)
				{
					this->keys[j] = this->keys[j + 1];
					this->values[j] = this->values[j + 1];
				}
				this->currentSize--;
				check = true;
			}
		}
	}
}	

template<class K, class V>
std::ostream &operator<<(std::ostream &out, const Dictionary<K, V> &source)
{
	Dictionary<K, V> tmp(source);

	tmp.sort();

	for (size_t i = 0; i < tmp.currentSize; i++)
		out << "Key: " << tmp.keys[i] << " Value: " << tmp.values[i] << "\n";
		
	return out;
}

template<class T>
class type_name 
{
public:
	static std::string get() { return typeid(T).name(); }
};
template<>
class type_name<std::string> 
{
public:
	static std::string get() { return "string"; }
};

template<>
class type_name<const char *>
{
public:
	static std::string get() { return "string"; }
};

template<int N>
class type_name<const char[N]> 
{
public:
	static std::string get() { return "string"; }
};