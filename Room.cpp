#include "Room.hpp"

Room::Room(int number, std::string type, double price) {
    roomNumber = number;
    roomType = type;
    pricePerNight = price;
    isItBooked = false;
}
