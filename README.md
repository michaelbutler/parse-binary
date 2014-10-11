parse-binary
============

Extract ASCII text characters out of a binary file and echo result to the terminal screen. It will also replace windows-style \r characters with \n in the process. Non-printable and non-null (ASCII = 0) characters will be represented by a "." period symbol. 


Compile
============
To clone the repository and compile the source:

* `git clone https://github.com/michaelbutler/parse-binary.git`
* `cd parse-binary`
* `make`

Program appears in:
* `./dist/Debug/(GNU-Linux-x86|your-system)/parsebinary`

This produces a parsebinary executable that you can copy where you need (e.g. to a directory in your `$PATH`)

Usage
============
```
parsebinary /path/to/inputfile.bin
```
Output all ASCII characters in `/path/to/inputfile.bin`

```
parsebinary /path/to/inputfile.bin > newfile.txt
```
Output all ASCII characters in `/path/to/inputfile.bin` to a file called `newfile.txt`

To Do List
============
* Keep UTF-8 or UTF-16 encoded characters intact instead of destroying them.
* Convert and output result as UTF-8 instead of plain ASCII.
* Add configuration flags (which algorithm to use)

License
============
Licensed under the GPLv3.
