#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

// the actual code you asked for
namespace ariel {
    string mat(int w, int h, char ch1, char ch2) {
        if (h % 2 == 0 || w % 2 == 0) {
            throw std::runtime_error("Mat size is always odd");
        }
        if (h < 0 || w < 0) {
            throw std::runtime_error("Mat size is always positive");
        }
        string ret;
        bool char1 = false;
        for (int j = 0 ; j < h; j++) {
            char1 = false;
            for (int i = 0 ; i < w ; i++){
                if (((j >= i && h - 1 - j >= i) && i <= w/2) || ((j >= w - i && h - 1 - j >= w - i) && i > w/2)) {
                    char1 = !char1;
                }
                if (char1) {
                    ret.push_back(ch1);
                }
                else {    
                    ret.push_back(ch2);
                }
            }
            
            ret.append("\n");    
        }
        return ret;
    }
}

// a function that also works with even values
namespace ariel2 {
    string mat(int w, int h, char ch1, char ch2) {
        if (h < 0 || w < 0) {
            throw std::runtime_error("Mat size is always positive");
        }
        string ret;
        bool char1 = false;
        for (int j = 0 ; j < h; j++) {
            char1 = false;
            for (int i = 0 ; i < w ; i++){
                if (((j >= i && h - 1 - j >= i) && ((i < w/2 && w % 2 == 0) || (i <= w/2 && w % 2 == 1))) || ((j >= w - i && h - 1 - j >= w - i) && i > w/2)) {
                    char1 = !char1;
                }
                if (char1) {
                    ret.push_back(ch1);
                }
                else {    
                    ret.push_back(ch2);
                }
            }
            
            ret.append("\n");    
        }
        return ret;
    }
}
