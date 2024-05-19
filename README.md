**OneLang** is a **programming language** that aims to be the one language to conquer all  application , no need to learn diffrent languages , **one language for every thing** , system developement, web developement, app developement , or any type for software developement it aims to fit in all this sectors


**NOTE : THIS LANGUAGE IS NOT READY , IT,S UNDER DEVELOPEMENT**
# how we planned to achieve

   * indentation based language(Python like syntax)

   * memory safe (compiler time memory management system)

   * can be interpret , compiled

   * large set of  available compiled target as we use [LLVM](https://llvm.org/) (e.g x86,x86_64,arm , aarch,thump,risc,wasm and many more that you may never heard of) .  

   * own build tool and package library inpired by rust [cargo](https://doc.rust-lang.org/cargo/commands/cargo-build.html) and [crates](https://crates.io/)


   * modern features

   * some rules and regulation to make code readable as freeadom of doing anything will create chaos



# How to start contributing
**we are using c++  to  build  this language, so you should learn c++ basics including classes**

At first create a folder of any name, here we are named it OneLangSource
```
mkdir OneLangSource
```
now move to that folder
```
cd OneLangSource
```
now run a terminal command to download repo using git command line tool
```
git clone https://github.com/subham008/OneLang.git
```
NOTE : if git not installed , then follow this link [git](https://git-scm.com/downloads)

it will take time to downlaod all resources

Once its done open that OneLang folder on your favourite IDE

**note: vscode is recommended**

# Skills Required

* c/c++ basics with class,struct,pointer and  reference pointer
* compiling and linking  of code 
* basic understanding of  computer working
* well understanding on any one operating system like windows,linux or mac
* well understanding of LLVM , how it works and how to use it in c++

To learn about LLVM we recommend you a youtube [tutorial](https://youtu.be/Lvc8qx8ukOI?si=qgf4jA4B-CPgzryp) of 20 videos , it worth time


# Tools required

* clang and clang++ (version 17 or above)
* LLVM tools (17.0.6 or above)

if you are using **linux or macOS** its easy for you to install this tools
but if you are using **windows** its very hard to install all these manually

so , we reccomend install [MSYS2](https://www.msys2.org/) on your windows device .

Now MSYS2 have multiple enviroments e.g clang32,clang64,ucrt32,ucrt64,mingw32,mingw64 and etc.

we will use **mingw64** enviroment or Terminal 

**mingw64**  use pacman to install and manage packages , it has huge list of [packages](https://packages.msys2.org/base)

**STEPS TO INSTALL TOOLS**

open **mingw64** terminal just by search on menu

Now install required packages through running below commads on **mingw64**  terminal


**To install clang run this command**
```
pacman -S mingw-w64-x86_64-clang
```
**To install LLVM tool run this command**
```
pacman -S mingw-w64-x86_64-llvm
```

**To install LLD , run this command**
```
pacman -S mingw-w64-x86_64-lld
```




# Folder details

<b style="color:#b5af0b;">.vscode</b> This folder is created by VSCODE itself it contains vscode setting and cpp_configuration

<b style="color:#b5af0b;">AST</b> This folder contains lexer and parser it is responsible to convert raw code or text to AST  here we call it Module it contains all function, variables, instruction in form of std::list<..>

<b style="color:#b5af0b;">OneLangSamples</b> This folder contains sample code written in OneLang, you can check it out to understand more about OneLang

<b style="color:#b5af0b;">compiler</b> This folder contains c++ code for compiling OneLang program to machine codes or bytecodes

<b style="color:#b5af0b;">llvm_test</b> This is just to learn about llvm it is not responsible for anything in this project


# how we Compile

We are using LLVM to compile our program 

source_code -> lexer -> Module(AST) -> LLVM IR -> compiled bytecode

**IF YOU ARE A CONTRIBUTER , YOU SHOULD JOIN OUR Discord server**

# Our Discord server 

[OneLang Discord](https://discord.gg/gMTRWB8f)



