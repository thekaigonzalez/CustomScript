# Migrating your scripts from CS6 To CS8
This Update brings many awaited features into CustomScript.
Some of these changes change the way scripts are written.
## Open Directory
Making Directories using CMDSystems have been updated.

old:
````
*
2021
*

bash send command(Isender, args) fire { mkdir <dir> }
````
new:
````
*
2021
*

mkdir dir('<name>')
````

## Packages
Packages are deprecated. Using namespaces is a better alternative.

old:
```
package test.module
```
new:
```
namespace MySpace

namespace MySpace/ExtraDirs
```
## IF ELSE
The if Statement tree is deprecated. Use ifelse To tell if a object has a dynamic l-value
```
*
2021
*

ifelse { a is <value> } doif {
    <bash>
}
```
## Arrays
Arrays Used to be captured in variables, This is a very verbose way to do arrays. The new array method allows specific array creation.

old:
```
var x = ['a', 'b']
```
new:
```
array x[<content>]
```

## Warnings & Error Classes
The Old way of doing errors was a very insecure way to do error handling.
The New ways to do error throwing & handling is very simpler.

old:
```
if (a == b) {
echo That doesn't make sense?
}
```
new:
```
ifelse(a != &b.randomized) doif { 
       raise TypeError e("That doesn't make sense!") 
} 
```

----------------
Thats all that CS8 Changes. Enjoy!