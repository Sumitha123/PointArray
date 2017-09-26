#include "ptArray.hpp"

/* Class Member function Definitions */
int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(const int new_x)
{
    x = new_x;
    cout << "new x coordinate : " << x << endl;
}

void Point::setY(const int new_y)
{
    y = new_y;
    cout << "new y coordinate : " << y << endl;
}



int PointArray :: getSize() const
{
    return size;
}

Point* PointArray :: getPoints() const
{
    return pArray;
}

//Default constructor
PointArray :: PointArray()
{
    size = 0;
    Point* pArray = new Point [size];
    pArray = {};
}

//Constructor that takes a points Array called points[] and it's size as parameters
PointArray :: PointArray(const Point points[], const int size)
{
    pArray = new Point[size];
    for (int i = 0; i < size; i++)
    {
        pArray[i] = points[i];
    }
}

//Copy constructor that creates a copy of a given Point Array
PointArray :: PointArray(const PointArray &pv)
{
    size = getSize();
    pArray = new Point[size];
    for(int i = 0; i < size; i++)
    {
        pArray[i] = pv.getPoints()[i];
    }
    
}

PointArray :: ~PointArray()
{
    delete[] pArray;
}


void PointArray::resize(int n)
{
    Point* new_pArray = new Point[n];
    
    // copy the first min(previous array size, n) existing elements
    for (int i = 0; i < (size < n ? size : n); i++)
    new_pArray[i] = pArray[i];
    
    
    // set new attributes
    pArray = new_pArray;
    size = n;
}

//Add a Point to the end of the array
void PointArray:: push_back(const Point &p)
{
    resize(size + 1);
    pArray[size -1] = p;
    cout << "Added Point (" << p.getX() <<","<< p.getY() << ") at the end of the array." << endl;
}

void PointArray::insert(const int position, const Point &p)
{
    // increase array size
    resize(size + 1);
    
    // Shifting Array elements to the right after the insertion point
    for (int i = size - 1; i > position; i--)
    pArray[i] = pArray[i-1];
    
    // insert p
    pArray[position] = p;
    
    cout<< "Inserted a Point (" << p.getX() <<","<< p.getY() << ") to  PointArray at index : "<< position <<endl;
}

void PointArray::remove(const int pos)
{
    // Remove the Point at pos, shifting the remaining elements to the left
    for (int i = pos; i < size ; i++)
    {
        Point x;
        if(i == pos)
        {
            x = pArray[i];
        }
        pArray[i] = pArray[i+1];
    // resize array
    resize(size - 1);
    cout << "Removed Point (" << x.getX() <<","<< x.getY() << ") from PointArray at index : "<< pos << endl;
    }

}
    // Remove everything from the array and sets its size to 0
void PointArray::clear()
{
    resize(0);
}

//Get a pointer to the element at some arbitrary position
Point* PointArray::get(const int position)
{
    return pArray + position;
}

void PointArray::printPointArray(const PointArray* pa)
{
    cout << "Point objects : " << endl;
    for(int i = 0; i<pa->getSize();i++)
    {
        cout << "(" << pa->getPoints()[i].getX()<<"," << pa->getPoints()[i].getY() << ")" <<endl;
    
    }
    
}




