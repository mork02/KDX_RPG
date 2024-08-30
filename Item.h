#pragma once
#include <iostream>

class Item {
private:

public:
    // init
    virtual ~Item() = default; 

    // getter
    virtual int get_id() const { return 0; }
    virtual std::string get_name() const { return ""; }
    virtual int get_dmg() const { return 0; }
    virtual int get_extra_dmg() const { return 0; }
    virtual int get_defensive() const { return 0; }
    virtual int get_extra_defensive() const { return 0; }
    virtual int get_durability() const { return 0; }

    // methods
    virtual void display_item() const = 0;
};
