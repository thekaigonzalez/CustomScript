# CustomScript. A robust, Customizable Parser.
CustomScript is a robust, Smart Compiler which has many customizable features including Beta CIOS Mode to help you begin development on Server-Side apps 😊

## CS8 C++ Engine Bindings
The CS8 & CS9 Engine rewrites are filled with new ways to communicate from Custom, To C/C++.
To learn the ways of the C++ Binding, check [Migrating Your scripts](MIGRATING.md), Not only does it tell you how to migrate from CS6 To CS8, It also Teaches you how to write functionalities as well!

## CS8/9 Developer's guide
CustomScript Is a Parser that runs on a custom built File I\O Engine that was built for the ease of language development and coding.

CS8 Comes with many great features out of the box, But you can add more by using the feature rich Engine Binding to help you.

In the CS Template, We go over all of the things you need to know about development of custom utilities & packages. This Reference Documentation shows you all of the keywords you need.

### Keywords
#### open
```
open stream(<filename>: str, <mode>: new(Mode)) { specifier }
```
Opens <filename> as <mode>.
The available modes are:

- append
- Write
- Parse
- json.parsermethod()
- read
- GetFirstLine
- CheckIf
- Loopuntil

#### parent
```
parent <type> <name>(args: optional)
```
Specifies a Parent function.
Parent Functions take control of all static methods.
Parent Controllers are used by the `main` call. Go down to the `main` Function Section to learn more.
#### send
```
send <func2stdout>(<void *>: str)
```
Send <void *> to stdout.
#### if
```
if (a == a) do {
    <COMMANDS>
}
```
Deprecated **if** Keyword. Use **ifelse** To allow Parser Methods.
#### for
```
for (<char>: character in <&string>: StringToBooleanArray) do {
    <COMMANDS>
}
```
Deprecated **for** Keyword. Use **foreach** to allow Parser methods instead of commands.
#### ifelse
```
ifelse doif(<var | const | let | method | string | character | boolean | function | void* | void | voidmethod> <var>: <value> = <value2> , <handler> => {
    <statements>
}
```
Execute <statements> as parser methods without having to catch `else` Exceptions.
#### foreach
```
foreach(<type> <name> in array <name>[contents]) do this-><event | type | function | coroutine> { <statements> }
```
Uses the StreamArrayLooper To Check if the Type is in the string and is valid.
## Presets
### Main()
```
public parent void* main(String args[]) {
    <parse>
}
```
Main Function. Executes any code inside of the block.
Basically `func` except it runs with the CS8 Parser and does not run on the windows API.
### build(args)
```
func build(args)
```
Basic Build Function.
### process(proto)
```
function process();
```
Process is a function that ws initially built to test function prototyping, Will be removed functionality In CS9 And Completely wiped In CSX.
## Classes & Structured Booleans
### Keyboard
```
classdef Keyboard {
    KEY_IN,
    KEY_OUT,
    function doif();
    function iftouched();
    function onrelease();
    function send();
    function virtual();
}
```
Keyboard Functionality.
### VirtualSender
```
classdef VirtualSender {
    KEY_IN,
    KEY_OUT,
    function send();
    function recieve();
    var sender = ISender,
    function VirtualShader();
    function fix();
}
```
Send Keyboard Input with VirtualSender
### Rewrite\Classdef
```
classdef CLASSDEF {
    ORIGIN,
    UTILS,
    CLASS
}
classdef MOD {
    MODULE,
    UTILS,
    FIN,
    DONE,
    STATUS,
    NULL
}
```
### NullableInitializer
NullableInitializer Is a very flexible class containing fragments from
- string
- str
- NULLPTR
- STDOUT
- cClassdef
- Init
- arraymethod
- argMethod
- ISender
- argsClass
## Sendable Functions
### Println
`println(void *)` accepts any input which derives from the NullableInitializer Class.
It then flushes output to STDOUT.
### FlushAll(void& args)
Flushes <args> to STDOUT without automatic flushing.
### printf(void* format)
Same as Println.
## CS8:Errors
### About
CS8 Contains a simple Error library containing basic errors.
### TypeError
Occurs when a Type is given, But return type doesn't give corrent type.
### Parser.NULLException
Occurs when user tries to pass a NULL value within a Non-NullableInit Function/Variable.
### Parser.NotFoundException
Glitchy Keyword Catcher.
### raise <error> e(<src>)
Raise Certain error as a function to save memory. Function compiled at runtime.
## CS8:SilentWarning
### About
CS8 Gives silent warnings about the script's static values. You can enable these by either:
- Going to the csdb.exe file
- Enabling Verbose Option by typing
`cs8.exe <file> -verbose`
  
These range from: 
### ForLoop.Ended
Occurs Silently when a `for` or `foreach` Loop is closed.
### ForLoop.Started
Occurs Silently when a Deprecated for loop begins
### ifLoop.Unable
Used to visibly occur when a If statement always returned false. Occurs silently now.
### ifLoop.Started
Starts when a If Loop parser method is started.
### Missing.Objects.do
Missing the `do` in If, when, while, for. Does not need to be specified but helps with memory. 