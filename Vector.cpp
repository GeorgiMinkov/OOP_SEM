// Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector.h"
#include<cmath>
#include<cassert>

void copy(float *& source, float *other, size_t sizeOther);

int main()
{
    return 0;
}

void Vector::resize(size_t newSize)
{
	float *buffer = new float[newSize];

	for (size_t i = 0; i < newSize; ++i)
		buffer[i] = this->vector[i];

	delete[] this->vector;

	this->vector = buffer;

	this->size = newSize;
}

Vector::Vector()
{
	this->size = 1;

	this->vector = new float[this->size];
}

Vector::Vector(float * vector, size_t size)
{
	copy(this->vector, vector, size);
	
	this->size = size;
}

Vector::Vector(const Vector & other)
{
	copy(this->vector, other.vector, other.size);
	this->size = other.size;
}

Vector & Vector::operator=(const Vector & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		if (this->vector != NULL) delete[] this->vector;

		copy(this->vector, other.vector, other.size);
		
		this->size = other.size;
	}

	return *this;
}

Vector::~Vector()
{
	delete[] this->vector;
}

Vector & Vector::operator+=(const float & number)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < this->size; ++i)
		this->vector[i] += number;
	
	return *this;
}

Vector & Vector::operator-=(const float & number)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < this->size; ++i)
		this->vector[i] -= number;

	return *this;
}

Vector & Vector::operator*=(const float & number)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < this->size; ++i)
		this->vector[i] *= number;

	return *this;
}

Vector & Vector::operator*=(const Vector & other)
{
	// TODO: insert return statement here
	if (this->size > other.size)
	{
		for (size_t i = 0; i < this->size; ++i)
		{
			if (i < other.size)	this->vector[i] *= other.vector[i];
			else this->vector[i] = 0;
		}
	}
	else
	{
		const size_t oldSize = this->size;
		resize(other.size);

		for (size_t i = 0; i < other.size; ++i)
		{
			if (i < oldSize) this->vector[i] *= other.vector[i];
			else this->vector[i] = 0;
		}
	}
	return *this;
}

Vector & Vector::operator/=(const float & number)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < this->size; ++i)
		this->vector[i] /= number;

	return *this;
}

Vector & Vector::operator+=(const Vector & other)
{
	// TODO: insert return statement here
	if (this->size >= other.size)
	{
		for (size_t i = 0; i < other.size; ++i) // Върти до големината на по - малкият за да не се налага вътрепна проверка
			this->vector[i] += other.vector[i];
	}
	else
	{
		size_t oldSize = this->size;

		resize(other.size); // Преоразмерява до големината на по - големия

		for (size_t i = 0; i < other.size; ++i)
		{
			if (i < oldSize) this->vector[i] += other.vector[i];
			else this->vector[i] = other.vector[i];
		}
	}

	return *this;
}

Vector & Vector::operator-=(const Vector & other)
{
	// TODO: insert return statement here
	if (this->size >= other.size)
	{
		for (size_t i = 0; i < other.size; ++i)
			this->vector[i] -= other.vector[i];
	}
	else
	{
		size_t oldSize = this->size;

		resize(other.size);

		for (size_t i = 0; i < other.size; ++i)
		{
			if (i < oldSize) this->vector[i] -= other.vector[i];
			else this->vector[i] = (-1)*other.vector[i];
		}
	}

	return *this;
}

float & Vector::operator[](const size_t &index)
{
	// TODO: get index numbered element
	assert(("ILLEGAL INDEX", index >= 0 && index < this->size));

	return this->vector[index];
}

float Vector::operator[](const size_t &index) const
{
	assert(("ILLEGAL INDEX", index >= 0 && index < this->size));

	return this->vector[index];
}

Vector & Vector::operator!()
{
	// TODO: insert return statement here
	*this /= sqrt(*this * *this);

	return *this;
}

void copy(float *& source, float *other, size_t sizeOther)
{
	source = new float[sizeOther];
	assert(source);

	for (size_t i = 0; i < sizeOther; ++i)
		source[i] = other[i];
}

Vector operator+(const Vector & left, const Vector & right)
{
	size_t size = (left.size > right.size) ? left.size : right.size;
	float *tmp = new float[size];

	if (left.size > right.size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (i < right.size) tmp[i] = left.vector[i] + right.vector[i];
			else tmp[i] = left.vector[i] + 0;
		}
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (i < left.size) tmp[i] = left.vector[i] + right.vector[i];
			else tmp[i] = 0 + right.vector[i];
		}
	}

	return Vector(tmp, size);
}

Vector operator-(const Vector & left, const Vector & right)
{
	size_t size = (left.size > right.size) ? left.size : right.size;
	float *tmp = new float[size];

	if (left.size > right.size)
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (i < right.size) tmp[i] = left.vector[i] - right.vector[i];
			else tmp[i] = left.vector[i] - 0;
		}
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			if (i < left.size) tmp[i] = left.vector[i] - right.vector[i];
			else tmp[i] = 0 - right.vector[i];
		}
	}

	return Vector(tmp, size);
}

Vector operator+(const Vector & left, const float & right)
{
	float *tmp = new float[left.size];

	for (size_t i = 0; i < left.size; ++i)
		tmp[i] = left.vector[i] + right;

	return Vector(tmp, left.size);
}

Vector operator+(const float & left, const Vector & right)
{
	float *tmp = new float[right.size];

	for (size_t i = 0; i < right.size; ++i)
		tmp[i] = left + right.vector[i];

	return Vector(tmp, right.size);
}

Vector operator-(const Vector & left, const float & right)
{
	float *tmp = new float[left.size];

	for (size_t i = 0; i < left.size; ++i)
		tmp[i] = left.vector[i] - right;

	return Vector(tmp, left.size);
}

Vector operator-(const float & left, const Vector & right)
{
	float *tmp = new float[right.size];

	for (size_t i = 0; i < right.size; ++i)
		tmp[i] = left - right.vector[i];

	return Vector(tmp, right.size);
}

Vector operator*(const Vector & left, const float & right)
{
	float *tmp = new float[left.size];

	for (size_t i = 0; i < left.size; ++i)
		tmp[i] = left.vector[i] * right;

	return Vector(tmp, left.size);
}

Vector operator*(const float & left, const Vector & right)
{
	float *tmp = new float[right.size];

	for (size_t i = 0; i < right.size; ++i)
		tmp[i] = left * right.vector[i];

	return Vector(tmp, right.size);
}

float operator*(const Vector & left, const Vector & right)
{
	size_t size = (left.size < right.size) ? left.size : right.size;
	float tmp = 0;

	for (size_t i = 0; i < size; i++)
		tmp += left.vector[i] * right.vector[i];

	return tmp;
}

Vector operator/(const Vector & left, const float & right)
{
	for (size_t i = 0; i < left.size; ++i)
		left.vector[i] /= right;

	return Vector(left.vector, left.size);
}

std::ostream & operator<<(std::ostream & out, const Vector & source)
{
	// TODO: insert return statement here
	const size_t size = source.size - 1;
	
	out << "(";

	for (size_t i = 0; i <= size; ++i)
	{
		if (i < size)	out << source.vector[i] << ", "; 
		else out << source.vector[i] << ")";
	}

	return out;
}

std::istream & operator >> (std::istream & in, Vector & source)
{
	// TODO: insert return statement here
	int size;
	do
	{
		std::cout << "Enter positive size: ";
		in >> size;
	} while (size <= 0);

	source.vector = new float[size];

	source.size = size;

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Enter element N: " << i + 1 << ": ";
		in >> source.vector[i];
	}

	return in;
}