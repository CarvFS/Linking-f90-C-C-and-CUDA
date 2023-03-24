program rism1d_main

    use iso_c_binding
    implicit none 

    type, bind(C) :: rism1d
        integer(C_int) :: extra_precision, Mdiis_vec
        character(kind = C_char), dimension(3) :: savefile
    end type rism1d

    interface

        subroutine calling(r1d) bind(C, name="cplusplus_callback_function")
            import :: rism1d

            type(rism1d) :: r1d

        end subroutine calling

    end interface

    type(rism1d) :: r1d

    call calling(r1d)

    write(*,*) "extra_precision = ", r1d%extra_precision, "Mdis_vec = ", r1d%Mdiis_vec, "savefile = ", r1d%savefile

    

end program rism1d_main