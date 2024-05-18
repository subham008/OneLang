**OneLang** is a **programming language** that aims to be the one language to conquer all  application , no need to learn diffrent languages , **one language for every thing** 


**NOTE : THIS LANGUAGE IS NOT READY , IT,S UNDER DEVELOPEMENT**
# how we planned to achieve

   * indentation based language(Python like syntax)

   * memory safe (compiler time memory management system)

   * can be interpret , compiled

   * large set of  available compiled target as we use LLVM (e.g x86,x86_64,arm , aarch,thump,risc,wasm and many more that you may never heard of) .  for more details follow this link https://llvm.org/docs/CompilerWriterInfo.html

   * own build tool and package library inpired by rust cargo(https://doc.rust-lang.org/cargo/commands/cargo-build.html) and crates(https://crates.io/)


   * modern features

   * some rules and regulation to make code readable as freeadom of doing anything will create chaos



# How to start contributing
**we are using c++  to  build  this language, so you should learn c++ basics including classes**

At first create a folder of any name, here we are named it OneLangSource

>mkdir OneLangSource

now move to that folder

>cd OneLangSource

now run a terminal command to download repo using git command line tool

>git clone https://github.com/subham008/OneLang.git

NOTE : if git not installed , then follow this link https://git-scm.com/downloads

it will take time to downlaod all resources

Once its done open that OneLang folder on your favourite IDE

**note: vscode is recommended**



# Folder details

**.vscode** This folder is created by VSCODE itself it contains vscode setting and cpp_configuration

**AST** This folder contains lexer and parser it is responsible to convert raw code or text to AST  here we call it Module it contains all function, variables, instruction in form of std::list<..>

**OneLangSamples** This folder contains sample code written in OneLang, you can check it out to understand more about OneLang

**compiler** This folder contains c++ code for compiling OneLang program to machine codes or bytecodes

**llvm_test** This is just to learn about llvm it is not responsible for anything in this project





