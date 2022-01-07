#include <iostream>
#include <vector>

class Draw {

  public:

    //constructor
    Draw(std::vector<double> rmsResults, int stepsX, int scaleRangeY);
    
    //accessor
    void scaleAndDraw();

  private:
    //member variables
    int _stepsX;
    int _scaleRangeY;
    double _minValue;
    double _maxValue;
    int _pixelCounter;
    double _currentScaledValue;

    std::vector<double> _rmsResults;
    std::vector<int> _scaleArray;

};