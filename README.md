# CMPS109_Project
Goals 
This is a programming project that is designed to let you utilize all the concepts 
and  apply  all  the  libraries,  tools,  and  advanced  programming  techniques
explained in class  to build a middleware  for  the Machine  Instruction Simulator
(MIS), which  is  in  the  form  of  a  virtual  machine  capable  of  executing  an 
instruction set. The project is composed of two phases, where the second phase 
builds on top of the first one. It is required also to conduct a UML Object Oriented 
Design and maintain it through constructive updates and evolution through out 
the development and the buildup of the middleware.


Problem
MIS is a virtual machine that is designed to execute a set of instructions.  An MIS 
program is represented by a set of variable declarations and a set of instructions
that operates on the set of defined variables. A program is introduced to the MIS 
in a text file with the extension “.mis” and the results are stored in 2 files; “.out” 
which should include the output of a the target MIS running program, and “.err” 
which  should  include all  the  parse  and  runtime  errors  generated  by  the  MIS 
virtual machine during execution. 
An  MIS  program  is  built  up  of  two  sections.  The  first  section  defines  all  the 
variables  to be used  throughout  the program execution, and  the second section 
has all the instructions to be executed which builds up the program’s sequential 
logic. For simplicity, all variables in an MIS program are global variables where
local  variables  or  subroutines are  not  supported  by  the  MIS  virtual  machine.
Every  variable  definition  and  program  instruction  needs to  be  written  on  a 
separate line, and should not exceed 1024 characters.
The  MIS specification supports 4 data  types  from which  variables  can  be 
declared and defined. The following table presents all the MIS variable types:


Phase 1
In this phase  you  are  required  to  conduct  an  object  oriented  UML  design  that 
includes  at  least  use  case  scenarios,  detailed  class  diagrams,  and  detailed 
sequence diagrams. You are also required to submit a full implementation of the MIS 
virtual machine that runs sequentially. You should apply all the elements of the object
mode studied and explained in class, and try to utilize all the C++11/14 features 
possible, such as STL containers.  You are also expected  to utilize concepts like 
inheritance, templates, virtual methods, and polymorphism in general.

Phase 2
In this phase you are required to build a client/server model for your MIS virtual 
machine.  You  will  be  splitting  your  virtual  machines  into  a  client  and  
server programs. 

The client will be responsible for reading the program from a file and 
sending it  to  the  server  over  network  sockets where it  should execute and the 
server  should return  the  results  to  the  client  where  it  should  be  stored  in
the corresponding  output  files  based  on  the  type  of  output  returned;  error  or
standard output.

Then, you should then be able to convert your MIS virtual machine server to be 
capable  of  handling more  than  one  client  concurrently  at  a  time, which  entails 
that  different  MIS  programs  can  be  executed  in  parallel by  the  same  server 
virtual machine, and each one should have its own separate isolated context.
Finally,  you  are  requested  to  implement  multi-threading  programmatic 
constructs  within  your  MIS  virtual  machine.  You  should  achieve  that  by 
introducing

//
THREAD_BEGIN
THREAD_END
LOCK
BARRIER
UNLOCK

Instruction Parameters Description

THREAD_BEGIN No Parameters Designate the beginning of a 
detached thread


THREAD_END No Parameters Designate the end of a detached 
thread


LOCK Variable Name Lock a variable, where the first 
instruction to lock a variable will 
pass through while subsequent 
instructions will block until the 
preceding instruction is released 
by UNLOCK.
LOCK can be only invoked from 
within a thread.


UNLOCK Variable Name Release an acquired lock on a 
variable. UNLOCK should be
ignored in case it is invoked by a 
thread that did not acquire the 
lock in the first place.
UNLOCK can be only invoked 
from within a thread.

BARRIER No Parameters The BARRIER instruction can be 
invoked only from within the 
main programs, and it will block 
the main program until all the 
detached running threads are 
finished. 
If initially there is no detached 
threads the main program should 
resume and ignore the BARRIER 
instruction.

///

In this phase you are required to utilize the POSIX Sockets library, and you have 
the choice to choose between TCP and UDP, but you will need to present design 
justification  for  your  choice. You  have  the  choice  between  using  the  pthreads
library or the built in C++11 muti-threading library that is part of the C++ STD.
Moreover, you will need to present your updated version of you UML design with 
modification  to  the  original  version  you  submitted in  phase  1, if  there  are  
any updates.