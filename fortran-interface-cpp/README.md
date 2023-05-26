#  Example for passing/changing Fortran defined type to C++

The idea here is to acess and modify Fortran derived types on C++ side, but without the need for get/set functions. Also, here one may acess the object values on the top level fortran code using the usal sintaxe (e.g. `type_object%variable`).

So far I figured out two ways for doing this:

 - Defining the derived type using C binding and then having a struct on C++ side mirroring this object (however, dealinig with strings here seems to be more trickier). Then, send a pointer to this type to C++;
 - Defining the derived as usual in Fortran. Thenm send a pointer to each member of the type to C++;

The first approach seems to be more straightforward, but I need to figure out how to deal with strings there. The second one may be helpful for one who needs to take an already existing Fortran code to modify.

## To do:

 - [ ] Figure out how to deal with strings in the first approach;
 - [ ] Figure out if one can send a pointer to the derived type to C++ in the second approach;
 - [ ] Add pointers in the derived type (the examples on fortran-cpp-fortran folder will be helpful, I hope);
