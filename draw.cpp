#include "draw.h"
#include <iostream>
#include <cmath>

//----------------------Uniform List Initilisation---------------------
//Initialises member variables and populates some with user inputted values
Draw::Draw(std::vector<double> rmsResults, int stepsX, int scaleRangeY) :

  _rmsResults{rmsResults},
  _stepsX{stepsX},
  _scaleRangeY{scaleRangeY},
  _minValue {0.0},
  _maxValue {0.0},
  _pixelCounter {0},
  _currentScaledValue {0}
  {};


//-----------------------Scale and Draw method---------------------------
//Scales the generated RMS values to a user inputted range, then draws to console
void Draw::scaleAndDraw() {
  
  //find maximum and miniumum values contained in vector
  std::cout << "Calculating Min & Max RMS values...\n";
  for (int i=0; i < _stepsX; i++) {
    if (_rmsResults[i] >= _maxValue) {
      _maxValue = _rmsResults[i];
    } else if (_rmsResults[i] <= _maxValue) {
      _minValue = _rmsResults[i];
    }
  }
    
  //Scale these values to user defined range, write to vector, scale Array
  std::cout << "Scaling values to Y axis...\n";
    for (int i = 0; i < _stepsX; i++) {
    _currentScaledValue = round((((_rmsResults[i] - _minValue) / (_maxValue - _minValue)) * (_scaleRangeY - 0)));
    _scaleArray.insert(_scaleArray.begin() + i, _currentScaledValue );

  }

  //Ouput scaled values to command line using punctuation
  std::cout << "Drawing...\n\n";
  std::cout << "Amplitude\n";
  for (int i = _scaleRangeY; i > 0; i--) { // 10
    for (int j = 0; j < _stepsX; j++) { //15
      if (i <= _scaleArray[j]) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }
      _pixelCounter++;
    }

    if (_pixelCounter >= _stepsX) {
      std::cout << "\n";
      _pixelCounter = 0;
    }

  }

//Add x axis label at a distances determined by the user inputter number of steps
  std::string xLabel = " ";
  for (int i = 0; i < _stepsX; i++) {
    xLabel =  xLabel + " ";
  }
xLabel =  xLabel + "Time";
std::cout << xLabel << "\n\n\n";
std::cout << "Done.\n";
}   