//
// Created by seymo on 2/21/2021.
//

#include <iostream>
#include <algorithm>

#include <utility>
#include <functional>
#include <conio.h>

#include <fstream>
#include <iomanip>
#include <GL/gl.h>
char fori;
#include <ios>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>

std::string delim;
std::string placeholder;

void start_app(std::string &file) {

}
void removeSpaces(std::string& str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' || str[i] != '\n')
            str[count++] = str[i]; // here count is
    }
    // incremented
    str[count] = '\0';
}
void evaluate_string_big(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), '"'), str.end());
}
void evaluate_string_char(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), '\''), str.end());
}
void removeNewlines(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}
std::string removeNewlinesx(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
std::string open_brack;
std::string close_brack;
std::string command;
std::string param1;
std::string sender;
std::string args;
std::string stream;
std::string initializer;
std::string funcname;
std::string isasync;
std::string statement;
std::string varname;
std::string varval;
std::string arg1;
std::string arg2;
char assignmentop = '=';
int line = 0;
int main(int argc, char *argv[]) {
    std::ifstream infisle(argv[1]);
    while (infisle >> initializer) {
        line++;
        if (initializer == "function") {
            getline(infisle, funcname, '(');
            getline(infisle, isasync, ')');

            std::remove_if(funcname.begin(), funcname.end(), isspace);

            if (funcname == "processs") {
                std::cout << "Process function exited with PROCESS CODE 4" << std::endl;
            } else {
                std::cout << "Started New Function Prototype: " << funcname << std::endl;
            }

        } else if (initializer == "var") {
            getline(infisle, varname, assignmentop);
            getline(infisle, varval, '\n');
            std::cout << "VARIABLE: " << varname << "\nVALUE: " << varval << std::endl;
        }
        else if (initializer == "customvar") {
            getline(infisle, varname, assignmentop);
            getline(infisle, varval, '\n');
            std::cout << "SPEC_VARIABLE: " << varname << "\nVALUE: " << varval << std::endl;
        }
        else if (initializer == "bash") {
            infisle >> arg1;
            if (arg1 == "send") {
                getline(infisle, funcname, '(');
                getline(infisle, sender, ',');
                getline(infisle, args, ')');
                infisle >> param1;
                if (param1 == "fire" || param1 == "run") {

                    getline(infisle, open_brack, '{');
                    getline(infisle, command, '}');
                    std::cout
                            << "Found 1 Event on Server CLIENT.csr. Executing Command from asynchronous Data Sender: " +
                               sender << std::endl;
                    system(command.c_str());
                } else if (param1 == "pack") {
                    getline(infisle, open_brack, '{');
                    getline(infisle, command, '}');
                    std::cout
                            << "Mailing: " +
                               sender << std::endl;
                    std::ofstream batch(funcname + ".bat");
                    batch << command;
                    batch.close();
                }

            }


        }
        else if (initializer == "if") {
            getline(infisle, funcname, '(');
            getline(infisle, varname, '=');
            getline(infisle, placeholder, '=');
            getline(infisle, varval, ')');
            getline(infisle, open_brack, '{');
            getline(infisle, statement, '}');
            removeSpaces(varname);

            removeSpaces(varval);
            varname.erase(varname.end());
            std::cout << "Tried Comparing" + varname + "To " << varval << " Got:" << std::endl;

            std::cout << "WAIT! Parsing Expression. . ." << std::endl;
            if (varname == varval)
                system(statement.c_str());
            if (varname == "iostream") {
                if (stream == varval) {
                    system(statement.c_str());
                }
            }
            else {
                std::cout << "WARNING: If statement always returns false." << std::endl;
            }
        }
        else if (initializer == "await") {
            getline(infisle, funcname, '(');
            getline(infisle, statement, ')');
            removeSpaces(funcname);
            if (funcname == "print") {

                std::cout << statement << std::endl;
            }
        } else if (initializer == "func") {
            getline(infisle, funcname, '(');
            getline(infisle, arg1, ')');
            infisle >> arg2;
            if (arg2 == "do") {
                getline(infisle, open_brack, '{');
                getline(infisle, statement, '}');
                std::cout << "Running Function " + funcname << std::endl;
                system(statement.c_str());
            }
        }
            // for (i in "My String") this {
            //        <command>
            // }
        else if (initializer == "for") {
            getline(infisle, funcname, '(');
            infisle >> fori;
            infisle >> delim;
            getline(infisle, varval, ')');
            infisle >> param1;
            if (param1 == "do") {
                getline(infisle, open_brack, '{');
                getline(infisle, statement, '}');
                for (char i : varval) {
                    if (i == fori) {
                        system(statement.c_str());
                    }
                }
            } else {
                std::cout << "FAILED TO GET FOR_LOOP_DO ON LINE " << std::to_string(line) << std::endl;
            }
        } else if (initializer == "package") {
            infisle >> arg1;
        } else if (initializer == "input") {
            getline(infisle, funcname, '(');
            getline(infisle, args, ')');
            std::cout << "Got " + funcname + ", Parsing Expressions for Args: " << args << std::endl;
            removeSpaces(funcname);

            std::cout << args;

            getline(std::cin, stream);
        }
        else if (initializer == "open") {
            std::string path;
            getline(infisle, funcname, '(');
            getline(infisle, path, ',');
            getline(infisle, param1, ')');
            getline(infisle, open_brack, '{');
            getline(infisle, statement, '}');
            removeSpaces(funcname);
            removeSpaces(path);
            removeSpaces(param1);
            removeNewlines(param1);
            removeNewlines(statement);
            removeSpaces(statement);
            evaluate_string_big(path);
            evaluate_string_char(path);
            std::cout << "File Identifier: " + funcname << "\nPath: " + path << "\nMode: " + param1 << "\nAction: " + statement << std::endl;

            if (param1 == "r+" || param1 == "read" || param1 == "r") {
                std::ifstream userfile(path);
                std::string val;
                while (userfile >> val) {
                    if (statement == "&print:self" || statement == "get_contents") {
                        std::cout << val << std::endl;
                    }
                }
            }
            else if (param1 == "w" || param1 == "write") {
                std::ofstream ifile(path);
                ifile << statement;
                ifile.close();
            } else if (param1 == "a+" || param1 == "append" || param1 == "a") {
                std::ofstream ifile(path);
                ifile << statement;
                ifile.close();
            }
        }
        else if (initializer == "classdef") {
            std::string classname;
            std::string contents;
            getline(infisle, classname, '{');
            getline(infisle, contents, '}');
            std::ofstream classes(classname + ".cClass");
            classes << "c l a s s\nc l a s s n a m e=" + classname << "\nc o n t e n t = {" + contents + "\n}";
            classes.close();
        }
        else if (initializer == "module") {
            getline(infisle, varname, assignmentop);
            getline(infisle, funcname, '(');
            
            getline(infisle,arg1, ')');
            removeNewlines(funcname);
            evaluate_string_big(arg1);
            evaluate_string_char(arg1);
            removeNewlines(arg1);
            if (funcname == "require") {
                std::cout << "Getting Module " + arg1 << "." << std::endl;
                std::ifstream requested("packages\\" + arg1);
                std::ofstream cycle("modules.txt", std::ios::app);
                if (arg1.empty())
                    std::cout << "Line 1201 Of require.csr: 'require' missing one required argument: Module: File" << std::endl;
                if (!requested) {
                    std::cout << "Program failed to parse after throwing exception of parser.requirement.NULLException: line@" << line << std::endl;
                    std::cout << "= require('" << arg1 << "')\n           ^^^^^^^^^^^^^" << std::endl;
                }
                std::string contents;
                while (requested >> contents) {
                    if (contents == "classdef") {
                        std::string name;
                        requested >> name;
                        cycle << "class=" + name + "\n";
                    }
                    else if (contents == "function") {
                        std::string name;
                        requested >> name;
                        cycle << "proto=" + name + "\n";
                    }
                    else if (contents == "func") {
                        std::string name;
                        requested >> name;
                        cycle << "function=" + name + "\n";
                    }

                }
                
            }
        }
        else if (initializer == "send") {
            getline(infisle, funcname, '(');

            getline(infisle,arg1, ')');
            removeNewlines(funcname);
            evaluate_string_char(arg1);
            evaluate_string_big(arg1);

            if (funcname == "println") {
                std::cout << arg1 << std::endl;
            }
        }
        else if (initializer == "system") {
            getline(infisle, funcname, '(');

            getline(infisle,arg1, ')');
            removeNewlines(funcname);
            if (funcname == "outln") {
                std::cout << arg1 << std::endl;
            }
            else if (funcname == "exec") {
                system(arg1.c_str());
            }
            else if (funcname == "sleep") {
                int time = std::stoi(arg1);
                Sleep(time * 1000);
            }
        }
        else if (initializer == "*") {
            getline(infisle, param1, '*');
            // Post to Buffer
        }
        else if (initializer == "Keyboard") {
            getline(infisle, funcname, '(');
            getline(infisle, param1, ')');
            getline(infisle, open_brack, '{');
            getline(infisle, statement, '}');
            evaluate_string_char(param1);
            char c = _getch();
            if (c == param1[0]) {
                std::cout << statement << std::endl;
            }
        }
        else if (initializer == "type") {
            getline(infisle, funcname, '(');
            getline(infisle, param1, ')');
            getline(infisle, open_brack, '{');
            getline(infisle, statement, '}');
            evaluate_string_char(param1);
            removeNewlines(funcname);

            if (funcname == "status") {
                std::cout << "1" << std::endl;
            }

        }
        else if (initializer == "array") {
            getline(infisle, funcname, '[');
            getline(infisle, param1, ']');
            evaluate_string_char(param1);
            evaluate_string_big(param1);
            removeNewlines(funcname);
            if (param1.empty())
                std::cout << "WARNING: CS8 Is not Objective, Arrays Take in at least 1 parameter: <content>" << std::endl;
            std::cout << "New Array:\nName: " << funcname << "\nArray Contents: " << param1 << std::endl;
        }
        else if (initializer == "raise") {
            infisle >> arg1;
            getline(infisle, funcname, '(');
            getline(infisle, param1, ')');
            evaluate_string_char(param1);
            evaluate_string_big(param1);
            removeNewlines(funcname);
            if (arg1 == "TypeError") {
                std::cout << "Errors.TypeError: " << param1 << std::endl;
            }
            else if (arg1 == "SecurityError") {
                std::cout << "Errors.SecurityError" << std::endl;
            }
            else if (arg1 == "OverFlowError") {
                std::cout << "CS8.OverflowError: " << param1 << std::endl;
            }
        }
        else if (initializer == "ifelse") {
            getline(infisle, funcname, '{');
            getline(infisle, param1, '}');
            system(param1.c_str());
        }
        else if (initializer == "namespace") {
            infisle >> arg1;
            // namespace init::init
        }
        else if (initializer == "#") {
            getline(infisle, param1);
            // Publish to buffer stream
        }
        else if (initializer == "using") {
            infisle >> arg1;
            std::cout << "Successfully created plant ID: " << arg1 << std::endl;
        }
        else if (initializer == "mkdir") {
            getline(infisle, funcname, '(');
            getline(infisle, param1, ')');
            evaluate_string_big(param1);
            evaluate_string_char(param1);
            CreateDirectory(param1.c_str(), nullptr);
        }
        else if (initializer == "return") { // return <type> index(/Path/To/Index)
            std::string type;
            infisle >> type;
            if (type == "public") {
                getline(infisle, funcname, '(');
                getline(infisle, param1, ')');
                return std::stoi(param1);
            }
        }
        else if (initializer == "public") {
            std::string type;
            infisle >> type;
            if (type == "parent") {
                std::string typespec;
                infisle >> typespec;
                if (typespec == "void" || typespec == "void*") {
                    getline(infisle, funcname, '(');
                    getline(infisle, param1, ')');
                    
                    getline(infisle, open_brack, '{');

                    removeNewlines(funcname);
                    if (funcname == "main") {
                        std::string spec;
                        infisle >> spec;
                        if (spec == "send") {
                            getline(infisle, funcname, '(');
                            getline(infisle, param1, ')');
                            evaluate_string_char(param1);
                            evaluate_string_big(param1);
                            removeNewlines(funcname);
                            if (funcname == "println" || funcname == "printf") {
                                std::cout << param1 << std::endl;
                            }
                            if (param1 == "args:fulltype/num" && funcname == "println") {
                                std::cout << argc << std::endl;
                            }
                            if (param1 == "args:fulltype/str" && funcname == "println") {
                                std::cout << argv << std::endl;
                            }
                            if (removeNewlinesx(param1) == "null" && funcname == "println") {
                                std::cout << "<<Use Of Built-In Object at stack call :class:(main). Run csdb.exe For more information.>>" << std::endl;
                            }
                        }
                        std::string eos;
                        getline(infisle, eos, '}');
                    }
                    
                }
            }
        }



    }

}