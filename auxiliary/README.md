# Image Randomizer

This is a image randomizer that takes a pre-existing image file and randomly scrambles the pixel colors to create a new random image.

# Dependencies

This project requires the libpng external library. To install it please type *sudo apt install libpng-dev*. 

# Formatting

To format your project go to the root directory. Then type *make format* to test this type *make verify_format*. 

# Building 

To build your project create a build directory with *mkdir build* then move into the directory with *cd build*
Finally type *cmake ..* to build the project.

# Running

To run your project after building type *./createRandomImage ../download.png 255 255*. Download.png is included for testing but any png can be used!

