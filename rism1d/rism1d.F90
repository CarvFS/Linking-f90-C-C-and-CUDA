program rism1d_main
  use iso_c_binding
  use rism1d_mod
  implicit none
  
  type(rism1d) :: r1d
  type(solvMDL) :: mdl
  type(mdiis) :: mdiis_o

  character(256, C_char) :: o_form = "PR"//char(0)

  !real(C_double) :: xvv_o(2,2,2)
  real(C_double) :: xvv_o(5)
  double precision :: residual
  double precision :: tolerance
  logical(C_bool) :: start
  logical(C_bool) :: converged

  integer :: i,j,k
!  do i=1,2
!    do j=1,2
!      do k=1,2
!        xvv_o(i,j,k) = 1.0
!      end do
!    end do
!  end do

  do i=1,5
    xvv_o(i) = i
  end do

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
  write(*,*)

  write(*,*) "rism1d_solve3DRISM_dT", rism1d_solve3DRISM_dT(r1d, -1, 2, 10000, 1d-4)
  write(*,*)

  residual = 1.2
  tolerance = 1d-4
  start = .TRUE.
  converged = .FALSE.
  write(*,*) "print xvv_o array: ", xvv_o
  call rism1d_single3DRISMsolution_dT(r1d,xvv_o,residual,tolerance,start,converged,mdiis_o)


end program rism1d_main
