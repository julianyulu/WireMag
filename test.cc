// test.cc --- 
// 
// Filename: test.cc
// Description: 
// 
// Author:    Yu Lu
// Email:     yulu@utexas.edu
// Github:    https://github.com/SuperYuLu 
// 
// Created: Sun Aug 26 13:20:33 2018 (-0500)
// Version: 
// Last-Updated: Sun Aug 26 13:45:32 2018 (-0500)
//           By: yulu
//     Update #: 16
// 

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(){
  const std::string configFile = "config.txt";

  std::ifstream config(configFile);
  //std::istringstream is_file(configFile);
  std::string line;

  
  std::string key;
  std::string value;
  while( std::getline(config, line))
    {
      std::istringstream is_line(line);    
      //std::cout  << line << std::endl;
      if( std::getline(is_line, key, '=') )
	if (std::getline(is_line, value))
	  std::cout  << key << "," << value << std::endl;
    }

}
