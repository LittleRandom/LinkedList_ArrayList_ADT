//
// Created by LittleRandom on 2/10/2020.
//

#include "ArrayList.h"
#include "Item.h"
#include <cstring>
#include <string>
using namespace ece309;

namespace ece309{

    ArrayList::ArrayList(){
        indexSize = 0;
        indexMax = 4;
        stringArray = new StringItem[indexMax];

    };

    ArrayList::ArrayList(const ArrayList &newArrayList){
        this->indexSize = newArrayList.indexSize;
        this->indexMax = newArrayList.indexMax ;
        stringArray = new StringItem[indexMax];
        for(int i=0; i<newArrayList.indexMax;i++){
            this->stringArray[i] = newArrayList.stringArray[i];
        }

    }

    ArrayList& ArrayList::operator= (const ArrayList &rhs) {
        this->indexSize = rhs.indexSize;
        this->indexMax = rhs.indexMax;
        delete [] stringArray;
        this->stringArray = new StringItem[rhs.indexMax];
        for(int i=0; i <= rhs.indexMax ; i++){
            this->stringArray[i] = rhs.stringArray[i];
        }
        return *this;
    }

    ArrayList::~ArrayList(){
        delete [] stringArray;

    }

    int ArrayList::size() const{
        return indexSize;
    }

    bool ArrayList::empty() const {
        return (!indexSize);
    }

    void ArrayList::push_back(const StringItem& newStringItem){
        if(indexSize >= indexMax){
            increment_array();
        }
        stringArray[indexSize]=newStringItem;
        indexSize++;
    };

    void ArrayList::push_front(const StringItem& newStringItem) {
        if (indexSize >= indexMax ) {
            increment_array();
        }
        for (int i = indexMax-1; i > 0; i--) {
            stringArray[i] = stringArray[i-1];
        }
        stringArray[0] = newStringItem;
        indexSize++;
    };

    bool ArrayList::pop_back(StringItem & replaceStringItem) {
        if(!indexSize){
            return false;
        } else {
            replaceStringItem = stringArray[indexSize-1];
            indexSize--;
            return true;

        }
    }

    bool ArrayList::pop_front(StringItem& replaceStringItem) {
        if (indexSize) {
            replaceStringItem = this->stringArray[0];
            for (int i = 0; i < indexSize - 1; i++) {
                this->stringArray[i] = this->stringArray[i + 1];
            }

            indexSize--;
            return true;
        }
        return false;
    }

    void ArrayList::increment_array(){

        StringItem* newArray = new StringItem[indexMax*2];
        for(int i = 0; i < indexMax ; i++){
            newArray[i] = stringArray[i];
        }
        indexMax *= 2;
        delete[] stringArray;
        stringArray = newArray;
    }


}