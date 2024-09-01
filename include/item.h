#pragma once
#include <iostream>
#include <string>

enum class Category {
    WEAPON,
    ARMOR
};

class Item {
private:
    static int next_id;
    int id;
    Category category;

protected:
    Item(Category cat) : id(next_id++), category(cat) {}

public:
    virtual ~Item() = default;

    // Getter for id
    virtual int get_id() const { return id; }
    virtual std::string get_name() const { return ""; }
    virtual int get_dmg() const { return 0; }
    virtual int get_extra_dmg() const { return 0; }
    virtual int get_defensive() const { return 0; }
    virtual int get_extra_defensive() const { return 0; }
    virtual int get_durability() const { return 0; }

    // Getter for category
    virtual Category get_category() const { return category; }

    virtual void display_item() const = 0;
};