module test_module_func

    implicit none 

    contains
    function add(a,b)
    implicit none
    double precision :: add
    double precision :: a,b

    add = a + b

    end function add

end module test_module_func