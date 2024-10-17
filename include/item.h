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
    static unsigned mNext_ID;
    int mID;
    Category mCategory;

protected:
    Item(Category Category) : mID(mNext_ID++), mCategory(Category) {}

public:
    virtual ~Item() = default;

    virtual auto get_id() const -> int { return mID; }
    virtual auto get_name() const -> std::string { return ""; }
    virtual auto get_dmg() const -> int { return 0; }
    virtual auto get_extra_dmg() const -> int { return 0; }
    virtual auto get_defensive() const -> int { return 0; }
    virtual auto get_extra_defensive() const -> int { return 0; }
    virtual auto get_durability() const -> int { return 0; }
    virtual auto get_category() const -> Category { return mCategory; }

    virtual auto display_item() const -> void = 0;
};
