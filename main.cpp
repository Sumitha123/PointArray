//
//  main.cpp
//  pointArray
//
//  Created by Sumitha on 10/31/16.
//  Copyright © 2016 Sumitha. All rights reserved.
//

#include "ptArray.hpp"

int main()
{
    
    
    //Instantiate a PointArray object parray of size 0.
    PointArray* parray = new PointArray();
    cout<< "Instantiated a PointArray object parray of size 0" << endl;
    
    //Call push_back member function multiple times to add multiple Point objects into parray.
    Point p1 = Point(1,2);
    Point p2 = Point(3,8);
    Point p3 = Point(6,6);
    
    parray->push_back(p1);
    parray->printPointArray(parray);
    
    parray->push_back(p2);
    parray->printPointArray(parray);
    
    parray->push_back(p3);
    parray->printPointArray(parray);
    
    //Call insert and remove member functions multiple times to add and remove Point objects inside parray
    Point p4 = Point(9,9);
    Point p5 = Point(1,6);
    
    parray->insert(1,p4);
    parray->printPointArray(parray);
    
    parray->remove(2);
    parray->printPointArray(parray);
    
    
    parray->remove(1);
    parray->printPointArray(parray);
    
    parray->insert(2,p5);
    parray->printPointArray(parray);
    
 
    //Call getSize member function to print the number of Point objects inside parray
    cout << "Number of Point objects inside parray : " << parray->getSize() << endl;
    
    //Print the contents of all Point objects inside parray.
    parray->printPointArray(parray);

    
    //Instantiate another PointArray object qarray by assigning it to be equal to parray(copy constructor)
    PointArray* qarray(parray);
    
    //Print the contents of all Point objects inside qarray.
    cout << "Point objects in qarray created from copy constructor" << endl;;
    qarray->printPointArray(qarray);
    
    
    //Delete parray.
    parray->~PointArray();
    cout << "parray deleted " << endl;
    
    //Call clear member function to clear the array contents in qarray
    qarray->clear();
    cout << "qarray cleared " << endl;
    
    //Instantiate another PointArray object rarray providing qarray and its size as two parameters.
    Point* points = (Point*)qarray;
    PointArray* rarray = new PointArray(points,1);
    cout << "Instantiated another PointArray object rarray providing qarray and its size" << endl;
    
    //Delete qarray.
    qarray->~PointArray();
    cout << "Deleted qarray" << endl;
    
    //Call get member function to change the contents of the first Point object inside rarray.
    rarray->get(0);
    rarray->push_back(p1);
    
    //Use const get member function to print the contents of all Point objects inside rarray.
    //printPointArray() function makes use of const get member function.
    rarray->printPointArray(rarray);
    
    
}

