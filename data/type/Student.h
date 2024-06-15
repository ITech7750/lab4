

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#include <utility>
#include <iostream>

#include "../../util/Definition.h"

class Student {
private:
    long id;
    String _name;
    String _surname;
    String _university;
    String _birthDate;

public:
    String address;
    String phone;
    int course;

    Student() {
        this->id = -1;
        _name = "";
        _surname = "";
        _birthDate = "";
        _university = "";

        course = -1;
        address = "";
        phone = "";
    }

    Student(
            long id,
            String name,
            String surname,
            String university,
            String birthDate
    ) {
        this->id = id;
        _name = std::move(name);
        _surname = std::move(surname);
        _birthDate = std::move(birthDate);
        _university = std::move(university);

        course = -1;
        address = "";
        phone = "";
    }

    Student(
            long id,
            String name,
            String surname,
            String university,
            String birthDate,
            String address,
            String phone,
            int course
    ) : Student(id, std::move(name), std::move(surname), std::move(university), std::move(birthDate)) {
        this->course = course;
        this->address = std::move(address);
        this->phone = std::move(phone);
    }

    String getName() const {
        return _name;
    }

    String getSurname() const {
        return _surname;
    }

    String getUniversity() const {
        return _university;
    }

    String getBirthDate() const {
        return _birthDate;
    }

    long getId() const {
        return id;
    }

    bool operator>(const Student& c) const {
        return id > c.id;
    }

    bool operator<(const Student& c) const {
        return id < c.id;
    }

    bool operator>=(const Student& c) const {
        return id >= c.id;
    }

    bool operator<=(const Student& c) const {
        return id < c.id;
    }

    bool operator==(const Student& c) const {
        return id == c.id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &s) {
        return os << "Student(" << s.getId() << ")";
    }
};




#endif //LAB3_STUDENT_H
