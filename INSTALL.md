# Install instructions for WRText

Compilation and installation instructions are available for:

  - [Linux (Debian 12)](#instructions-for-linux-debian-12)
  - [Windows](#instructions-for-windows)
  -  [MacOS](#instructions-for-macos)

## Instructions for Linux (Debian 12)
The following are the instructions to compile WRText on Linux, specifically Debian 12. Compiling on other versions or distros could generate problems with packages versions.
The application targets `GTK-4.8.3`.
### Requisites
To install all the packages needed to compile WRText you can run the following command in your terminal

`sudo apt update & sudo apt-get install libgtk-4-dev build-essential clang-format doxygen libgtksourceview-5-dev -y`

### Compiling
Clone the GitHub repository by typing:
`git clone https://github.com/gabsimoni/wrtext.git`
Enter the directory by running:
`cd wrtext`
Compile the source code by typing: 
`make`
This will generate an executable in the root directory.
### Executing
To run the application:
`./WRText-x` (replace `x` with the version of the application, like `v1.0`)

## Instructions for Windows
The following are the instructions to compile WRText on Windows using MSYS2 with MinGW64.
Compiling with other environments (Visual Studio, Cygwin, plain CMD/PowerShell) is not supported and will cause dependency issues.

The application targets GTK 4.8.x
### Requisites
Install MSYS2

Launch MINGW64 and run the following command to update the system
`pacman -Syu`

Install the required packages
`pacman -S \
  mingw-w64-x86_64-gcc \
  mingw-w64-x86_64-make \
  mingw-w64-x86_64-pkg-config \
  mingw-w64-x86_64-gtk4 \
  mingw-w64-x86_64-gtksourceview5`

### Compiling
Go to the WRText GitHub repository (https://github.com/gabsimoni/wrtext) and download the repository to a directory of your choice

Navigate to the extracted directory:
`cd wrtext`

Compile the source code:
`make`
or
`mingw32-make`
This will generate a windows executable in the project root.

### Executing
To run the application:
`./WRText-x` (replace `x` with the version of the application, like `v1.0`)

### Notes
When executing outside of a MSYS2 terminal, many *.dll files must be bundled to the same directory as the executable.
A package of the latest release is provided with all the *.dll files bundled and can be downloaded and used as it.

## Instructions for MacOS

### Requisites
First you need to install a package manager like homebrew:
``` /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```

Then clone the GitHub repository:
```git clone https://github.com/gabsimoni/wrtext.git```

And install the dependencies:
```brew install gcc gtk4 gtksourceview5 doxygen clang-format```

### Compilation
Go in the folder containing the repository:
```cd wrtext```

To compile the code you can use ```make``` or ```make debug``` for the debug mode.
### Executing
To launch the application:
```./WRText-x```  (replace `x` with the version of the application, like `v1.0`)
