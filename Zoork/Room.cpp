#include "NullPassage.h"
#include "Room.h"

#include <utility>

Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}

std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}

void Room::addItem(const std::shared_ptr<Item>& item) {
    items[item->getName()] = item;
}

void Room::removeItem(const std::string &name) {
    items.erase(name);
}

std::shared_ptr<Item> Room::getItem(const std::string &name) const {
    auto it = items.find(name);
    if (it != items.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<Item> Room::retrieveItem(const std::string &name) {
    auto it = items.find(name);
    if (it != items.end()) {
        auto item = it->second;
        items.erase(it);
        return item;
    }
    return nullptr;
}
