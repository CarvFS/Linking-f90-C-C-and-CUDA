program rism1d_main
  use iso_c_binding
  use rism1d_mod
  implicit none
  
  type(rism1d) :: r1d
  type(solvMDL) :: mdl ! define target object
  
  character(256, C_char) :: o_form = "PR"//char(0)

!  subroutine c_opaque_alloc(c_obj)
!    use rism1d_mod
!    implicit none
!    type(solvMDL) :: c_obj
!    allocate(c_obj%test)
!  end subroutine c_opaque_alloc
  
  !call calling(r1d)
  
  !write(*,*) "extra_precision = ", r1d%extra_precision
  !write(*,*) "Mdiis_vec = ", r1d%Mdiis_vec, "mdiis_method = ", r1d%mdiis_method
  !write(*,*) "savefile = ", r1d%savefile, " closureID = ", r1d%closureID
  
  write(*,*) "rism1d_getInvDebyeLen", rism1d_getInvDebyeLen(r1d)
  write(*,*)
  write(*,*) "rism1d_getCompressibility", rism1d_getCompressibility(r1d)
  write(*,*)
  write(*,*) "rism1d_getCompressibility_dT", rism1d_getCompressibility_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_get3DRISMbackground", rism1d_get3DRISMbackground(r1d)
  write(*,*)
  write(*,*) "rism1d_getDelHvLimit", rism1d_getDelHvLimit(r1d)
  write(*,*)
  write(*,*) "rism1d_getDelHvLimit_dt", rism1d_getDelHvLimit_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_getSusceptibility", rism1d_getSusceptibility(r1d)
  write(*,*)
  write(*,*) "rism1d_getSusceptibility_dT", rism1d_getSusceptibility_dT(r1d)
  write(*,*)
  write(*,*) "rism1d_getExNumber", rism1d_getExNumber(r1d)
  write(*,*)
  write(*,*) "rism1d_getStructFactor", rism1d_getStructFactor(r1d)
  write(*,*)
  write(*,*) "rism1d_getRunExNumber", rism1d_getRunExNumber(r1d)
  write(*,*)
  write(*,*) "rism1d_getExChem", rism1d_getExChem(r1d, o_form)
  write(*,*)

  call rism1d_addSpecies(r1d, mdl, 123)

end program rism1d_main
