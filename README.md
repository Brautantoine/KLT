[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Brautantoine/KLT.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Brautantoine/KLT/context:cpp)
# What is Kana Learning Tool (Work In Progress) ? ##
>**This software is under development, core program isn't finish yet. You can try it if you want but some features will come later**

KLT (Kana Learning Tool) is a terminal programm that will help you learn and practice your kana. Currently KLT has only small features such as :
* Display kana/romaji table
* Practice with random kana

But soon it will offer you the possibility to store and adapt your progression with different users profile. It will also offer the possibility to practice with some words.
>**IMPORTANT :** Katakana is now supported on random training mode

## Distribution ##

Because of some non-portable functions used, KLT will only be available for Linux during is developpment time. But once the core programm will be finish, a cross-platform version will come (and maybe with GUI)

It have been test on :
* Ubuntu 16.06 and 18.04
* Mageia 6
* Debian 9
* RaspberryPi 3 (with cross-compiling)

## How to compile it ? ##
>The project's architecture is changing, a good Autotools package will come soon

If you have g++ installed you can try the makefile with :
```sh
make # invoke g++
```

But you'll probably need to compile it yourself. A right `Autotools`packaging will come later.

> **IMPORTANT** : KLT depends of libncursesw.so (available with libncursesw5-dev package) - Dependencies section will come

## How to install it ? ##

Currently KLT only produce a `"klt.out"` (or whatever you had name your executable). If you want you can run
```sh
sudo make install # will install klt in /usr/bin
```

You can also just `mv` the executable wherever you want.

## How to use it ? ##

In order to run KLT just use :
```sh
klt
```

There is also some features such as :
```sh
klt [-h,--help] # Display brief help
klt  [-v,--version] # Display version
```


## Incoming Update before 1.0 release ##

- [x] Full support for random kana training and configure options for it [100%]
- [ ] Training with words [0%]
- [ ] Good makefile and Autotools packaging [25%]

## Contact ##

If you have any questions feel free to mail me : <antoine.braut@gmail.com>

**I hope this software will help you ! Have a nice day !**

<img src="https://images.ecosia.org/x8hEzRW0N0B1oHUTXqREorZ73aE=/0x390/smart/https%3A%2F%2Fcdn170.picsart.com%2Fupscale-241091004033212.png%3Fr1024x1024" alt="drawing" width="200"/>
