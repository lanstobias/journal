#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <time.h>

#include <boost/filesystem.hpp>
#include <boost/process.hpp>
#include <boost/system/error_code.hpp>

#include "../include/FileHandler.hpp"

using namespace std;
using namespace boost;

// Contructors
FileHandler::FileHandler() {}
FileHandler::FileHandler(string destinationPath) : destinationPath_(destinationPath) {}

// Accessors
string FileHandler::getDestinationPath() {
    return destinationPath_;
}

ofstream& FileHandler::temporaryFile() const {
    return temporaryFile_;
}

// Mutators
void FileHandler::setDestinationPath(string newDestinationPath) {
    destinationPath_ = newDestinationPath;
}

// Public methods
string FileHandler::createTempFile() {
    // TODO: Solve liker problem when doing this:
    //string filename = temporaryFilename();

    std::stringstream ssFilename;
    filesystem::path temporaryFilePath = filesystem::temp_directory_path();
    ssFilename << temporaryFilePath.native() << "test" << ".md";

    return ssFilename.str();
}

void FileHandler::openFileWithEditor(string file) {
    filesystem::path editorPath = "/usr/bin/nano";
    int result = process::system(editorPath, file);
}

// Private methods
string temporaryFilename() {
    std::stringstream filename;
    filesystem::path temporaryFilePath = filesystem::temp_directory_path();
    filename << temporaryFilePath.native() << "test" << ".md";

    return filename.str();
}

string FileHandler::readTempFile() {
    return "";
}

void FileHandler::deleteTempFile() {
    //try {
        //temporaryFile_.close();
    //} catch(ofstream::failure e) {
        //cerr << "Could not close file";
    //}
}


