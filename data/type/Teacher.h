

#ifndef LAB3_TEACHER_H
#define LAB3_TEACHER_H

#include <utility>
#include <iostream>

#include "../../util/Definition.h"

class Teacher {
private:
    long id;
    String _name;
    String _surname;
    String _university;
    String _birthDate;

public:
    String address;
    String phone;
    int salary;

    Teacher() {
        this->id = -1;
        _name = "";
        _surname = "";
        _birthDate = "";
        _university = "";

        salary = -1;
        address = "";
        phone = "";
    }

    Teacher(
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

        salary = -1;
        address = "";
        phone = "";
    }

    Teacher(
            long id,
            String name,
            String surname,
            String university,
            String birthDate,
            String address,
            String phone,
            int salary
    ) : Teacher(id, std::move(name), std::move(surname), std::move(university), std::move(birthDate)) {
        this->salary = salary;
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

    bool operator>(const Teacher& c) const {
        return id > c.id;
    }

    bool operator<(const Teacher& c) const {
        return id < c.id;
    }

    bool operator>=(const Teacher& c) const {
        return id >= c.id;
    }

    bool operator<=(const Teacher& c) const {
        return id < c.id;
    }

    bool operator==(const Teacher& c) const {
        return id == c.id;
    }

    friend std::ostream &operator<<(std::ostream &os, const Teacher &s) {
        return os << "Teacher(" << s.getId() << ")";
    }
};


#endif //LAB3_TEACHER_H
