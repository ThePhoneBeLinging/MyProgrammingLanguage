//
// Created by Elias Aggergaard Larsen on 04/09/2024.
//

#include "Item.h"

#include <utility>

Item::Item(std::string type, std::string value)
{
    type_ = std::move(type);
    value_ = std::move(value);
}

std::string Item::type() const
{
    return type_;
}

void Item::type(const std::string& type)
{
    type_ = type;
}

std::string Item::value() const
{
    return value_;
}

void Item::value(const std::string& value)
{
    value_ = value;
}
