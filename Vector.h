#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

class Vector
{
private:
	float *vector;
	size_t size;

	void resize(size_t newSize);
public:
	Vector();
	Vector(float *vector, size_t size);
	Vector(const Vector &other);
	Vector & operator=(const Vector &other);
	~Vector();


	friend Vector operator+(const Vector &left, const Vector &right);
	friend Vector operator-(const Vector &left, const Vector &right);

	friend Vector operator+(const Vector &left, const float &right);
	friend Vector operator+(const float &left, const Vector &right);

	friend Vector operator-(const Vector &left, const float &right);
	friend Vector operator-(const float &left, const Vector &right);
	
	Vector & operator+=(const float &number);
	Vector & operator-=(const float &number);

	friend Vector operator*(const Vector &left, const float &right);
	friend Vector operator*(const float &left, const Vector &right);
	Vector & operator*=(const float &number);

	friend float operator*(const Vector &left, const Vector &right);
	Vector & operator*=(const Vector &other);


	friend Vector operator/(const Vector &left, const float &right);
	Vector & operator/=(const float &number);


	Vector & operator+=(const Vector &other);
	Vector & operator-=(const Vector &other);

	float & operator[](const size_t &index);
	float operator[](const size_t &index) const;

	friend std::ostream& operator<<(std::ostream &out, const Vector &source);
	friend std::istream& operator>>(std::istream &in, Vector &source);

	Vector & operator!();
};

#endif // !VECTOR_H