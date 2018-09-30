#include "Shape.h"



class Circle : public Shape {

private:

	double radius;

	
public:

	//constructors
	Circle(void);	//default
	Circle(double inputRadius, std::string inputColour);

	//destructor
	~Circle(void);

	double GetRadius(void);
	void SetRadius(double inputRadius);

	void Show(void);

	double OverallDimension(void);
	double Area(void);
	double Perimeter(void);
};
