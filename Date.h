#ifndef DATE_H
#define DATE_H

class Date
{
private:
	size_t day, month, year;

public:
	Date(size_t = 0, size_t = 0, size_t = 0);
	~Date();
	Date& operator = (const Date& other);

	void setDay(size_t);
	void setMonth(size_t);
	void setYear(size_t);

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;
};

#endif // !DATE_H
