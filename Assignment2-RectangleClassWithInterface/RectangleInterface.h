/** @file RectangleInterface.h */
#ifndef _RECTANGLE_INTERFACE
#define _RECTANGLE_INTERFACE

class RectangleInterface {

  public:

    /** Updates the length and width of this Rectangle
    @param  newLength the new length for this Circle
    @param  newWidth the new width for this Circle
    @pre    newLength and newWidth must be larger than zero
    @post   If newLength and newWidth are valid, the length and width of this object are set to newLength and newWidth respectively. Otherwise, the Rectangle is not updated. 
    @return true if this object is updated, and false otherwise. */ 
    virtual bool set(double length, double width) = 0;

    /** Gets the length  of this Rectangle
	  @return The length of this Rectangle. */
    virtual double getLength() const = 0;

    /** Gets the width  of this Rectangle
	  @return The width of this Rectangle. */
    virtual double getWidth() const = 0;

    /** Gets the area of this Rectangle
	  @return The area of this Rectangle. */
    virtual double getArea() const = 0;

    /** Destroys this Rectangle and frees its assigned memory. */
    virtual ~RectangleInterface() {}

}; 

#endif