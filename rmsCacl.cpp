#include "rmsCalc.h"
#include <iostream>

//----------------------Uniform List Initilisation---------------------
//Initialises member variables and populates some with user inputted values
RmsCalc::RmsCalc(std::string fileName, int stepsX, int scaleRangeY, int bufferSize) :

_fileName{fileName}, 
_numSamples{0}, 
_stepsX{stepsX}, 
_scaleRangeY{scaleRangeY},
_bufferSize{bufferSize}, 
_mainCounter {0},
_rmsCounter {0},
_rmsResultCounter {0},
_sum {0},
_stepSize {0},
_currentSample {0}
{};

//-----------------------Rms Results Calculator---------------------------
//Produces an array of RMS values, calculater from the audiofile
std::vector<double> RmsCalc::getRmsResults() {
  audioFile.load(_fileName);  //load audio file object
  audioFile.printSummary(); //prints summary
  std::cout << "Calculating RMS Values...\n";
  _numSamples = audioFile.getNumSamplesPerChannel();
  _stepSize = round(_numSamples / _stepsX);

  while (_mainCounter < _numSamples) {   //sets the buffer size, for i < 512 increase
  for (int i = 0; i < _bufferSize; i++) {
    if (_mainCounter >= _numSamples) {     // if the counter >= number of samples, break the while loop
      break;
    }

    _currentSample = (audioFile.samples[1][_mainCounter] + audioFile.samples[1][_mainCounter]) / 2 ; //current sample  is equal to the counter ++, summed to
    _bufferCirc.insert (_bufferCirc.begin() + i, _currentSample);  //write current sample to the buffer
    _mainCounter++;     //increase the counter
    _sum =+ _currentSample * _currentSample;     //sum the square of the all thesamples
    _rmsCounter++;      //sum the square of the all thesamples

    if (_rmsCounter == _stepSize) { //Checks to see if buffer is full
      _rmsResultsBuffer.insert(_rmsResultsBuffer.begin() + _rmsResultCounter, sqrtf(_sum/_stepSize)); //calculater rms of buffer and adds to rms results vector
      _rmsResultCounter++; // increase results counter
      _sum = 0; 
      _rmsCounter = 0; //reset sum variable and counter to 0
      }
    }
  }
  std::cout << "RMS Values Calculated.\n";
  return _rmsResultsBuffer; //return array of rms values
}