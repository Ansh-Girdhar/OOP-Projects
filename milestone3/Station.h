// Name: Ansh GIrdhar
// Seneca Student ID: 152552204
// Seneca email: agirdhar@myseneca.ca
// Date of completion: 2022-11-15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;

namespace sdds {
    class Station {
        int id;
        string name;
        string description;
        unsigned int nextSerialNum;
        unsigned int numItems;
        
        static size_t m_widthField;
        static int id_generator;

        public:
        Station(const string& record);
        const string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};


#endif