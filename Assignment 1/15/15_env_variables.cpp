/*
===========================================================================================================================
Name : 15.c
Author : Aman Tiwari
Description :Write a program to display the environmental variable of the user (use environ).
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

extern char **environ;   // declare the environment variable

int main() {
    char **env = environ;   // pointer to environment variables

    while (*env) {
        printf("%s\n", *env);  // print each environment variable
        env++;
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 15 % gcc 15_env_variables.cpp 
(base) amantiwari@Amans-MacBook-Air 15 % ./a.out                 
MallocNanoZone=0
USER=amantiwari
COMMAND_MODE=unix2003
__CFBundleIdentifier=com.microsoft.VSCode
PATH=/opt/homebrew/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/anaconda3/bin:/opt/anaconda3/condabin
LOGNAME=amantiwari
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.8yGJiXnhDE/Listeners
HOME=/Users/amantiwari
SHELL=/bin/zsh
TMPDIR=/var/folders/7j/y4th2xn11sb7x1kz_3wmxhpw0000gn/T/
__CF_USER_TEXT_ENCODING=0x1F5:0x0:0x0
XPC_SERVICE_NAME=0
XPC_FLAGS=0x0
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
SHLVL=1
PWD=/Applications/Academic work/software system/Assignment 1/15
OLDPWD=/Applications/Academic work/software system/Assignment 1
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:/opt/homebrew/share/info:
CONDA_EXE=/opt/anaconda3/bin/conda
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
CONDA_SHLVL=1
CONDA_PREFIX=/opt/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
TERM_PROGRAM=vscode
TERM_PROGRAM_VERSION=1.103.2
LANG=en_US.UTF-8
COLORTERM=truecolor
VSCODE_INJECTION=1
ZDOTDIR=/Users/amantiwari
USER_ZDOTDIR=/Users/amantiwari
TERM=xterm-256color
VSCODE_PROFILE_INITIALIZED=1
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
GSETTINGS_SCHEMA_DIR=/opt/anaconda3/share/glib-2.0/schemas
_=/Applications/Academic work/software system/Assignment 1/15/./a.out
===========================================================================================================================
*/
