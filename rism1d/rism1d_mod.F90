module rism1d_mod
  use iso_c_binding
  implicit none 

  type, bind(C) :: rism1d
     !integer(C_int) :: extra_precision, Mdiis_vec, mdiis_method
     !character(kind = C_char), dimension(16) :: savefile
     !character(kind = C_char), dimension(8) :: closureID
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

     function rism1d_getCompressibility(this) bind(C, name = "rism1d_getCompressibility")
       import :: rism1d
       type(rism1d) :: this
       double precision :: rism1d_getCompressibility
     end function rism1d_getCompressibility

     function rism1d_getCompressibility_dT(this) bind(C, name = "rism1d_getCompressibility_dT")
       import :: rism1d
       type(rism1d) :: this
       double precision :: rism1d_getCompressibility_dT
     end function rism1d_getCompressibility_dT

     function rism1d_get3DRISMbackground(this) bind(C, name = "rism1d_get3DRISMbackground")
       import :: rism1d
       type(rism1d) :: this
       double precision :: rism1d_get3DRISMbackground
     end function rism1d_get3DRISMbackground

     function rism1d_getDelHvLimit(this) bind(C, name = "rism1d_getDelHvLimit")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getDelHvLimit
    end function rism1d_getDelHvLimit

    function rism1d_getDelHvLimit_dT(this) bind(C, name = "rism1d_getDelHvLimit_dT")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getDelHvLimit_dT
    end function rism1d_getDelHvLimit_dT
    
    function rism1d_getSusceptibility(this) bind(C, name = "rism1d_getSusceptibility")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getSusceptibility
    end function rism1d_getSusceptibility

    function rism1d_getSusceptibility_dT(this) bind(C, name = "rism1d_getSusceptibility_dT")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getSusceptibility_dT
    end function rism1d_getSusceptibility_dT

    function rism1d_getExNumber(this) bind(C, name = "rism1d_getExNumber")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getExNumber
    end function rism1d_getExNumber

    function rism1d_getStructFactor(this) bind(C, name = "rism1d_getStructFactor")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getStructFactor
    end function rism1d_getStructFactor

    function rism1d_getRunExNumber(this) bind(C, name = "rism1d_getRunExNumber")
      import :: rism1d
      type(rism1d) :: this
      double precision :: rism1d_getRunExNumber
    end function rism1d_getRunExNumber

    function rism1d_getExChem(this, o_form) bind(C, name = "rism1d_getExChem")
      use iso_c_binding
      import :: rism1d
      type(rism1d) :: this
      !integer(C_int), value :: o_form ! passing integer by value
      character(C_char),  dimension(*), intent(in) :: o_form
      double precision :: rism1d_getExChem
    end function rism1d_getExChem

  end interface
end module rism1d_mod
