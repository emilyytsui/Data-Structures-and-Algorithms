//Lesson11.cpp            //Author: Emily Tsui
//Special quadrilaterals as a sequence of Base and Derived classes

#include <iostream>
using namespace std;

class Quadrilateral{
  public:
    Quadrilateral(){
      cout << "Constructed Quadrilateral" << endl;
    }
    virtual void Properties(){
      cout << "A Quadrilateral is a four-sided polygon" << endl ;
    }
};

class Kite : public virtual Quadrilateral{
  public:
    Kite(){
      cout << "Constructed Kite" << endl;
    }
    void Properties() override{
      cout << "A Kite is a Quadrilateral with 2 sets of congurent consecutive sides" << endl ;
    }
};

class Trapezoid : public virtual Quadrilateral{
  public:
    Trapezoid(){
      cout << "Constructed Trapezoid" << endl;
    }
    void Properties() override{
      cout << "A Trapezoid is a Quadrilateral with exactly one pair of sides parallel" << endl ;
    }
};

class Parallelogram : public virtual Trapezoid{
  public:
    Parallelogram(){
        cout << "Constructed Parallelogram" << endl;
    }
    void Properties() override{
      cout << "A Parallelogram is a Quadrilateral with both pairs of opposite sides parallel" << endl ;
    }
};

class IsoscelesTrapezoid : public virtual Trapezoid{
  public:
    IsoscelesTrapezoid(){
      cout << "Constructed Isosceles Trapezoid" << endl;
    }
    void Properties() override{
      cout << "An Isosceles Triangle is a Trapezoid with the non-parallel sides (legs) congurent" << endl ;
    }
};

class Rhombus : public virtual Kite, virtual Parallelogram{
  public:
    Rhombus(){
      cout << "Constructed Rhombus" << endl;
    }
    void Properties() override{
      cout << "A Rhombus is a Parallelogram with all 4 sides congruent" << endl ;
    }
};

class Rectangle : public virtual Parallelogram, virtual IsoscelesTrapezoid{
  public:
    Rectangle(){
      cout << "Constructed Rectangle" << endl;
    }
    void Properties() override{
      cout << "A Rectangle is a Parallelogram with 4 right angles" << endl ;
    }
};

class Square : public virtual Rhombus, virtual Rectangle{
  public:
    Square(){
      cout << "Constructed Square" << endl;
    }
    void Properties() override final{
      cout << "A Square has all the properties of a Parallelogram, Rectangle, and a Rhombus" << endl ;
    }
};

int main() {
  Quadrilateral Quad;
  Quad.Properties();
  cout << endl;

  Kite Kite;
  Kite.Properties();
  cout << endl;

  Trapezoid Trap;
  Trap.Properties();
  cout << endl;

  Parallelogram Para;
  Para.Properties();
  cout << endl;

  IsoscelesTrapezoid IsosTri;
  IsosTri.Properties();
  cout << endl;

  Rhombus Rhom;
  Rhom.Properties();
  cout << endl;

  Rectangle Rect;
  Rect.Properties();
  cout << endl;

  Square Sq;
  Sq.Properties();
  cout << endl;
  
  return 0;
} 