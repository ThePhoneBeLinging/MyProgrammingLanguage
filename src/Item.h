//
// Created by Elias Aggergaard Larsen on 04/09/2024.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item
{
public:
    Item(std::string type, std::string value);
    [[nodiscard]] std::string type() const;
    void type(const std::string& type);
    [[nodiscard]] std::string value() const;
    void value(const std::string& value);

private:
    std::string type_;
    std::string value_;
};


#endif //ITEM_H
