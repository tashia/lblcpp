# lblcpp

### compile command
```
clang++ -std=c++17 -Wall -pedantic file.cc
-v for invocation
```
To use `libc++`
First install libc++ and its corresponding abi
```
sudo apt-get install libc++-12-dev
sudo apt-get install libc++abi-12-dev
export LD_LIBRARY_PATH=/usr/lib:/usr/lib/clang/12.0.0/lib  
dpkg-query -l 'libc+*'     
```
Export the library path, e.g.
```
 export LD_LIBRARY_PATH=/usr/lib/clang/12.0.0/lib:$LD_LIBRARY_PATH
```
Use command
```
clang++ -std=c++17 -stdlib=libc++ -Wall -pedantic file.cc
```