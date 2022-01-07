#include <iostream>
#include "AudioFile.h"
#include "rmsCalc.h"
#include "draw.h"
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>

//Main function, visualises the waveform of a user inputted wave file
void visualiseWaveform() {
  bool menuReturn = 1;
  std::string returnInput;
  std::string line;


  while (true) {
    if (menuReturn == 1){
      std::string file;
      int xSize, ySize;

//Draw the menu by reading a text file
      std::ifstream f("waveformTitle.txt"); 
      std::string str;
      if(f) {
        std::ostringstream ss;
        ss << f.rdbuf(); 
        str = ss.str();
      }
    std::cout<<str;

    
  //Prompt the use for inputs
      std::cout << "\nEnter a filename: \n";
      std::cin >> file;
      std::cout << "Enter the X axis size: \n";
      std::cin >> xSize;
      std::cout << "Enter the Y axis size: \n";
      std::cin >> ySize;

      //Calculate rms values 
      //fileName, X axis size, Y asix size, bufferSize
      RmsCalc rmsCalc(file, xSize, ySize, 512);
      std::vector<double> results = rmsCalc.getRmsResults();

      //Scale and draw these rsm values to the console
      //rms results vector, X axis size, Y asix size
      Draw draw(results, xSize, ySize);
      draw.scaleAndDraw();
      }

      //Menu functionality to process another file.
      menuReturn = 0;
      if (menuReturn == 0 ) {
        std::cout << "Input b to process another file: ";
        std::cin >> returnInput;
      if (returnInput == "b" || "B")  {
        menuReturn = 1;
        } else {
          menuReturn = 0;
        }
    }
  } 

}

int main() {
  visualiseWaveform();
}
