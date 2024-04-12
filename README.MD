
## Presiquite
C++ 11
Cmake installed
### Windows
#### First way
Access https://cmake.org/download/ 

Download prefer installer. For example: **cmake-3.29.2-windows-x86_64.msi** for windows x64. Run installer to install.
Check cmake install with command line in windows 
```bash
cmake
```
![alt text](image-1.png)
#### Second way
```bash
#if using Windows Package Manager
winget install kitware.cmake
#if using Chocolatey
choco install cmake
```
### Linux
```bash
#update package 
sudo apt update && sudo apt upgrade
#install cmake
sudo apt install cmake
#check cmake install
cmake --version
```
## How To Build
Clone this repository. Run following command 
```bash
cmake -S . -B .
#build
cmake --build . -j 12
#running test
cmake -V
```
File __main__ will generate
Running ./main input.txt

