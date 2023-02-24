// Name: Ansh GIrdhar
// Seneca Student ID: 152552204
// Seneca email: agirdhar@myseneca.ca
// Date of completion: 2022-11-15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.




#include <iostream>
#include "Utilities.h"

char sdds::Utilities::m_delimiter = '|';

void sdds::Utilities::setFieldWidth(size_t newWidth)
     {
         m_widthField = newWidth;
     }

size_t sdds::Utilities::getFieldWidth() const 
    {
        return m_widthField;
    }

string sdds::Utilities::extractToken(const string& str, size_t& nxtPosi, bool& more) 
    {

        if (str[nxtPosi] == m_delimiter || nxtPosi >= str.length()) {
            more = false;
            throw invalid_argument("Invalid next_pos argument");
    }

    string token = "";
    string whitespace = "";

    while (nxtPosi < (size_t)str.length()) {
        if (str[nxtPosi] != ' ') {
            if (str[nxtPosi] == '\n' || str[nxtPosi] == '\r') {
                break;
            } else if (str[nxtPosi] == m_delimiter) {
                if (m_widthField < token.length()) {
                    m_widthField = token.length();
                }
                more = true;
                nxtPosi++;
                return token;
            } else {
                if (token.length() > 0) {
                    token += whitespace + str[nxtPosi];
                    whitespace = "";
                } else {
                    token += str[nxtPosi];
                    whitespace = "";
                }

                if (nxtPosi == (size_t)str.length() - 1) {
                    if (m_widthField < token.length()) {
                        m_widthField = token.length();
                    }
                    more = false;
                    nxtPosi++;
                    return token;
                }
            }
        } else {
            whitespace += ' ';
        }
        nxtPosi++;
    }

    more = false;
    return token;
}
