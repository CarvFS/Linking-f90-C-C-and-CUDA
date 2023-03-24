module rism1d_mod
  use iso_c_binding
  implicit none 

  type, bind(C) :: rism1d
     integer(C_int) :: extra_precision, Mdiis_vec, mdiis_method
     character(kind = C_char), dimension(16) :: savefile
     character(kind = C_char), dimension(8) :: closureID
  end type rism1d

  interface

     subroutine calling(r1d) bind(C, name="cplusplus_callback_function")
       import :: rism1d

       type(rism1d) :: r1d

     end subroutine calling

     function rism1d_getInvDebyeLen(this) bind(C, name = "rism1d_getInvDebyeLen")
       import :: rism1d
       type(rism1d) :: this
       double precision :: rism1d_getInvDebyeLen
     end function rism1d_getInvDebyeLen

  end interface
end module rism1d_mod
