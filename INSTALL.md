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

Just use MSYS2 and compile GTK-4.8.3 yourself and use it to compile the application. (Probably need to compile `gtksourceview5` too).

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
