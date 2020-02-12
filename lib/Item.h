//
// Class that represents a data item, for use in data structures.
// Can change the type of the data field and recompile library.
// ECE 309 - Spring 2020
//

#ifndef ECE309_SPR20_ITEM_H
#define ECE309_SPR20_ITEM_H

#include <string>
using std::string;

#include <cstdio>

namespace ece309 {

    // base class -- no data, just virtual functions
    class Item {
    public:
        virtual ~Item() {}
        virtual void print() const { printf("Item!"); }
        virtual string to_string() const { return string(""); }
    };

    class StringItem : public Item {
    public:
        const char * str;
        StringItem(const char *s=""):str(s) {}
        void print() const { printf("%s", str); }
        string to_string() const { return string(str); }
    };

    class IntegerItem : public Item {
    public:
        int i;
        IntegerItem(int ii=0):i(ii) {}
        void print() const { printf("%d", i); }
        string to_string() const { return std::to_string(i);}
    };

}

#endif //ECE309_SPR20_ITEM_H
