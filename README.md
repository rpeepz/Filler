# Filler&emsp;[![Actions Status](https://github.com/rpeepz/Filler/workflows/C/Build/badge.svg)](https://github.com/rpeepz/Filler/actions)[![GitHub release](https://img.shields.io/github/v/release/rpeepz/Filler.svg)](https://github.com/rpeepz/Filler/releases)[![GitHub All Releases](https://img.shields.io/github/downloads/rpeepz/Filler/total.svg)](https://github.com/rpeepz/Filler/releases)[![GitHub license](https://img.shields.io/badge/Licence-MIT-purple.svg)](https://raw.githubusercontent.com/rpeepz/Filler/master/LICENSE)[![Twitter Follow](https://img.shields.io/twitter/follow/papagna94.svg?style=social&label=Follow)](https://twitter.com/papagna94)  
An Ai player that I created to play a game developed by 42 students <br/>
僕は埋めるよ!!  
_I'll fill you!_  


### Table Of Contents
* [Objective](#objective)
* [Installation](#installation)
* [Usage](#usage)
* [Project Structure](#project-structure)
* [Dependencies](#dependencies)
* [Future](#future)
* [Subject PDF](#subject-pdf)
* [Sources](#sources)
* [Keep In Touch](#keep-in-touch)

#### About 42  
[42][42] is a free, non profit, project-based, peer-to-peer learning coding school. It originated in France and now has over 20 campuses all over the world. More information can be found [here][42].

<br>

---

<br>

## Objective  
This project's goal is to create player for the Filler game.  <br>

sample gameplay:  
![test](https://media.giphy.com/media/ch2OIkngQa2aKbZ5j8/giphy.gif "sample") <br>

click here [<img src="https://i.imgur.com/muGcWVW.png" width="16px" height="16px" title="filler video">](https://www.youtube.com/watch?v=UcGA-NssVWs) for a video of the game played by one of the first to attempt this project  

<br>

## Installation
Download and compile repo:  
``` 
git clone https://github.com/rpeepz/Filler.git  
cd Filler  
make  
```  
Executable `rpapagna.filler` will be created  
<br>

## Usage  

`./filler_vm -p1 user1 -p2 user2 -f mapfile` <sup id="l_path">[1](#f_path)</sup>
- Filler_vm is the Ruby exececutable that provides pieces
- user1 and user2 are player executables
- mapfile is any of the maps provided in the maps directory.  

For help run `./filler_vm` with no arguments  

Make sure you have the required [dependencies](#dependencies) before proceeding.  
For instructions and/or greater detail refer to the project [pdf](#subject-pdf)  

<br>

---  

<br>

## Project Structure

### Source files

```
src/
├── main.c
├── phase_one.c
├── play.c
├── set.c
└── sort.c

1 directory, 5 files
```

### Header files

```
includes/
└── filler.h

1 directory, 1 file
```
<br>

--- 

<br>

## Dependencies  
* A C language compiler most common would be GCC or Clang.
* Cmake to run the custom Makefile for fast instalation.
* Code was written to run on Unix based systems, it would likely work on a windows machine too but is currently untested. 

<br>

## Future 
My current release has a small known issue.  
I also plan to implement more phases for a more advanced fill.  
<br>

## Subject PDF
[Filler PDF][pdf]   

---  

## Sources  
[Morgane Dubus](https://github.com/mdubus/filler "informational") - teaching the outline  
[Pierre Bondoerffer](https://github.com/pbondoer/42-filler "inspirational") - teaching the conept  
WolframAlpha.com - help with calculations  
My Notebook - testing concepts  
[Antoine Janssen](https://github.com/Themancrazy "insightful") - correction genuis  
@Phat Truong - rigorous testing  
[Jincheol Park](https://github.com/Seojun-Park) - help at every step  

<br>

---  

## Keep in Touch

You can find me on:
* [Github](https://github.com/rpeepz)  
* [Twitter](https://twitter.com/papagna94) 
* [LinkedIn](https://www.linkedin.com/in/rpapagna-510) 
<!-- * [Medium](https://medium.com/@themichaelbrave)  -->
<!-- * [Home] -->

<br>

---

_This project was attempted for learning purposes only. This repo may not be kept up to date and I cannot guarantee that it will work on your future machines. You are welcome to use and learn from this as you want, but do not implement code that you do not understand. These sources listed above have been invaluable and I advise you to do research on the subject before trying to copy the code you see here._  

<br>


<b id="f_path">1: </b>The vm will fail if a player is in the current directory. Give the path to fix this e.g. `-p1 ./rpapagna.filler` [↩](#l_path)  


[42]: http://42.us.org "42 USA"
[pdf]:  https://github.com/rpeepz/phil/blob/master/filler.en.pdf  "filler"
