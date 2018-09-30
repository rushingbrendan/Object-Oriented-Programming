#include "Shape.h"



class Square : public Shape {

private:

	double sideLength;


public:

	//constructors
	Square(void);
	Square(double inputSideLength, std::string inputColour);

	//destructor
	~Square(void);

	void SetSideLength(double inputSideLength);
	double GetSideLength(void);

	void Show(void);
	
	double OverallDimension(void);
	double Area(void);
	double Perimeter(void);


};