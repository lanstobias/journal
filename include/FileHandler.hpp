#pragma once
#include <string>

#include "Date.hpp"

class FileHandler
{
private:
    std::string destinationPath;

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
    FileHandler(std::string destinationPath);

    /**
     * @brief Get the Destination Path object.
     * 
     * @return The path as a string object.
     */
    std::string getDestinationPath();

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
    void openNano();

private:
    /**
     * @brief Generate a temporary filename.
     * 
     * @return std::string The generated filename.
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
