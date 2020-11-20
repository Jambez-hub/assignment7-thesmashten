// File name: geotopt.h
// Author: Nishant Jain
// VUnetID: jainn6
// Email: nishant.jain@vanderbilt.edu
// Class: CS3251
// Assignment Number: 7
// Description: This class defines a getopt data structure.
// Last Changed: 11/20/20
#ifndef GETOPT_H
#define GETOPT_H

// Put this into its own namespace to disambiguate from globals.
namespace parsing {
extern char* optarg; /* Global argument pointer. */
extern int optind; /* Global argv index. */

// Function to parse a command line argument.
int getopt(int argc, char* argv[], char* optstring);

std::string getfilename(std::string arg);

std::string getpath(std::string arg);
}

#endif // GETOPT_H
