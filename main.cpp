/* main.cpp
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

// Constant definitions
#define VERSION string("0.1.3")
#define APPLICATION string("Blocks")
#define COPYRIGHT string("Copyright 2013 Christopher Simpkins")
#define LICENSE string("MIT License")
#define TAGLINE string("- a text file template engine")
#define GITHUB_SRC string("https://github.com/chrissimpkins/blocks")

// Standard library headers
#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

#include "main.h"
#include "io.h"
#include "opts.h"
#include "print.h"

// Standard library namespace
using std::wstring;
using std::string;
using std::vector;
using std::system;

/******************************************
*  G'day, I'm main()
*******************************************/

int main(int argc, char const *argv[]) {
	string teststring = "";
	//user did not enter enough arguments in the command
	if (argc < 2) {
		print("You didn't enter a command");
		show_usage();
		return 1;
	}
	else{
		//create the command line vector
		const vector<string> clv = create_CL_vector(argc, argv);
		//create reference to the CL vector (used to pass the CL vector by reference)
		const vector<string>& clvr = clv;
		// create a string for the main user entered command at vector position 1
		const string cmd = clv.at(1);
		// HELP ---------------------------------------------------------
		if (cmd == "help" || cmd == "-h" | cmd == "--help"){
			show_help();
		}
		// VERSION ------------------------------------------------------
		else if (cmd == "version" || cmd == "-v" | cmd == "--version"){
			show_version();
		}
		// MAKE ---------------------------------------------------------
		else if (cmd == "make") {
			if (argc < 3) {
				print_error("Please include text blocks to compile your file");
				return 1;
			}
			else {
				// TO DO: get the files that are going to be used for the make
			}
		} // end MAKE
	}

} //end main

/******************************************
*  Convert the CL character array to vector
*******************************************/

inline vector<string> create_CL_vector(int argc, char const *argv[]){
	vector<string> vs;
	for (int i = 0; i < argc; ++i){
		vs.push_back(argv[i]);
	}
	return vs;
}

/******************************************
*  Terminal view for help
*******************************************/

inline void show_help() {
	print(" ");
	print(APPLICATION + " " + TAGLINE);
	print("Version: " + VERSION);
	print(COPYRIGHT);
	print(LICENSE);
	print("Source: " + GITHUB_SRC);
	print("------------------------------------------------");
	print(" ");
	// SYNTAX HELP
	print("Usage:");
	print("\tblocks <command> [-shortoption] [--longoption] <last positional arg>");
	// HELP INFO
	print(" ");
	print("Help:");
	print("\tblocks <command> [-h | --help]");
	print(" ");
	print("Get help for any command with the -h or --help options.");
}

/******************************************
*  Terminal view for usage
*******************************************/

inline void show_usage() {
	print("Usage:");
	print("\tblocks <command> [-shortoption] [--longoption] <last positional arg>");
}

/******************************************
*  Terminal view for version
*******************************************/

inline void show_version(){
	print(" ");
	print(APPLICATION + " " + TAGLINE);
	print("Version: " + VERSION);
}
