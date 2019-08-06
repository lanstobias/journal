#pragma once
#include <string>

#include <boost/filesystem/path.hpp>

#include "Date.hpp"

class FileHandler
{
private:
    std::string destinationPath_;
    std::ofstream temporaryFile_;

public:
    /**
     * @brief Construct a new File Handler object.
     * 
     */
    FileHandler();

    /**
     * @brief Construct a new File Handler object.
     * 
     * @param destinationPath The path to the destination.
     */
    FileHandler(std::string destinationPath_);

    /**
     * @brief Get the Destination Path object.
     * 
     * @return The path as a string object.
     */
    std::string getDestinationPath();

    /**
     * @brief 
     * 
     */
    std::ofstream* getPointerToTemporaryFile();

    /**
     * @brief Set the Destination Path object
     * 
     * @param newDestinationPath The new destination path.
     */
    void setDestinationPath(std::string newDestinationPath);

    /**
     * @brief Open nano text editor.
     * 
     * @return Void.
     */
    std::string createTempFile();

    /**
     * @brief 
     * 
     * @param filename 
     */
    void openFileWithEditor(std::string file);

private:
    /**
     * @brief Create a temporary filename for file createion.
     * 
     * @return std::string 
     */
    std::string temporaryFilename();

    /**
     * @brief Read the temporary file.
     * 
     * @return std::string 
     */
    std::string readTempFile();

    /**
     * @brief Delete the temporary file.
     * 
     * @return Void.
     */
    void deleteTempFile();
};
