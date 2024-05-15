#!/bin/sh
DoExitAsm ()
{ echo "An error occurred while assembling $1"; exit 1; }
DoExitLink ()
{ echo "An error occurred while linking $1"; exit 1; }
echo Linking /home/dmitry/Документы/GTK_C/KotesPascalProj
OFS=$IFS
IFS="
"
/usr/bin/ld -b elf64-x86-64 -m elf_x86_64       -L. -o '/home/dmitry/Документы/GTK_C/KotesPascalProj' -T '/home/dmitry/Документы/GTK_C/link25892.res' -e _start
if [ $? != 0 ]; then DoExitLink /home/dmitry/Документы/GTK_C/KotesPascalProj; fi
IFS=$OFS
