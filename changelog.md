# CustomScript Changelog
### Version 6.0

#### What's new?
- Added doif()
- Made CustomScript make a modules.txt For Better module handling.
- Cached variables so you can use them later.
- Added Block Comments "`*`"
- Fixed Input
- Class Definitions
- Keyboard Input "`require('keyboard.custom')`'"
- Added Strings
- Added Diagnostic gathering using `type <func>(params)`
- More Functions
- Finally... A Filesystem!
- Working Imports
- Raw exec `<command>(<name>, <sender>) { <cmd> }`
#### Fixed
- Input Streams not working
- Statements & parameters on one line

#### Changed?
- Utilities On most CustomScript Parsers. (https://www.github.com/Kai-Builder/customscript-template/)
### Version 5.0.0
#### What's new?
- Added If statements
- Added better bash commands
- Added Template of module importing
- More Functions
- No More Prototyping! Use `func` To execute Bash Commands On-the-fly! Use `eval func()` To Run a Evaluated Function (BETA)

#### Fixed
- Nothing
#### Changed?
- Utilities

### Version 2.0.1
#### What's new?
- Fixed Parser
#### Fixed
- Nothing
#### Changed 
- Nothing

### Version 1.0.0
#### What's new?
- Nothing
#### Changed?
- Nothing
#### Fixed
- Nothing

# Examples
Get File's Contents
```custom
open file('file.txt', read) { 
        get_contents 
} 
```
Write to a file
```
open file('assets/asset.asset', write) {
    <content>
}

```
Write to a file (Old method)

```
bash send command(FileSender, args) fire {
    echo hello > test.txt
}
```
Append to a file

```
open file('test.txt', a) {
    <content>
}
```
# Classes

## File
All open() Methods Inherit File.
File defines the filesystem in which files are written, cached, appened, and read from.

## IOBuff
This method Is inherited by **iostream** **println** **printf** And **print**.
It defines the main class In which all console buffers are printed, Deleted, Executed, And Cached.
