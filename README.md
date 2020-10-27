# 📝uText 

## Description
Text editor made with Qt GUI

## How to use

### Must Have (dependencies)
- CMake 3.18.2 or above - https://cmake.org/download
- Qt 5.15 or above - https://www.qt.io/download

### Building
##### First step
If you do not have ```CMAKE_PREFIX_PATH``` you can fix it in 2 ways:
- go into ```utag/CMakeLists.txt``` and add ```set(CMAKE_PREFIX_PATH "/your/path/to/qt")```
- or you can just write in terminal ```export CMAKE_PREFIX_PATH=/your/path/to/qt```

##### Second step
    ./build.sh

### Run
    utext 

## App features
- open directories and single files
- list opened directory files and subdirectories in the Tree area. 
- open files from the Tree area for reading/editing 
- save files after editing
- copy/cut/paste options in the Toolbar
- find/replace/undo/redo options in the Toolbar 
- keyboard shortcuts
- ability to copy/cut/paste/find/replace for the selected piece of text
- syntax highlighting for source code, markup languages, config files and other text that appears in an organized or predictable format
- basic text formatting (font style, font size, color, background color etc.)
- autocompletion and auto-indentation
- dark & light themes
- error handling with the GUI


    ![image](https://user-images.githubusercontent.com/46691148/97325361-908aed80-187b-11eb-955f-8ab4a425e7dd.png)

## License
Collision is an open-sourced software licensed under the
[MIT license](LICENSE).
