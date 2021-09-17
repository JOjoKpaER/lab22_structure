#pragma once

#define delay 250

#include <string>

class datetime {
	
private:

	datetime* prev;
	datetime* next;

public:

	unsigned short second;
	unsigned short minute;
	unsigned short hour;
	unsigned short day;
	unsigned short month;
	unsigned short year;

	datetime() {
		second = NULL;
		minute = NULL;
		hour = NULL;
		day = NULL;
		month = NULL;
		year = NULL;
		prev = nullptr;
		next = nullptr;
	}

	datetime(unsigned int _second,
		unsigned int _minute,
		unsigned int _hour,
		unsigned int _day,
		unsigned int _month,
		unsigned int _year,
		datetime* _prev,
		datetime* _next) {
		if (_second < 60) {
			second = _second;
		}
		else {
			second = NULL;
			return;
		}
		if (_minute < 60) {
			minute = _minute;
		}
		else {
			second = NULL;
			minute = NULL;
			return;
		}
		if (_hour < 24) {
			hour = _hour;
		}
		else {
			second = NULL;
			minute = NULL;
			hour = NULL;
			return;
		}
		if (_month == 2) {
			if (_year % 4 == 0) {
				if (_year % 100 != 0 || _year % 400 == 0) {
					if (_day == 29)
						day = _day;
				}
				else if (_day < 29)
					day = _day;
				else {
					second = NULL;
					minute = NULL;
					hour = NULL;
					day = NULL;
					return;
				}
			}
			else if (_day < 29)
				day = _day;
			else {
				second = NULL;
				minute = NULL;
				hour = NULL;
				day = NULL;
				return;
			}
		}
		else
		if (_month == 1 && _day < 32 ||
			_month == 3 && _day < 32 ||
			_month == 4 && _day < 31 ||
			_month == 5 && _day < 32 ||
			_month == 6 && _day < 31 ||
			_month == 7 && _day < 32 ||
			_month == 8 && _day < 32 ||
			_month == 9 && _day < 31 ||
			_month == 10 && _day < 32 ||
			_month == 11 && _day < 31 ||
			_month == 12 && _day < 32) {
			day = _day;
		}
		else {
			second = NULL;
			minute = NULL;
			hour = NULL;
			day = NULL;
			return;
		}
		if (_month < 13 && _month > 0)
		{
			month = _month;
		}
		else {
			second = NULL;
			minute = NULL;
			hour = NULL;
			day = NULL;
			month = NULL;
			return;
		}
		if (_year < 65536) {
			year = _year;
		}
		else {
			second = NULL;
			minute = NULL;
			hour = NULL;
			day = NULL;
			month = NULL;
			year = NULL;
			return;
		}
		if (_prev) {
			prev = _prev;
			_prev->next = this;
		}
		if (_next) {
			next = _next;
			next->prev = this;
		}
	}

	datetime(datetime* copyFrom) {
		this->second = copyFrom->second;
		this->minute = copyFrom->minute;
		this->hour = copyFrom->hour;
		this->day = copyFrom->day;
		this->month = copyFrom->month;
		this->year = copyFrom->year;
		this->next = copyFrom->next;
		this->prev = copyFrom->prev;
	}

	unsigned short get_seconds() {
		return this->second;
	}

	unsigned short get_minutes() {
		return this->minute;
	}

	unsigned short get_hours() {
		return this->hour;
	}

	unsigned short get_days() {
		return this->day;
	}
	
	unsigned short get_months() {
		return this->month;
	}

	unsigned short get_years() {
		return this->year;
	}

	std::string get() {
		return    std::to_string(this->second) + ":" +
			std::to_string(this->minute) + ":" +
			std::to_string(this->hour) + " " +
			std::to_string(this->day) + "-" + 
			std::to_string(this->month) + "-" +
			std::to_string(this->year);
	}
};