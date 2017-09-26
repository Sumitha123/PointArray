//
//  ptArray.hpp
//  pointArray
//
//  Created by Sumitha on 10/31/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#ifndef ptArray_hpp
#define ptArray_hpp

#include <iostream>
using namespace std;

//Point class
class Point
{
    private:
    int x;
    int y;
    
    public:
    Point(){ x = 0.0; y = 0.0; }
    Point(double x_val, double y_val){ x = x_val; y = y_val; }
    int getX() const;
    int getY() const;
    void setX(const int new_x);
    void setY(const int new_y);
    
};

// Point Array Class
class PointArray
{
    private:
    Point* pArray;
    int size;
    void resize(int n);
    
    public:
    int getSize() const;
    Point * getPoints() const;
    
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    void clear();
    Point* get(const int position);
    void printPointArray(const PointArray* pa);
    
};





#endif /* ptArray_hpp */
