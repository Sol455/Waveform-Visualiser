#ifndef RMSCALC_H
#define RMSCALC_H
#include <iostream>
#include <vector>
#include <cmath>
#include "AudioFile.h"

class RmsCalc {

  public:

    //Constructor
    RmsCalc(std::string fileName, int stepsX, int scaleRangeY, int bufferSize);

    //Global variables
    AudioFile<double> audioFile;

    //Accessors
    std::vector<double> getRmsResults();
    void getAudioFileTest();
    std::string audioFileTest;

  private:
    //Member variables
    std::string _fileName;
    int _numSamples; 
    int _mainCounter; 
    int _rmsCounter; 
    int _rmsResultCounter; 
    int _bufferSize;
    int _stepsX;
    int _scaleRangeY;
    int _stepSize;
    double _sum; 
    double _currentSample;

    std::vector<double> _bufferCirc;
    std::vector<double> _rmsResultsBuffer;
    std::vector<double> _fftTestVector;

};

#endif
