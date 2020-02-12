//
// Created by LittleRandom on 2/10/2020.
//

#ifndef ECE309_SPR20_ARRAYLIST_H
#define ECE309_SPR20_ARRAYLIST_H

#include "Item.h"

using namespace ece309;


namespace ece309 {
    class ArrayList {
    private:
        StringItem* stringArray;
        int indexMax;
        int indexSize;

//        void rstIndex();
    public:
        ArrayList();
        ArrayList(const ArrayList &newArrayList);
        ~ArrayList();

       ArrayList& operator= (const ArrayList &rhs);


        bool empty() const;
        int size() const;
        void push_back(const StringItem &);
        void push_front(const StringItem&);
        bool pop_front(StringItem& replaceStringItem);
        bool pop_back(StringItem& replaceStringItem);
        void increment_array();

    };

}
#endif //ECE309_SPR20_ARRAYLIST_H
