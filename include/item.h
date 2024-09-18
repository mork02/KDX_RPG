#pragma once
#include <iostream>
#include <string>

enum class Category
{
    WEAPON,
    ARMOR
};

class Item
{
private:
    static int next_id;
    int id;
    Category category;

protected:
    Item(Category cat) : id(next_id++), category(cat) {}

public:
    virtual ~Item() = default;

    // Getter for id
    virtual auto get_id() const -> int { return id; }
    virtual auto get_name() const -> std::string { return ""; }
    virtual auto get_dmg() const -> int { return 0; }
    virtual auto get_extra_dmg() const -> int { return 0; }
    virtual auto get_defensive() const -> int { return 0; }
    virtual auto get_extra_defensive() const -> int { return 0; }
    virtual auto get_durability() const -> int { return 0; }

    // Getter for category
    virtual auto get_category() const -> Category { return category; }

    virtual auto display_item() const -> void = 0;
};
