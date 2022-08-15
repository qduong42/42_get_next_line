# get_next_line - @42Wolfsburg

## About

std::getline/getline c++/c function

- Only works with \n as delimiter. 
- Coded 'low level'way with read and write system calls. read from files or stdin. Works with multiple fds simultaneously. Dynamic allocation of concatenated string.
- input stream needs to be read according to user defined BUFFER_SIZE.

## Installation & Usage

### Requirements
The only requirements are:
- GNU make (v3.81)
- GCC (12.0.0) (clang-1200.0.32.28)

Those versions are the ones used during development.

### Building the program

1. Download/Clone this repo

        git clone https://github.com/qduong42/42_get_next_line
2. `cd` into the root directory and compile library `ar -rcs get_next_line [all mandatory files] or [all bonus files]`

### Running the program

Use defined library get_next_line

## Main Project Instructions

### Mandatory

- Only use C
- Must respect the 42 imposed coding style The Norminator
- No memory leaks
- Implement getline function with \n as delimiter:
- Must have a header file get_next_line.h

### Bonuses

- Handle multiple fds at the same time.
    
## Notes

Enjoy!

