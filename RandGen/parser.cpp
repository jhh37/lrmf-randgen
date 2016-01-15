#include <iostream>
#include <cmath>

#include "parser.h"

void parse_options_from_args(int argc, char* argv[], options_t &options) {
  
  // If no arguments provided, check for help and then allow user to type them one by one.
  if (argc < 2) {
    
    parse_options_manually(options, 1);
    
    // Otherwise, parse the input arguments.
  } else {
    
    std::string arg;
    std::string argType;
    int len = 0;
    
    for (int i = 1; i < argc; i++) {
      
      arg = argv[i];
      len = int(arg.find('='));
      argType = arg.substr(0, len);
      arg = arg.substr(len + 1);
      
      // Parse dataset.
      if (argType == "-d" || argType == "--dataset") {
        options.dataset = arg;
      } else if (argType == "-f" || argType == "--folder") {
        options.folder = arg;
        // Parse the number of rows.
      } else if (argType == "-m" || argType == "--rows") {
        options.m = atoi(arg.c_str());
        // Parse the number of columns.
      } else if (argType == "-n" || argType == "--cols") {
        options.n = atoi(arg.c_str());
        // Parse rank.
      } else if (argType == "-r" || argType == "--rank") {
        options.r = atoi(arg.c_str());
        // Parse random seed.
      } else if (argType == "-s" || argType == "--seed") {
        options.seed = atoi(arg.c_str());
        // Parse the number of columns.
      } else if (argType == "--debug") {
        options.DEBUG =  atoi(arg.c_str()) > 0 || (arg == argType);
        // Output a list of commands.
      } else if (argType == "/?" || argType == "-h" || argType == "--help") {
        options.HELP = true;
        outputCommands();
        return;
      }
    } // End of for loop
    
    // Parse options manually for incorrect inputs.
    parse_options_manually(options, 0);
    
    // If debug is on, output the input arguments.
    if (options.DEBUG) {
      
      std::cout << std::endl;
      
      std::cout << "---[ PARSED INPUT ARGUMENTS ]---" << std::endl;
      
      std::cout << "1. Dataset: " << options.dataset << std::endl;
      std::cout << "2. Folder: " << options.folder << std::endl;
      std::cout << "3. Size: " << options.m << " x " << options.n << std::endl;
      std::cout << "4. Rank: " << options.r << std::endl;
      std::cout << "5. Seed: " << options.seed << std::endl;
      std::cout << "6. Display: " << options.DISPLAY << std::endl;
      
      std::cout << std::endl;
      
    }
  }
  
  return;
}

void parse_options_manually(options_t &options, bool START_FROM_SCRATCH) {
  
  // If starting from scratch, reset the options to default.
  if (START_FROM_SCRATCH) { options.reset(); }
  
  while (options.dataset.length() < 1) {
    std::cout << "Please enter the name of the dataset: ";
    std::cin >> options.dataset;
  }
  while (options.m < 1) {
    std::cout << "Please enter the number of rows (m): ";
    std::cin >> options.m;
  }
  while (options.n < 1) {
    std::cout << "Please enter the number of columns (n): ";
    std::cin >> options.n;
  }
  while (options.r < 1) {
    std::cout << "Please enter the proposed rank (r): ";
    std::cin >> options.r;
  }
  
  //  // Only type again the followings if starting from scratch.
  //  if (START_FROM_SCRATCH) {
  //    std::cout << "Please specify the tolerance threshold (default = 1e-9): ";
  //    std::cin >> options.tol;
  //
  //    std::cout << "Please specify the iteration threshold (default = 300): ";
  //    std::cin >> options.max_iter;
  //  }
  
  return;
}

void outputCommands() {
  
  std::cout << std::endl;
  
  std::cout << "--- [ LIST OF COMMANDS ] ---" << std::endl << std::endl;
  
  std::cout << "[ Dataset-related ]" << std::endl;
  std::cout << "-d=<string>, --dataset=<string>: Read dataset from <name>_r<rank>_{M, W, U0, V0}.bin." << std::endl;
  std::cout << "-f=<string>, --folder=<string>: Set the name of the folder." << std::endl;
  std::cout << "-m=<int>, --rows=<int>: Set the number of rows." << std::endl;
  std::cout << "-n=<int>, --cols=<int>: Set the number of columns." << std::endl;
  std::cout << "-r=<int>, --rank=<int>: Set the proposed rank." << std::endl;
  std::cout << "-s=<int>, --seed=<int>: Set the random seed." << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "[ Program-related ]" << std::endl;
  std::cout << "--display[=<bool>]: Specify whether to show progress in detail. (default = 1)" << std::endl;
  std::cout << "--debug[=<bool>]: Specify whether to show debug-related information. (default = 0)" << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "[ Miscellaneous]" << std::endl;
  std::cout << "/?, -h, --help: Show a list of available commands." << std::endl;
  
  std::cout << std::endl;
  
  return;
}