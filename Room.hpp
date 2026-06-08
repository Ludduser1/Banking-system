#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include "Customer.hpp"

class Room {
public:
    int roomNumber;
    std::string roomType;
    double pricePerNight;
    bool isItBooked;
    Customer guest;

    Room(int number, std::string type, double price);
};

#endif