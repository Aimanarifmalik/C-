#include<iostream>

using namespace std;

class Hexagon {
	
	protected:
    	int side = 2;
    	int angle = 120;

	public:
    	int calcArea() {
        	int area = 1.5 * 1.732 * side;
        	return area;
    	}

    	int calcPeri() 
		{
        	int P = 6 * side;
        	return P;
    	}

   		int calcAngleSum() 
		{
        	int A = 6 * angle;
        	return A;
    	}

    	int show();
};

class Square {
	
	protected:
    	int length = 3;

	public:
    	int calcAreaSquare() 
		{
        	int area = length * length;
        	return area;
    	}

    	int calcPeriSquare() 
		{
        	int perimeter = 4 * length;
        	return perimeter;
    	}
};

int Hexagon::show() 
{
    while (1) 
	{
        int num;
        cout<<"\nEnter 1 to calculate the area, perimeter, and sum of angles of hexagon: ";
        cout<<"\nEnter 2 to calculate the area and perimeter of Square: ";
        cout<<"\nEnter any other number to exit: ";
        cin>>num;

        if (num == 1) 
		{
            cout<<"\nHexagon Area: "<<calcArea();
            cout<<"\nHexagon Perimeter: "<<calcPeri();
            cout<<"\nHexagon Sum of Angles: "<<calcAngleSum()<<endl;
            
        } 
		else if (num == 2) 
		{
            Square square;
            cout<<"\nSquare Area: "<<square.calcAreaSquare();
            cout<<"\nSquare Perimeter: "<<square.calcPeriSquare()<<endl;
        } 
		else 
		{
            cout<<"\nExiting.......\n";
            break;
        }
    }
    return 0;
}

int main() 
{
    Hexagon hexagon;
    hexagon.show();
    return 0;
}

