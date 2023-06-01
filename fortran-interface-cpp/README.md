#  Example for passing/changing Fortran defined type to C++

Run as: `make`, then `./main`

The idea here is to acess and modify Fortran derived types on C++ side, but without the need for get/set functions. Also, here one may acess the object values on the top level fortran code using the usal sintaxe (e.g. `type_object%variable`).

So far I figured out two ways for doing this:

 - Defining the derived type using C binding and then having a struct on C++ side mirroring this object (however, dealinig with strings here seems to be more trickier). Then, send a pointer to this type to C++;
 - Defining the derived as usual in Fortran. Then, send a pointer to each type's members to C++;

The first approach seems to be more straightforward, but I need to figure out how to deal with strings there (strings may be handled using pointers - it is already implemented in the example presented here). The second one may be helpful for one who needs to take an already existing Fortran code to modify.

## To do:

 - [x] Figure out how to deal with strings in the first approach;
 - [x] Figure out if one can send a pointer to the derived type to C++ in the second approach;
 - [x] Add 1D pointers to the derived type in second approach (the examples on fortran-cpp-fortran folder will be helpful, I hope);
 - [x] Add 2D pointers to the derived type in second approach;
 - [x] Add 1D pointers to the derived tyoe in first approach;
 - [x] Add 2D pointers to the derived type in first approach;
